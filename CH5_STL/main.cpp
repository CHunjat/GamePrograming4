#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <algorithm> // 90�� ������ �پ��� �Լ��� �����Ǿ��ִ�. en.cppreference.com/w/cpp/algorithm
#include "algo.h"


/*
* iterator(�ݺ���)
* ������ ������ �ϴ� Ŭ����
* �ڷᱸ��:: iterator
* 
*/

/*
* iterator�� ����ؼ� �ڷᱸ���� element�� ����� ���ִ�.
* begin(), cbegin(), rbegin(), crbegin()
* end()  ,  cend() , rend() , crend()    
* 
* auto it = �̸�. 
* 
*/
// iterator�� �⺻ ����
void test1()
{
	std::vector<int> nums = { 1,2,3,4,5 };
	std::list<int> intlist = { 1,2,3,4,5 };
	std::vector<int>::iterator it = nums.begin();

	std::cout << " iterator �� Ȱ���� �ڷᱸ�� ��ü ������ ���" << std::endl;
	while (it != nums.end())
	{
		std::cout << *it << " "; //iterator ����� �ּ��� ���� �������ؼ� ���
		it++;
	}

	std::cout << " for �ݺ����� Ȱ���� �ڷᱸ�� ��ü ���������" << std::endl;
	for (int i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i] << " ";
	}

	//vector�� �ƴ� �ٸ� �ڷᱸ������ �����͸� ��ȸ, ���
	std::list<int>::iterator it2 = intlist.begin();
	std::cout << " ==============================================" << std::endl;
	std::cout << " list �ڷᱸ���� ��ü ����� �ڵ�" << std::endl;
	while (it2 != intlist.end())
	{
		std::cout << *it2 << " ";
		it2++;
	}
}


//�������� ����ϴ� ���
void test2()
{
	std::cout << "\n===================================" << std::endl;
	std::vector<int> vec { 1,2,3,4,5,6,7,8,9 };
	auto it = vec.rbegin();
	

	while (it != vec.rend())
	{
		std::cout << *it << " ";
		it++;
	}


	std::cout << std::endl;
	std::cout << "list�� �������� ���" << std::endl;
	std::list<int> lis{ 2,4,5,6,7,8,9 };
	auto it2 = lis.rbegin();
	while (it2 != lis.rend())
	{
		std::cout << *it2 << " ";
		it2++;

	}

}

//auto Ű���� ����
void test3()
{
	std::cout << "\n===================================" << std::endl;

	// ����1 
	auto x = 5;

	// ����2 ���� ����ϸ� ������? -> Ÿ�� �̸��� �ſ� �� �������� �ִ�.
	std::vector<int> nums = { 1,2,3,4,5 };
	auto it = nums.begin();

	// ������ ����: ���� ������ �����ʿ� ���� value ��Ư���� �������϶� ����� ���� ����,

	// ����3.
	

	// ������ �ڷ����� �ſ� ���� �� 

	/*
	* auto			:	int , double, primitive type ����Ҷ� ���ϰ� ��� (�����ؼ� ���������.)
	* auto&			:	�޸𸮿� �����ؼ� �����͸� ������ �� �ִ�. 
	* const auto&	:   �޸𸮿� �����͸� ���������� �������� ���ϰ� �Ѵ�.
	* 
	*/

	for (const auto& num : nums)
	{
		std::cout << num << " "; 
	}

	for (auto& i : nums)
	{
		i = 0;
	}

	for (auto num : nums)
	{
		std::cout << num << " "; 
	}
}

// ��� iterator
//

void test4()
{
	std::cout << "\n===================================" << std::endl;
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9 };

	//std::vector<int>::const_iterator it = vec.cbegin(); // �Ʒ� auto �ڵ�� ����.
	auto it = vec.cbegin();

	while (it != vec.cend())
	{
		std::cout << *it << " ";
		it++;
	}
}
// iterator ���� ������ ������
void test5()
{
	std::cout << "\n===================================" << std::endl;
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 }; 

	auto start = vec.begin() + 2; // 3��° element ����Ű�� �ִ�. 3���� �����ϰԵ�
	auto finish = vec.end() - 3; 

	while(start != finish)
	{
		std::cout << *start << " ";
		start++;
	}
}
	int main()
{
		//test1();
		//test2();
		//test3();
		//test4();
		//test5();
		//find_test();
		find_test2();
		all_of_test();
		for_each_test();
}

