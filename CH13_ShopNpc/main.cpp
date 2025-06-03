/*
*    목표 : 1. 콘솔창에서 플레이어를 움직인다.
*           2. 특정 위치에 상점 NPC와 조우할 떄 상점의 항목을 보여준다
*           3. 상점을 이용한다.
* 
*   Game Object : Player, NPC, SHOP 클래스
*   자료구조! Item 어떠한 자료구조로? 컨테이너에 보관하여 사용?
*   File Input & output 메모장에 있는 데이터를 NPC에 전달하는 기능
*/

//클래스 구현 -> 테스트 -> 헤더로 옮기기


#include <iostream>
#include <map> // 유틸리티와 같이 자주씀
#include <utility> //pair 클래스 정의
#include <conio.h>
#include "ConsoleUtility.h"

#include <fstream> //ifstream ofstream
#include <iomanip> // 입출력 조작 헤더
#include <string>
#include <unordered_map> // 플레이어의 인벤토리를 위한 자료구조

const int total_with = 60;  //전체 
const int field1_width = 30; //이름
const int field2_width = 15; //가격
const int field3_width = 15; //타입

class Item
{
public:
	std::string name;
	int price;
	std::string type;
public:
	Item() = default;
	Item(std::string name, int price, std::string type) : name(name), price(price), type(type) {}

	virtual void Use() = 0; //순수가상함수 : Item을 상속하는 클래스가 이 함수를 반드시 구현을 하세요!
};


class Weapon : public Item
{
public:
	Weapon(std::string name, int price, std::string type) : Item(name, price, type) {}

	void Use() override
	{
		std::cout << "무기를 사용합니다" << std::endl;
	}
};

class UsableItem : public Item
{
public:
	UsableItem(std::string name, int price, std::string type) : Item(name, price, type) {}

	void Use() override
	{
		std::cout << "소비성 아이템을 사용합니다." << std::endl;
	}
};




/// <summary>
/// UsableItem 아이템을 use했을때 사라지는 종류의 아이템입니다.
/// Player 클래스의 RemoveItem을 사용하세요
/// </summary>



#pragma region Player 코드
class Player
{
private:
	// Item items[100]; 다음 코드의 문제점?
	std::unordered_map<std::string, Item*> inventory; // Item을 아이템의 이름으로 찾는 컨테이너

public:
	int posX, posY, Money;

#pragma region 인벤토리 코드
	// 플레이어가 소유가 인벤토리를 자료구조를 한가지 선택해서. 그 자료구조에 구매한 아이템을 저장해보세요.
	// 저장한 자료구조를 사용하는 함수를 만들면 됩니다.
	


	/*
	* 상점은 전부다 아이템을 팔아야 한다. (공통된 클래스 -> Item)
	* 해당 아이템 같은 함수 Use() 갖고 있지만 다른 기능으로 사용하고 싶다. (클래스의 다형성)
	* Item을 주소로 받아오면 다형성을 사용할 수있다.
	*/

	// 특정 키를 눌렀을 때 (게임 입력 Player Input)

	// PushOne 함수 포인터 PushOne();

	void Use(Item* item)
	{
		//소비 아이템 -> 적용...
		//장비 아이템 -> 장비 장착...
		item->Use();
	}
	void AddItem(Item* item)
	{
		inventory.insert({ item->name, item });
	}

	void RemoveItem(std::string name)
	{
		//제거할 수 없는 경우에는?
		if (inventory.find(name) != inventory.end()) //컨테이너 데이터가 존재할 떄만 실행하세요
		{
			inventory.erase(name);
		}
		else
		{
			std::cout << "인벤토리에 해당하는 아이템이 없습니다" << std::endl;
		}
	

	}
	void RemoveItem(Item* item)
	{
		inventory.erase(item->name);
	}


#pragma endregion

	
	Player() = default;
	Player(int posX, int posY, int Money) : posX(posX), posY(posY), Money(Money) {}

	//좌상단의 플레이어 UI 띄우기.

