#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>

// ã���� iterator ��ȯ, ��ã���� end()
// �����͵� �ȿ� ã�� �����Ͱ� �ִ��� Ȯ���ϴ� �Լ�
void find_test()
{
	std::cout << "\n=======================================" << std::endl;
	std::vector<int> nums = { 1,2,3,4,5 };

	auto it = std::find(nums.begin(), nums.end(), 7);

	if (it != nums.end()) //!= �� �ƴϸ� => end ���� �ƴϸ�
	{
		std::cout << *it << std::endl; //3
	}
	else
	{
		std::cout << "�����͸� ã�� ���߽��ϴ�. " << std::endl;
	}
}


struct Monster
{
	int id;
	std::string name;

	Monster(int id, std::string name) :id(id), name(name) {}
};

//�˰����� ����� ��ȭ �ڵ�

/*
* std::�Լ��̸� = vec.begin(), vec.end() , (���ǵ� �Լ�, ���ٽ�, ����)�� �´�. 
* 
* 1. function pointer
* bool (*�Լ��̸�)(int x);
* 
* 2. functor : class ���� struct �̸�{ } ���� ������ 
* 
* 3. Lamba �� : �Լ��� �������� �ʾƵ� �Լ��� ȣ���� �� ó�� ����� �� �ִ�. �����Լ�.  
*    [](){}
* 
*/

// even Ȧ��
bool ISEven(int x)
{
	return x % 2 != 0;
}

// odd ¦��
bool ISOdd(int x)
{
	return x % 2 == 0;
}

bool CheckMonster(const Monster& findmon)
{
	return findmon.id == 3;
}


// monster
	// monsters.id

	//find_if : 3��° ���ڿ� ��� �����͸� ã�� ���ΰ�? ������ �־��ش�.
	// �Լ�, functor, ���ٽ�
void find_test2()
{
	std::vector<Monster> monsters;
	monsters.emplace_back(1, "��ī��"); // emplace_back�� ������ ȣ�Ⱑ��
	monsters.emplace_back(2, "�̻��ؾ�"); 
	monsters.emplace_back(3, "���̸�"); 
	monsters.emplace_back(4, "���α�"); 

	auto it = std::find_if(monsters.begin(), monsters.end(),
		[](const Monster& findmon) {return findmon.id == 3;}); // bool checkMonster�� ���� �ڵ��.

	std::cout << it->name << std::endl;

	std::cout << "�Լ� �����ͷ� ������ ���� " << std::endl;

	auto it2 = std::find_if(monsters.begin(), monsters.end(), CheckMonster);

	std::cout << it2->name << std::endl;
}

struct Square_Functor
{
	void operator()(int x)
	{
		std::cout << x * x << " ";
	}
};

void for_each_test()
{
	std::vector<int> nums = { 1,3,5 };
	Square_Functor square;
	std::for_each(nums.begin(), nums.end(), square);
}


void all_of_test()
{
	std::vector<int> nums = { 1,3,5 };

	if (std::all_of(nums.begin(), nums.end(), ISOdd))
	{
		std::cout << "nums�� ��� �����Ͱ� Ȧ�� �Դϴ�." << std::endl;
	}
	else
	{
		std::cout << " ��� �����Ͱ� ¦�� �Դϴ�" << std::endl;
	}
}