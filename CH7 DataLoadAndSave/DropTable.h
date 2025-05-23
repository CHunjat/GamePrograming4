#pragma once
#include "GameModel.h"
#include "ConsoleUtility.h"
/*
* 
* 1. DropItem �����ڸ� ��������
* 2. Monster�� �����͸� �޾ƿ� �� �ְ� private�� ����
* 3. public ���̺� ������, vector�� DropItem�� �߰��غ�����
* 4. �ڷᱸ���� ����ϴ� �Լ��� ��������
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
		// ���� � ����ġ ���̺��� �����ߴ°�?
		SetDropItem();
	}

	void SetDropItem()
	{
		int index= ConsoleUtil::GetRandomInt(Drop.size() -1); // index�� 0���� �����Ѵ�. size() -1  
 		currentDropItem = Drop[index];
	}

	void drop()
	{
		std::cout << " ȹ�� ����ġ : " << currentDropItem.exp << std::endl;
		std::cout << " ȹ���� �� : " << currentDropItem.money << std::endl;
		

		//Player.GetDropItem(); player�� exp�� ������Ų��, money�� ������Ų��. 
	}

};

