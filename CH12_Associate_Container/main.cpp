
//���� �����̳� : (multi, unordered) set, map

#include <set>
#include <map>
#include <algorithm>

#include <iostream>
#include <iomanip>
#include <utility>
// set�� ������� �� �������� �߻��ϴ°�?
#pragma region ���� �����̳� ����ϱ�

void Test1()
{
	std::set<int> nums;

	// �����͸� ��� ������ �� �ֳ���? push
	// ���� �����̳� insert
	// ���� �����̳��� �����͸� �Է��ϸ� �ڵ����� ������ �ȴ�.
	// Ž���� �� �� ���ĵ� ����� ����ϸ� ȿ�����̴�.
	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7); // {1,5,2,7} ������ ���� ������� �񱳸� �ؼ� ������.

	std::cout << "Ư¡1 .set�� �����Ͱ� �ڵ����� ���ĵ� " << std::endl;

	for (const auto& num : nums)
	{
		std::cout << num << " " ;
	}
	std::cout << std::endl;
	// set�� Ư¡. �ߺ��� �ȵ� 
	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7); // {1,5,2,7} ������ ���� ������� �񱳸� �ؼ� ������.
	std::cout << "Ư¡2 .set�� �����Ͱ� �ߺ��� �ȵȴ�. " << std::endl;
	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	std::cout << " ���� �����̳� �տ� Ư�� Ű���带 ���̸� ������ ���Ѵ�. " << std::endl;
}

void Test2()
{
	std::cout << " Ư¡2. multiset�� �����ʹ� �ߺ��� �ȴ�. " << std::endl;

	std::multiset<int> nums;

	nums.insert(1);
	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(2);
	nums.insert(7); // {1,5,2,7} ������ ���� ������� �񱳸� �ؼ� ������.

	std::cout << "Ư¡1 .set�� �����Ͱ� �ڵ����� ���ĵ� " << std::endl;

	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
	// set�� Ư¡. �ߺ��� �ȵ� 
	nums.insert(1);
	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(2);
	nums.insert(7); // {1,5,2,7} ������ ���� ������� �񱳸� �ؼ� ������.
	std::cout << "Ư¡2 .set�� �����Ͱ� �ߺ��� �ȵȴ�. " << std::endl;
	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	std::cout << " ���� �����̳� �տ� Ư�� Ű���带 ���̸� ������ ���Ѵ�. " << std::endl;
}

#pragma endregion 

#pragma region Ŀ���� Ŭ������ set�� �ִ� ���

struct Item
{
	int id;
	std::string name;
	Item() = default;
	Item(int id, std::string name) : id(id), name(name) {}

	bool operator < (const Item& other) const // Ŭ������ ���̿��� �񱳿����ڸ� �������Ѵ�.
	{
		return id < other.id;
	}

	
};

void Test3()
{
	std::cout << "Ŀ���� ��ü�� Set���� ����ϱ�" << std::endl;
	std::set<Item> items;

	Item item1(1, "����");
	Item item2(2, "��");
	Item item3(3, "�ٳ���");
	Item item4(100, "Į");
	Item item5(50, "����");

	items.insert(item1);
	items.insert(item2);
	items.insert(item3);
	items.insert(item4);
	items.insert(item5);

	std::cout << "�ߺ��� ��� ����" << std::endl;
	items.insert(Item(3, "����"));

	for (const auto& item : items)
	{
		std::cout << item.id << " " << item.name << std::endl;
	}

	std::cout << "Set�� ����ϸ� �������� ũ�⿡ ���� �ڵ����� ������ ����� ���� �� �ֽ��ϴ�" <<std:: endl;
	std::cout << "find�Լ��� ����ؼ� ������ �����͸� ã�� �� �ִ�." <<std:: endl;
	
	// item ��ü�� items �ȿ��� ã�ƾ� �Ѵ�. 
	// item�� id �� n���� �����͸� ã��;��
	// map�� ����ϸ� ���� �������� ���� �ذ� �� �� �ִ�.
}



#pragma endregion

#pragma region map ����ϱ�

void Test4()
{
	std::cout << "map �ڷᱸ�� ����ϱ�" << std::endl;
	std::map<int, Item> items;

	//map�� �����͸� �ִ� �������� ��� 1. pair Ŭ������ �����ϴ� ��� {Ÿ��,Ÿ��} �߰�ȣ ���.
	items.insert({ 0,Item(100, "����") });

	// 2. make_pair �Լ� ����ϱ�
	items.insert(std::make_pair(10, Item(1000, "�ռҵ�")));

	// (3) pairŬ������ ���� �����ϱ� (����� �ʿ� utility)
	std::pair<int, Item> p1(5, Item(101, "���� ����"));

	items.insert(p1);

	std::cout << "Ư¡ 1  map�� pair�� �̷���� �����͸� �����ϴ� �����̳ʴ�" << std::endl;
	std::cout << "Ư¡ 2  map�� KEY������ �ڵ� ������ �̷������." << std::endl;

	for (const auto& item : items)
	{
		std::cout << item.first << " " << "ID : " << item.second.id << "�̸� : " << item.second.name << std::endl;
	}
	std::cout << "Ư¡3 ���� �� �ڷᱸ���Դϴ� <<std ::endl";
	std::cout << items[0].id << items[0].name << std::endl;

}   

