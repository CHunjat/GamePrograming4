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
#include <unordered_map> // �÷��̾��� �κ��丮�� ���� �ڷᱸ��

const int total_with = 60;  //��ü 
const int field1_width = 30; //�̸�
const int field2_width = 15; //����
const int field3_width = 15; //Ÿ��

class Item
{
public:
	std::string name;
	int price;
	std::string type;
public:
	Item() = default;
	Item(std::string name, int price, std::string type) : name(name), price(price), type(type) {}

	virtual void Use() = 0; //���������Լ� : Item�� ����ϴ� Ŭ������ �� �Լ��� �ݵ�� ������ �ϼ���!
};


class Weapon : public Item
{
public:
	Weapon(std::string name, int price, std::string type) : Item(name, price, type) {}

	void Use() override
	{
		std::cout << "���⸦ ����մϴ�" << std::endl;
	}
};

class UsableItem : public Item
{
public:
	UsableItem(std::string name, int price, std::string type) : Item(name, price, type) {}

	void Use() override
	{
		std::cout << "�Һ� �������� ����մϴ�." << std::endl;
	}
};




/// <summary>
/// UsableItem �������� use������ ������� ������ �������Դϴ�.
/// Player Ŭ������ RemoveItem�� ����ϼ���
/// </summary>



#pragma region Player �ڵ�
class Player
{
private:
	// Item items[100]; ���� �ڵ��� ������?
	std::unordered_map<std::string, Item*> inventory; // Item�� �������� �̸����� ã�� �����̳�

public:
	int posX, posY, Money;

#pragma region �κ��丮 �ڵ�
	// �÷��̾ ������ �κ��丮�� �ڷᱸ���� �Ѱ��� �����ؼ�. �� �ڷᱸ���� ������ �������� �����غ�����.
	// ������ �ڷᱸ���� ����ϴ� �Լ��� ����� �˴ϴ�.
	


	/*
	* ������ ���δ� �������� �Ⱦƾ� �Ѵ�. (����� Ŭ���� -> Item)
	* �ش� ������ ���� �Լ� Use() ���� ������ �ٸ� ������� ����ϰ� �ʹ�. (Ŭ������ ������)
	* Item�� �ּҷ� �޾ƿ��� �������� ����� ���ִ�.
	*/

	// Ư�� Ű�� ������ �� (���� �Է� Player Input)

	// PushOne �Լ� ������ PushOne();

	void Use(Item* item)
	{
		//�Һ� ������ -> ����...
		//��� ������ -> ��� ����...
		item->Use();
	}
	void AddItem(Item* item)
	{
		inventory.insert({ item->name, item });
	}

	void RemoveItem(std::string name)
	{
		//������ �� ���� ��쿡��?
		if (inventory.find(name) != inventory.end()) //�����̳� �����Ͱ� ������ ���� �����ϼ���
		{
			inventory.erase(name);
		}
		else
		{
			std::cout << "�κ��丮�� �ش��ϴ� �������� �����ϴ�" << std::endl;
		}
	

	}
	void RemoveItem(Item* item)
	{
		inventory.erase(item->name);
	}


#pragma endregion

	
	Player() = default;
	Player(int posX, int posY, int Money) : posX(posX), posY(posY), Money(Money) {}

	//�»���� �÷��̾� UI ����.

	void ShowPlayerUI()
	{
		ConsoleUtil::GotoXY(65, 1);
		std::cout << "�÷��̾��� ����" << std::endl;
		ConsoleUtil::GotoXY(65, 2);
		std::cout << "�÷��̾��� ������ : " << Money;
		ConsoleUtil::GotoXY(65, 3);
		std::cout << "������ ������ : ";
		ConsoleUtil::GotoXY(65, 4);
		for (const auto& item : inventory)
		{
			std::cout << item.first << " �� ���� : " << item.second->price << "||"; 
		}
	}

	void BuyItem(Item* item)
	{
		Money -= item->price; //������
		AddItem(item);
	}
};
#pragma endregion 


#pragma region �����ڵ�

