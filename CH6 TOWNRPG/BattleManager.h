#pragma once
#include "GameModel.h"

class BattleManager
{
private:Player& player;
	    Monster& monster;

public:
	void Battle()
	{
		while (player.getHealth() > 0 && monster.getHealth() > 0)
		{
			player.Attack(monster);
			if (monster.getHealth() > 0)
			{
				monster.Attack(player);
			}
		}
		std::cout << "������ ����Ǿ����ϴ�." << std::endl;
	}

};