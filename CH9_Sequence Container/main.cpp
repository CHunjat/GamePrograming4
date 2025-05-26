#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "TimeCheck.h"
#include "FunctionPointer.h"
#include "ConsoleUtility.h"



/*
* Sequence Container
* Vector
* Deque
* List
*/

/*
* vector�� list�� �������� ���� ���غ�����.
* 
* 1. vector push_back �߰�, list push_back �߰� �� �ð��� ���غ����� : ��� < > ���� �� ������. ��������?
* 2. ������ �����Ϳ� �����ϴµ� �ɸ��� �ð� : ��� vector�� �� ������. list ������ �������� �� �ð��� �ɸ�.
* 3. ������ �����͸� ����µ� �ɸ��� �ð�   : list�� ��������.
* 
*    �����ϴµ�, vector , ����µ� list �Ѵ� ����� ������ ����
*    �����Ͱ� ������ ������, ������ ������� vector ����
*    �����Ͱ� ������ ����� ��� list ����
* 
*    (�ڡڡڡڡ�)������ ������ ���� ���ٵ� ������?? : ?? unordered_map

     vector 
	 unordered_map  ��ǻ� ������ �������۽� �ΰ� ����ص� ������. 
*/

/*
* Vector, Lisst ũ�� �������� ����.
* Vector[]�ε����� �����ͷ� ����� �� �ִ�.
* List[]�ε����� �����ͷ� ����� �� ����. // �迭�� �ƴϸ� ��� �ڷḦ ǥ���Ҽ� ������?
* 
* �������� ������ Ȯ���ϱ� ���ؼ� ȭ�鼳���� �����Ѵ�.
*/


struct Node
{
	int value;
	Node* NextPtr; //�����ּ�
	Node* prevPtr; //�����ּ�
};
void Test1_vector()
{
	std::vector<int> nums;
	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}

	std::cout << nums[500] << std::endl;

	

}

void Test2_List()
{
	std::list<int> nums;

	nums.push_back(3);
	nums.push_front(2);
	nums.push_back(1);

	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}
}

void VectorExample()
{
	std::vector<int>nums;
	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}
	std::cout << "������ ������ ���ٽð�" << std::endl;
	std::cout << nums[900] << std::endl;
    //erase�Լ�, n�� ����ϴ� ����
}

void listExample()
{
	std::list<int>nums;
	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}
	std::cout << "������ ������ ���ٽð�" << std::endl;
	//erase�Լ�, n�� ����ϴ� ����


	auto it = std::next(nums.begin(), 900);
	std::cout << *it << std::endl;

}

int main()
{
	//Test1_vector();
	//Test2_List();
	
	
	// �ڷᱸ�� �ð� �׽�Ʈ
	//TimeCheckTest();
	//TimeCheckTest2();

	//�Լ� ������ ����
	//Test();

	
	ConsoleUtil::TimeCheck(VectorExample);
	ConsoleUtil::TimeCheck(listExample);
}