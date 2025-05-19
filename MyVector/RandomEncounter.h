#pragma once
#include "ConsoleUtility.h"
#include <vector>
#include <iostream>


class Monster
{
public:
	std::string name;
	int hp;
	int atk;
public:
	Monster() = default;
	~Monster() = default;

	Monster(std::string name, int hp, int atk)
		:name(name), hp(hp), atk(atk) {}

	void ShowInfo() const
	{
		std::cout << " ���� �̸� : " << name << std::endl;
	}

	void TakeDamage(int dmg)
	{
		hp -= dmg;

		if (hp <= 0)
		{
			std::cout << name << " �� �й��߽��ϴ�." << std::endl;
		}
		else
		{
			std::cout << name << " �� ����ü�� : " << hp << std::endl;
		}
	}

};

class Player
{
private:
	std::vector<Monster> huntedMonster;

	// huntedMonster.push_back();
public:
	void huntMonster(const Monster& monster)
	{
		huntedMonster.push_back(monster);
	}

	void display() const
	{
		std::cout << " ����� ���� ���" << std::endl;
		int i = 1;
		for (const auto& monster : huntedMonster)
		{
			std::cout << i << "��° ����� ���� : " << monster.name << std::endl;
			i++;
		}
	}
};

void Battle(Player& player)
{
	std::vector<Monster> monsters =
	{
		//monsters.emplace_back // ������ ���ÿ� �־��� ���ɻ� ������.
		Monster("Goblin", 30, 5),
		Monster("Dragon", 50, 6),
		Monster("Orc" , 25, 3),
		Monster("Zombie", 51, 2),
		Monster("Vampire", 40, 8),
	};

	int randIndex = ConsoleUtil::GetRandomInt(monsters.size() - 1);

	Monster& selectMonster = monsters[randIndex];
	int playerattackdmg = 10;

	while (selectMonster.hp > 0)
	{
		std::cout << "���Ϳ���" << playerattackdmg << " ��ŭ �����߽��ϴ�." << std::endl;
		selectMonster.TakeDamage(playerattackdmg);
	}

	player.huntMonster(selectMonster);

}