#pragma endregion



#pragma region ���� �����̳ʸ� �ǽ��Ѵ�

struct NewItem
{
	std::string name;
	int ATK;
	int price;

	NewItem() = default;
	NewItem(std::string name, int ATK, int price) : name(name), ATK(ATK), price(price) {}
};

void Test5()
{
	std::map<std::string, int > map1;
	map1.insert({ "��", 0 });
	map1.insert({ "��", 1 });
	map1.insert(std::make_pair("��", 2));
	map1.insert(std::pair<std::string, int>("��", 3));


	for (const auto& e : map1)
	{
		std::cout << " [";
		std::cout << e.first << " " << e.second << " ";
		std::cout << "]" << " ";
	}

	std::cout << "�� Ű���忡�� ��� ���ڰ� ����ֳ���" << map1["��"] << std::endl;
	std::map<int, int>map2;
	//�÷��̾��� id��ȣ(����) , �ش� �÷��̾��� ����
	//id��ȣ�� ???�� ������ ������ ���ΰ���?
	//���� ->user Ÿ������ �����ϸ� user�� ��� ������ id��ȣ�� ã�� �� �ִ�.
	map2.insert({ 0,10 });
	map2.insert({ 5,100 });
	map2.insert({ 100,999 });
	map2.insert({ 50,50 });
	map2.insert({ 25,100 });

	std::cout << "map2 �����̳� �ȿ� ������ Ű���忡�� ��� ���ڰ� ����ֽ��ϱ�? " << map2[100] << std::endl;

	std::map<std::string, NewItem> map3;
	map3.insert({ "�ռҵ�", NewItem("�ռҵ�", 50, 100)});
	map3.insert({ "���Ǿ�", NewItem("���Ǿ�", 30, 75) });
	// std::cout <<"map3�� ����ؼ� Ư�� �̸����� �������� ã�� ���" <<map3["�ռҵ�"] <<std::endl;

	std::cout << "���࿡ map3�ȿ� ����ִ� �̸��� �ռҵ��� �����͸� �ҷ�����" << std::endl;
	NewItem itemInstance = map3["�ռҵ�"];
	std::cout << "�̸� :" << itemInstance.name <<
		"���ݷ� :" << itemInstance.ATK <<
		"���� :" << itemInstance.price << std::endl;
	//void ButItem(NewItem item) item ����, player �� ���ؼ� �����Ѵ�.

}

#pragma endlreigon


#pragma region ���� UI �� ��� ����

// iomanip ����� ���ڿ��� �԰��� ����� �ִ� ���, setw left
class Player
{
	int money;
public:
	Player(int money) : money(money) {}

	//������ �������� ȹ���ߴ�.
	void BuyItem(NewItem item)
	{

	}
};
//������ ���� �������� �Ȱ� �ʹ�.
//�������� �����̳� ���·� ������ �ؾ��Ѵ�.
//map ����ؼ� �����̳� ������ �ϰڴ�.

class Shop
{   //1�ܰ�
	//Ÿ��<int   ,Newitem>  items �����̳ʸ� �����ϱ�
	std::map<int, NewItem> items; 

	
	//2�ܰ�
public:
	Shop()
	{   // 2�ܰ�
		// 5���� �ְ� ���� ���� �����͸� ���� �־��ּ���
		items.insert({0, NewItem("ö��", 5, 100)});
		items.insert({1, NewItem("����", 3, 100)});
		items.insert({2, NewItem("â", 6, 900)});
		items.insert({3, NewItem("Į", 7, 950)});
		items.insert({4, NewItem("Ȱ", 9, 1000)});
		// {0, NewItem("�̸�" , ���ݷ�, ����)});
	}

	void ShowItem()
	{
		std::cout << std::left;
		std::cout << std::setw(10) << "�ε���" << std::setw(10) << "�̸�" << std::setw(10) << "���ݷ�" << std::setw(10)
			<< "����" << std::setw(10) << std::endl;

		for (const auto& item : items)
		{
			std::cout << std::left; //�������� ���� 
			std::cout << std::setw(10) << item.first << std::setw(10) << item.second.name <<
				std::setw(10) << item.second.ATK <<
				std::setw(10) << item.second.price << std::endl;
		}
		
	}
	void SellItem()
	{

	}


};

void ShopTest()
{
	//1. Item �����͸� �����.
	//2. ������ �����͸� ����� Ŭ������ ������
	//3. ShopŬ���� �ȿ� map �ڷᱸ���� �߰��غ�����
	//4. items �����͸� �ʱ�ȭ ���ּ���

	std::cout << std::endl;
	std::cout << "���� ��� �׽�Ʈ" << std::endl;
	Shop shop1;
	shop1.ShowItem();
}

#pragma endregion
// set���� �����͸� ���� ���� ���� ������ ��, �װ��� ������ map
// pair�� ���Ǹ� �ؾ��Ѵ�.







int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
}