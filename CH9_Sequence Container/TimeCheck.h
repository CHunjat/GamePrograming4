#pragma once

#include <iostream>
#include <chrono> //clock����� ����ִ� ���
#include <vector>
#include <list>

/*
* vector�� list�� ������
* 
* 1. ������ �����Ϳ� �����ϴ� �ð���
*  ��� : vector�� �ٷ� ������ �����Ϳ� ���ٰ��� , ���� (O(1))
*		  list�� n��° �����Ϳ� �����ϴµ� ���̿� ����ؼ� �ð��� �ɸ���. (linear time O( n)
* 
* 2. ù��°�� ���� �����Ͱ� �ƴ� �����͸� ���� �Ǵ� �����ϴµ� �ɸ��� �ð�
*  - �����͸� ���� ���� �Ǵ� �����ϴ� ��쿡 vector�� �ð��� ��ȿ����
*    1~N ������ -> 1-N�� ������ �ű�� �۾�
*   
*   �����͸� ����ų� �����ϴ� �۾��� ������ ���� ���� vector�� �ð��� ��ȿ����
* 
* 
*/

/*
* (����) ��� �ڷ������� ����� �� �� �𸣰����� vector�� ��������
* vector�� ������ ������ �ð��� �� �����ɸ���?
* 
*/

void TimeCheckTest() //vector
{

	std::cout << "Ư�� ����� �󸶳� �ð��� �ɸ����� �����ϴ� �ڵ��Դϴ�" << std::endl;
	auto Start = std::chrono::high_resolution_clock::now();
	// �� ���̿� �ۼ��� �ڵ�
	std::vector<int> nums;

	for (int i = 0; i < 10000000; i++)
	{
		nums.push_back(i);
	}

	for (int i= 0; i < 100000; i++)
	{
		auto it = nums.begin() + 5; //���ۺ��� n���ڿ��ִ� ���� �����ؼ� 
		//auto it2 = std::next(nums.begin() + 500);
		nums.erase(it); //����³༮
	}

	

	//
	auto End = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> duration = End - Start;

	std::cout << duration.count() << "ms" << std::endl;


}
void TimeCheckTest2() // list
{

	std::cout << "STL list�� �ð��� �����մϴ�." << std::endl;
	auto Start = std::chrono::high_resolution_clock::now();
	// �� ���̿� �ۼ��� �ڵ�
	std::list<int> nums;

	for (int i = 0; i < 10000000; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 10000; i++)
	{
		auto it = std::next(nums.begin(), 5); //���� vector �Ȱ����� +n �Ұ��
		nums.erase(it);
	}


	//
	auto End = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> duration = End - Start;

	std::cout << duration.count() << "ms" << std::endl;

}