#pragma once
#include "GameModel.h"
#include "ConsoleUtility.h"
/*
* 
* 1. DropItem 생성자를 만들어보세요
* 2. Monster가 데이터를 받아올 수 있게 private를 선언
* 3. public 레이블에 생성자, vector의 DropItem을 추가해보세요
* 4. 자료구조를 사용하는 함수를 만들어보세요
*/
struct DropItem
{
	int index;
	int exp;
	int money;
	DropItem() = default;
	DropItem(int index, int exp, int money) :index(index), exp(exp), money(money) {}


};

class Monster
{
private:
	int exp;
	int money;
	//2
	std::vector<DropItem> Drop;
	DropItem currentDropItem;
public:
	Monster(int exp, int money) : exp(exp), money(money) 
	{
		Drop.emplace_back(1, 10, 100);
		Drop.emplace_back(2, 20, 200);
		Drop.emplace_back(3, 30, 300);
		Drop.emplace_back(4, 40, 400);
		Drop.emplace_back(5, 50, 500);
		// 내가 어떤 경험치 테이블을 선택했는가?
		SetDropItem();
	}

	void SetDropItem()
	{
		int index= ConsoleUtil::GetRandomInt(Drop.size() -1); // index는 0부터 시작한다. size() -1  
 		currentDropItem = Drop[index];
	}

	void drop()
	{
		std::cout << " 획득 경험치 : " << currentDropItem.exp << std::endl;
		std::cout << " 획득한 돈 : " << currentDropItem.money << std::endl;
		

		//Player.GetDropItem(); player의 exp를 증가시킨다, money를 증가시킨다. 
	}

};

