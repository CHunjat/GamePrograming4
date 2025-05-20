#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>

// 찾으면 iterator 반환, 못찾으면 end()
// 데이터들 안에 찾는 데이터가 있는지 확인하는 함수
void find_test()
{
	std::cout << "\n=======================================" << std::endl;
	std::vector<int> nums = { 1,2,3,4,5 };

	auto it = std::find(nums.begin(), nums.end(), 7);

	if (it != nums.end()) //!= 이 아니면 => end 값이 아니면
	{
		std::cout << *it << std::endl; //3
	}
	else
	{
		std::cout << "데이터를 찾지 못했습니다. " << std::endl;
	}
}


struct Monster
{
	int id;
	std::string name;

	Monster(int id, std::string name) :id(id), name(name) {}
};

//알고리즘을 사용한 심화 코드

/*
* std::함수이름 = vec.begin(), vec.end() , (정의된 함수, 람다식, 펑터)가 온다. 
* 
* 1. function pointer
* bool (*함수이름)(int x);
* 
* 2. functor : class 도는 struct 이름{ } 옛날 문법임 
* 
* 3. Lamba 식 : 함수를 선언하지 않아도 함수를 호출한 것 처럼 사용할 수 있다. 무명함수.  
*    [](){}
* 
*/

// even 홀수
bool ISEven(int x)
{
	return x % 2 != 0;
}

// odd 짝수
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

	//find_if : 3번째 인자에 어떠한 데이터를 찾을 것인가? 조건을 넣어준다.
	// 함수, functor, 람다식
void find_test2()
{
	std::vector<Monster> monsters;
	monsters.emplace_back(1, "피카츄"); // emplace_back은 생성자 호출가능
	monsters.emplace_back(2, "이상해씨"); 
	monsters.emplace_back(3, "파이리"); 
	monsters.emplace_back(4, "꼬부기"); 

	auto it = std::find_if(monsters.begin(), monsters.end(),
		[](const Monster& findmon) {return findmon.id == 3;}); // bool checkMonster와 같은 코드다.

	std::cout << it->name << std::endl;

	std::cout << "함수 포인터로 구현한 예시 " << std::endl;

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
		std::cout << "nums의 모든 데이터가 홀수 입니다." << std::endl;
	}
	else
	{
		std::cout << " 모든 데이터가 짝수 입니다" << std::endl;
	}
}