class Shop
{
private:
	std::map<int, Item*> items; // �ڷᱸ�� Ŭ������ �����Ѵ�.
	/*
	* Item �߻� Ŭ���� �����, item ��ü�� Ŭ������ ������ �� ����.(�ν��Ͻ�)
	* �ּҷ� �޾ƿ;� �ϴµ� enum Ÿ�Կ� ���� Ŭ������ �ٸ��� ����ϰԲ� �ڵ带 �ۼ��ؾ��Ѵ�.
	* "���丮 ����" -���丮 Ŭ������ ���� �����ڸ� �ٸ��� ������ �� �ִ�.
	*/

public:
	Shop() //�����͸� �ʱ�ȭ �Ѵ�.
	{
		items.insert({ 0,new UsableItem("���¹̳�����" , 100, "�Һ�") });  //���1
		items.insert(std::make_pair(1, new UsableItem("����������", 150, "�Һ�"))); //���2
		std::pair<int, Item*> p1(2, new UsableItem("��Ʈ", 8, "�Һ�"));//���3
		items.insert(p1);
		items.insert({ 3, new Weapon("����" , 115, "����") });  //���1
		items.insert({ 4, new Weapon("�߱������" , 70, "����") });  //���1
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
			in_file >> name >> price >> type;	
			
			if (type == "����")
			{
				items.insert({ index, new Weapon(name, price, type) }); // map �ڷᱸ���� ����
			
			}
			else
			{
				items.insert({ index, new UsableItem(name, price, type) }); // map �ڷᱸ���� ����
				
			}
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
			out_file << std::setw(field1_width) << std::left << items[i]->name
				<< std::setw(field2_width) << std::right << items[i]->price
				<< std::setw(field3_width) << std::right << items[i]->type << std::endl;
		}
		out_file.close();
	}

	//�����͸� ����Ͽ� ����� �����Ѵ�.
	void ShowItems(int x, int y)
	{
		std::string headersize = "012345678901234567890123456789012345678901234567890123456789";
		//�������� �Ӹ���
		//std::cout << headersize << std::endl;

		ConsoleUtil::GotoXY(x, y);
		std::cout << std::setw(field1_width) << std::left << "�̸�"
			<< std::setw(field2_width) << std::right << "����"
			<< std::setw(field3_width) << std::right << "Ÿ��" << std::endl;

		ConsoleUtil::GotoXY(x, y+1);
		//������ �ߴ� �ڵ�
		std::cout << std::setw(total_with) //���� ����1
			<< std::setfill('-')           // ������ '-' ����
			<< ""                          // ���� ����2
			<< std::endl;

		std::cout << std::setfill(' ');

		//�������� ����϶�
		for (int i = 0; i < items.size(); i++)  //���1 �ε��� ��� ������ ������ �ڷᱸ���� �Ѵ�. vector, map �� ����
		{
			ConsoleUtil::GotoXY(x, y + 2 + i);

			std::cout << std::setw(field1_width) << std::left << items[i]->name
				<< std::setw(field2_width) << std::right << items[i]->price
				<< std::setw(field3_width) << std::right << items[i]->type
				<< std::endl;
		
		}



		/*for (const auto& elem : items) //���2
		{

		}*/
	}


	//�������� �Ǹ��ϴ� ��� (�÷��̾ ���� ������...?)

	bool BuyItem(int index, Player& player)
	{
		if (items.find(index) != items.end()) //�������� ã�Ҵ�!
		{
			Item* itemInstance = items[index];
			if (player.Money >= itemInstance->price) // �÷��̾ �������� ����Ҷ�
			{
				player.BuyItem(itemInstance);
				return true;
			}
			else
			{
				std::cout << " �������� �����մϴ�. " << std::endl;
			}
		}
		else
		{
			std::cout << "�������� ã�� ���߽��ϴ�." << std::endl;
		}
	}

	void Interact(Player& player)
	{
		int select;
		std::cout << "��ȣ�� �Է��Ͽ� �������� ������ �� �ֽ��ϴ�" << std::endl;
		std::cin >> select;
		BuyItem(select, player);
	}

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
		if (npc.isActivate == false) { return; } // if(!npc.isActivate) �� ����. ������ ��Ȱ��ȭ �Ǹ� ���Ұ���.
		npc.ShowItems(UI_X, UI_Y);
		npc.Interact(player);
	}
}

#pragma endregion

#pragma region Player�ڵ�



#pragma endregion

int main()
{
	ConsoleUtil::SetCursorVisible(false);

	Player player(10, 10, 800); // �÷��̾��� ���ۼ���

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
		//�Է��� �޾����� ��ǥ�� ���ϴ� �ڵ�
		if (_kbhit())
		{
			system("cls");
			if (GetAsyncKeyState(VK_UP))
			{
				//���� �÷��̾��� ���� 0 -1 -> 0
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