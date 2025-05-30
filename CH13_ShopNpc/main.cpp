/*
*    ��ǥ : 1. �ܼ�â���� �÷��̾ �����δ�.
*           2. Ư�� ��ġ�� ���� NPC�� ������ �� ������ �׸��� �����ش�
*           3. ������ �̿��Ѵ�.
* 
*   Game Object : Player, NPC, SHOP Ŭ����
*   �ڷᱸ��! Item ��� �ڷᱸ����? �����̳ʿ� �����Ͽ� ���?
*   File Input & output �޸��忡 �ִ� �����͸� NPC�� �����ϴ� ���
*/

//Ŭ���� ���� -> �׽�Ʈ -> ����� �ű��


#include <iostream>
#include <map> // ��ƿ��Ƽ�� ���� ���־�
#include <utility> //pair Ŭ���� ����
#include <conio.h>
#include "ConsoleUtility.h"

#include <fstream> //ifstream ofstream
#include <iomanip> // ����� ���� ���
#include <string>

const int total_with = 60;  //��ü 
const int field1_width = 30; //�̸�
const int field2_width = 15; //����
const int field3_width = 15; //Ÿ��


#pragma region �����ڵ�

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
	std::map<int, Item> items; // �ڷᱸ�� Ŭ������ �����Ѵ�.

public:
	Shop() //�����͸� �ʱ�ȭ �Ѵ�.
	{
		items.insert({ 0, Item("���¹̳�����" , 100, "�Һ�") });  //���1

		items.insert(std::make_pair(1, Item("����������", 150, "�Һ�"))); //���2

		std::pair<int, Item> p1(2, Item("��Ʈ", 8, "�Һ�"));//���3
		items.insert(p1);
		items.insert({ 3, Item("����" , 115, "����") });  //���1
		items.insert({ 4, Item("�߱������" , 70, "����") });  //���1
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
		
		
		if (!in_file) //!�� �����Ѵ�! �׷��ϱ� �̰� ���࿡ �������� �����ϸ�~! {} �ڵ带 �����϶�
		{
			std::cerr << "������ ���µ� �����߽��ϴ�" << std::endl;
			std::exit(1);
		}

		int index = 0;

		while (!in_file.eof()) //end of file ������ ���� ���������� true�� ��ȯ�ϴ� �Լ�, ��, ���޾������� �����Ҵ���� �ݺ��ϴ� while��
		{
			in_file >> name >> price >> type;				  // ���Ͽ��� name, price, type �б� 
			items.insert({ index, Item(name, price, type) }); // map �ڷᱸ���� ����
			index++;										  // ���� index �Ѿ��
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

		if (!out_file) //!�� �����Ѵ�! �׷��ϱ� �̰� ���࿡ �������� �����ϸ�~! {} �ڵ带 �����϶�
		{
			std::cerr << "������ ���µ� �����߽��ϴ�" << std::endl;
			std::exit(1);
		}

		for (int i = 0; i < items.size(); i++)  //�����͸� �����϶� ����϶� ���ݹٲ㼭 
		{
			out_file << std::setw(field1_width) << std::left << items[i].name
				<< std::setw(field2_width) << std::right << items[i].price
				<< std::setw(field3_width) << std::right << items[i].type << std::endl;
		}
		

		out_file.close();
	}

	//�����͸� ����Ͽ� ����� �����Ѵ�.
	void ShowItems()
	{
		std::string headersize = "012345678901234567890123456789012345678901234567890123456789";
		//�������� �Ӹ���
		//std::cout << headersize << std::endl;

		std::cout << std::setw(field1_width) << std::left << "�̸�"
			<< std::setw(field2_width) << std::right << "����"
			<< std::setw(field3_width) << std::right << "Ÿ��" << std::endl;

		//������ �ߴ� �ڵ�
		std::cout << std::setw(total_with) //���� ����1
			<< std::setfill('-')           // ������ '-' ����
			<< ""                          // ���� ����2
			<< std::endl;

		std::cout << std::setfill(' ');

		//�������� ����϶�
		for (int i = 0; i < items.size(); i++)  //���1 �ε��� ��� ������ ������ �ڷᱸ���� �Ѵ�. vector, map �� ����
		{
			std::cout << std::setw(field1_width) << std::left << items[i].name
				<< std::setw(field2_width) << std::right << items[i].price
				<< std::setw(field3_width) << std::right << items[i].type
				<< std::endl;
		
		}



		/*for (const auto& elem : items) //���2
		{

		}*/
	}


	//�������� �Ǹ��ϴ� ���
};

#pragma endregion 

#pragma region NPC �ڵ�
//������ �����ϴ� ��ġ�� �÷��̾ �������� �� �� �������� �����ּ���

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

#pragma region Player�ڵ�

class Player
{
	//��ǥ
	//��

	//Shop �ڵ�� ����, money ,Shop.tiems[i].price �� money -= price;
	//�κ��丮 (� �����̳ʸ� �����ϸ� ������?
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
		//�Է��� �޾����� ��ǥ�� ���ϴ� �ڵ�
		if (_kbhit())
		{
			system("cls");
			if (GetAsyncKeyState(VK_UP))
			{
				//���� �÷��̾��� ���� 0 -1 -> 0
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