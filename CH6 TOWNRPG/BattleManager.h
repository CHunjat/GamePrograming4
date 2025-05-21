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
		std::cout << "전투가 종료되었습니다." << std::endl;
	}

};