#pragma once

#include <iostream>


/*
* virtual 사용하려면 해당 클래스를 상속하는 자식 클래스가 필요
* Combat - Player , Monster
* override 기능을 사용하여 Combat타입임에도 Player의 Combat과 Monster의 Combate 사용할 수 있다.
* 
* virtual 함수() = 0; 순수 가상 함수
* 자식에서 해당 함수를 override 시켜라
* 
*/
class Combat // 순수 가상함수 만들어봐
{
public:
	virtual ~Combat() = default;

	virtual void Attack(Combat& target) = 0;
	virtual void TakeDamage(int damage) = 0;
	virtual int getHealth() = 0; 
};

class Player : public Combat
{
private:
	int health;
	int ATK;

public:
	Player(int health, int ATK) : health(health), ATK(ATK) {}

	void Attack(Combat& target) override
	{
		target.TakeDamage(ATK);
	}

	void TakeDamage(int damage) override
	{
		health -= damage;
		std::cout << "player가" << damage << "의 피해를 입었습니다.";
	}
	int getHealth() override 
	{
		return health;
	}
};

class Monster : public Combat
{
private:
	int health;
	int ATK;

public:
	Monster(int health, int ATK) : health(health), ATK(ATK) {}
	void Attack(Combat& target) override
	{
		target.TakeDamage(ATK);
	}

	void TakeDamage(int damage) override
	{
		health -= damage;
		std::cout << "Monster가" << damage << "의 피해를 입었습니다.";
	}
	int getHealth() override
	{
		return health;
	}
};