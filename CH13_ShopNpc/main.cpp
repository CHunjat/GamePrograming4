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

const int total_with = 60;  //전체 
const int field1_width = 30; //이름
const int field2_width = 15; //가격
const int field3_width = 15; //타입


#pragma region 상점코드

class Item
{
public:
	std::string name;
	int price;
	std::string type;
public:
	Item() = default;
	Item(std::string name, int price, std::string type) : name(name), price(price), type(type) {}
};

class Shop
{
private:
	std::map<int, Item> items; // 자료구조 클래스를 보관한다.

public:
	Shop() //데이터를 초기화 한다.
	{
		items.insert({ 0, Item("스태미나포션" , 100, "소비") });  //방법1

		items.insert(std::make_pair(1, Item("마나엘릭서", 150, "소비"))); //방법2

		std::pair<int, Item> p1(2, Item("볼트", 8, "소비"));//방법3
		items.insert(p1);
		items.insert({ 3, Item("석궁" , 115, "무기") });  //방법1
		items.insert({ 4, Item("야구방망이" , 70, "무기") });  //방법1
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
			in_file >> name >> price >> type;				  // 파일에서 name, price, type 읽기 
			items.insert({ index, Item(name, price, type) }); // map 자료구조에 저장
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
			out_file << std::setw(field1_width) << std::left << items[i].name
				<< std::setw(field2_width) << std::right << items[i].price
				<< std::setw(field3_width) << std::right << items[i].type << std::endl;
		}
		

		out_file.close();
	}

	//데이터를 사용하여 기능을 구현한다.
	void ShowItems()
	{
		std::string headersize = "012345678901234567890123456789012345678901234567890123456789";
		//아이템의 머릿말
		//std::cout << headersize << std::endl;

		std::cout << std::setw(field1_width) << std::left << "이름"
			<< std::setw(field2_width) << std::right << "가격"
			<< std::setw(field3_width) << std::right << "타입" << std::endl;

		//라인을 긋는 코드
		std::cout << std::setw(total_with) //길이 설정1
			<< std::setfill('-')           // 공백을 '-' 설정
			<< ""                          // 길이 설정2
			<< std::endl;

		std::cout << std::setfill(' ');

		//아이템을 출력하라
		for (int i = 0; i < items.size(); i++)  //방법1 인덱스 기반 접근이 가능한 자료구조야 한다. vector, map 만 가능
		{
			std::cout << std::setw(field1_width) << std::left << items[i].name
				<< std::setw(field2_width) << std::right << items[i].price
				<< std::setw(field3_width) << std::right << items[i].type
				<< std::endl;
		
		}



		/*for (const auto& elem : items) //방법2
		{

		}*/
	}


	//아이템을 판매하는 기능
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

public:
	NPC() = default;
	NPC(std::string filename, int posX, int posY) :posX(posX), posY(posY)
	{
		shop = Shop(filename);
	}

	void ShowItems()
	{
		shop.ShowItems();
	}

	void ShowNPC()
	{
		ConsoleUtil::GotoXY(posX, posY);
		std::cout << "$";
	}
};

void Interact(int x1, int y1, NPC& npc) // Player, NPC
{
	if (x1 == npc.posX && y1 == npc.posY)
	{
		npc.ShowItems();
	}
}

#pragma endregion

#pragma region Player코드

class Player
{
	//좌표
	//돈

	//Shop 코드와 연동, money ,Shop.tiems[i].price 비교 money -= price;
	//인벤토리 (어떤 컨테이너를 선택하면 좋을까?
};

#pragma endregion

int main()
{
	ConsoleUtil::SetCursorVisible(false);

	int PlayerX = 10;
	int PlayerY = 10;
	

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
				PlayerY--;
				if (PlayerY <= 0) { PlayerY = 0; }
				
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				PlayerY++;
			}
			if (GetAsyncKeyState(VK_LEFT))
			{
				PlayerX--;
				if (PlayerX <= 0) { PlayerX = 0; }
				
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				PlayerX++;

			}
		}

		npc1.ShowNPC();
		npc2.ShowNPC();
		npc3.ShowNPC();

		Interact(PlayerX, PlayerY, npc1);
		Interact(PlayerX, PlayerY, npc2);
		Interact(PlayerX, PlayerY, npc3);

		ConsoleUtil::GotoXY(PlayerX, PlayerY);
		std::cout << "a";

		_getch();
	}
	
	
}