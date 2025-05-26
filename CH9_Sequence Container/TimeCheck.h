#pragma once

#include <iostream>
#include <chrono> //clock기능이 담겨있는 헤더
#include <vector>
#include <list>

/*
* vector와 list의 차이점
* 
* 1. 임의의 데이터에 접근하는 시간비교
*  결과 : vector는 바로 임의의 데이터에 접근가능 , 빠름 (O(1))
*		  list는 n번째 데이터에 접근하는데 길이에 비례해서 시간이 걸린다. (linear time O( n)
* 
* 2. 첫번째와 끝의 데이터가 아닌 데이터를 삭제 또는 수정하는데 걸리는 시간
*  - 데이터를 자주 삭제 또는 수정하는 경우에 vector의 시간이 비효율적
*    1~N 데이터 -> 1-N개 데이터 옮기는 작업
*   
*   데이터를 지우거나 변경하는 작업이 많으면 많을 수록 vector가 시간이 비효율적
* 
* 
*/

/*
* (번외) 어떠한 자류구조를 써야할 지 잘 모르겠으면 vector로 만들어보세요
* vector로 무엇을 했을때 시간이 더 오래걸릴까?
* 
*/

void TimeCheckTest() //vector
{

	std::cout << "특정 기능이 얼마나 시간이 걸리는지 측정하는 코드입니다" << std::endl;
	auto Start = std::chrono::high_resolution_clock::now();
	// 이 사이에 작성된 코드
	std::vector<int> nums;

	for (int i = 0; i < 10000000; i++)
	{
		nums.push_back(i);
	}

	for (int i= 0; i < 100000; i++)
	{
		auto it = nums.begin() + 5; //시작부터 n번뒤에있는 값에 접근해서 
		//auto it2 = std::next(nums.begin() + 500);
		nums.erase(it); //지우는녀석
	}

	

	//
	auto End = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> duration = End - Start;

	std::cout << duration.count() << "ms" << std::endl;


}
void TimeCheckTest2() // list
{

	std::cout << "STL list의 시간을 측정합니다." << std::endl;
	auto Start = std::chrono::high_resolution_clock::now();
	// 이 사이에 작성된 코드
	std::list<int> nums;

	for (int i = 0; i < 10000000; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 10000; i++)
	{
		auto it = std::next(nums.begin(), 5); //위에 vector 똑같은거 +n 할경우
		nums.erase(it);
	}


	//
	auto End = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> duration = End - Start;

	std::cout << duration.count() << "ms" << std::endl;

}