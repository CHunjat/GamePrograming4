#pragma once

#include <iostream>


/*
* virtual ����Ϸ��� �ش� Ŭ������ ����ϴ� �ڽ� Ŭ������ �ʿ�
* Combat - Player , Monster
* override ����� ����Ͽ� CombatŸ���ӿ��� Player�� Combat�� Monster�� Combate ����� �� �ִ�.
* 
* virtual �Լ�() = 0; ���� ���� �Լ�
* �ڽĿ��� �ش� �Լ��� override ���Ѷ�
* 
*/
class Combat // ���� �����Լ� ������
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
		std::cout << "player��" << damage << "�� ���ظ� �Ծ����ϴ�.";
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
		std::cout << "Monster��" << damage << "�� ���ظ� �Ծ����ϴ�.";
	}
	int getHealth() override
	{
		return health;
	}
};