	void ShowPlayerUI()
	{
		ConsoleUtil::GotoXY(65, 1);
		std::cout << "플레이어의 정보" << std::endl;
		ConsoleUtil::GotoXY(65, 2);
		std::cout << "플레이어의 소지금 : " << Money;
		ConsoleUtil::GotoXY(65, 3);
		std::cout << "보유한 아이템 : ";
		ConsoleUtil::GotoXY(65, 4);
		for (const auto& item : inventory)
		{
			std::cout << item.first << " 의 가격 : " << item.second->price << "||"; 
		}
	}

	void BuyItem(Item* item)
	{
		Money -= item->price; //돈지불
		AddItem(item);
	}
};
#pragma endregion 


#pragma region 상점코드

class Shop
{
private:
	std::map<int, Item*> items; // 자료구조 클래스를 보관한다.
	/*
	* Item 추상 클래스 만들면, item 자체를 클래스로 생성할 수 없다.(인스턴스)
	* 주소로 받아와야 하는데 enum 타입에 따라 클래스를 다르게 사용하게끔 코드를 작성해야한다.
	* "팩토리 패턴" -팩토리 클래스로 만들어서 생성자를 다르게 구현할 수 있다.
	*/

public:
	Shop() //데이터를 초기화 한다.
	{
		items.insert({ 0,new UsableItem("스태미나포션" , 100, "소비") });  //방법1
		items.insert(std::make_pair(1, new UsableItem("마나엘릭서", 150, "소비"))); //방법2
		std::pair<int, Item*> p1(2, new UsableItem("볼트", 8, "소비"));//방법3
		items.insert(p1);
		items.insert({ 3, new Weapon("석궁" , 115, "무기") });  //방법1
		items.insert({ 4, new Weapon("야구방망이" , 70, "무기") });  //방법1
	}

	Shop(std::string filename)
	{
		LoadShopData(filename);
	}


	void LoadShopData(std::string filename)
	{
		std::ifstream in_file;
		in_file.open(filename);

		std::string name;
		int price;
		std::string type;
		
		
		if (!in_file) //!는 존재한다! 그러니까 이건 만약에 인파일이 존재하면~! {} 코드를 실행하라
		{
			std::cerr << "파일을 여는데 실패했습니다" << std::endl;
			std::exit(1);
		}

		int index = 0;

		while (!in_file.eof()) //end of file 파일의 끝이 도달했을때 true를 반환하는 함수, 즉, 도달안했으면 도달할대까지 반복하는 while문
		{
			in_file >> name >> price >> type;	
			
			if (type == "무기")
			{
				items.insert({ index, new Weapon(name, price, type) }); // map 자료구조에 저장
			
			}
			else
			{
				items.insert({ index, new UsableItem(name, price, type) }); // map 자료구조에 저장
				
			}
			index++;										  // 다음 index 넘어가기
		}
		in_file.close();
	}

	void SaveShopData(std::string Filename)
	{

		std::ofstream out_file;
		out_file.open(Filename);

		std::string name;
		int price;
		std::string type;

		if (!out_file) //!는 존재한다! 그러니까 이건 만약에 인파일이 존재하면~! {} 코드를 실행하라
		{
			std::cerr << "파일을 여는데 실패했습니다" << std::endl;
			std::exit(1);
		}

		for (int i = 0; i < items.size(); i++)  //데이터를 저장하라 출력하라를 조금바꿔서 
		{
			out_file << std::setw(field1_width) << std::left << items[i]->name
				<< std::setw(field2_width) << std::right << items[i]->price
				<< std::setw(field3_width) << std::right << items[i]->type << std::endl;
		}
		out_file.close();
	}

	//데이터를 사용하여 기능을 구현한다.
	void ShowItems(int x, int y)
	{
		std::string headersize = "012345678901234567890123456789012345678901234567890123456789";
		//아이템의 머릿말
		//std::cout << headersize << std::endl;

		ConsoleUtil::GotoXY(x, y);
		std::cout << std::setw(field1_width) << std::left << "이름"
			<< std::setw(field2_width) << std::right << "가격"
			<< std::setw(field3_width) << std::right << "타입" << std::endl;

		ConsoleUtil::GotoXY(x, y+1);
		//라인을 긋는 코드
		std::cout << std::setw(total_with) //길이 설정1
			<< std::setfill('-')           // 공백을 '-' 설정
			<< ""                          // 길이 설정2
			<< std::endl;

		std::cout << std::setfill(' ');

		//아이템을 출력하라
		for (int i = 0; i < items.size(); i++)  //방법1 인덱스 기반 접근이 가능한 자료구조야 한다. vector, map 만 가능
		{
			ConsoleUtil::GotoXY(x, y + 2 + i);

			std::cout << std::setw(field1_width) << std::left << items[i]->name
				<< std::setw(field2_width) << std::right << items[i]->price
				<< std::setw(field3_width) << std::right << items[i]->type
				<< std::endl;
		
		}



		/*for (const auto& elem : items) //방법2
		{

		}*/
	}


	//아이템을 판매하는 기능 (플레이어가 돈이 없으면...?)

	bool BuyItem(int index, Player& player)
	{
		if (items.find(index) != items.end()) //아이템을 찾았다!
		{
			Item* itemInstance = items[index];
			if (player.Money >= itemInstance->price) // 플레이어가 소지금이 충분할때
			{
				player.BuyItem(itemInstance);
				return true;
			}
			else
			{
				std::cout << " 소지금이 부족합니다. " << std::endl;
			}
		}
		else
		{
			std::cout << "아이템을 찾지 못했습니다." << std::endl;
		}
	}

	void Interact(Player& player)
	{
		int select;
		std::cout << "번호를 입력하여 아이템을 구매할 수 있습니다" << std::endl;
		std::cin >> select;
		BuyItem(select, player);
	}

};

#pragma endregion 

#pragma region NPC 코드
//상인이 존재하는 위치에 플레이어가 도달했을 때 이 아이템을 보여주세요

class NPC
{
private:
	Shop shop;
	
public:
	int posX;
	int posY;
	bool isActivate;

public:
	NPC() = default;
	NPC(std::string filename, int posX, int posY) :posX(posX), posY(posY), isActivate(true)
	{
		shop = Shop(filename);
	}

	void ShowItems(int x, int y)
	{
		shop.ShowItems(x,y);
		
	}

	void Interact(Player& player)
	{
		shop.Interact(player);
		isActivate = false;
	}

	void ShowNPC()
	{
		if (isActivate == false) return;
		ConsoleUtil::GotoXY(posX, posY);
		std::cout << "$";
	}
};

void Interact(Player& player, NPC& npc, int UI_X, int UI_Y) // Player, NPC
{
	if (player.posX == npc.posX && player.posY == npc.posY)
	{
		if (npc.isActivate == false) { return; } // if(!npc.isActivate) 와 같다. 상점이 비활성화 되면 사용불가능.
		npc.ShowItems(UI_X, UI_Y);
		npc.Interact(player);
	}
}

#pragma endregion

#pragma region Player코드



#pragma endregion

int main()
{
	ConsoleUtil::SetCursorVisible(false);

	Player player(10, 10, 800); // 플레이어의 시작설정

	//int PlayerX = 10;
	//int PlayerY = 10;
	

	NPC npc1("shop1.txt", 3,5);
	NPC npc2("shop2.txt", 10,8);
	NPC npc3("shop3.txt", 8,6);

	//shop.SaveShopData("shop1.txt");
	//shop.SaveShopData("shop2.txt");
	//shop.SaveShopData("shop3.txt");

	while (true)
	{
		//입력을 받았을때 좌표가 변하는 코드
		if (_kbhit())
		{
			system("cls");
			if (GetAsyncKeyState(VK_UP))
			{
				//현재 플레이어의 값이 0 -1 -> 0
				player.posY--;
				if (player.posY <= 0) { player.posY = 0; }
				
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				player.posY++;
			}
			if (GetAsyncKeyState(VK_LEFT))
			{
				player.posX--;
				if (player.posX <= 0) { player.posX = 0; }
				
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				player.posX++;

			}
		}

		player.ShowPlayerUI();

		npc1.ShowNPC();
		npc2.ShowNPC();
		npc3.ShowNPC();

		Interact(player, npc1, 0,10);
		Interact(player, npc2, 0,10);
		Interact(player, npc3, 0,10);

		ConsoleUtil::GotoXY(player.posX, player.posY);
		std::cout << "a";

		_getch();
	}
	
	
}