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
* vector와 list의 차이점을 직접 비교해보세요.
* 
* 1. vector push_back 추가, list push_back 추가 한 시간을 비교해보세요 : 결과 < > 누가 더 빨랐다. 그이유느?
* 2. 임의의 데이터에 접근하는데 걸리는 시간 : 결과 vector가 더 빠르다. list 개수가 많을수록 더 시간이 걸림.
* 3. 임의의 데이터를 지우는데 걸리는 시간   : list가 더빠르다.
* 
*    접근하는데, vector , 지우는데 list 둘다 장단점 있으니 선택
*    데이터가 삭제는 적은데, 접근은 많은경우 vector 유리
*    데이터가 삭제가 빈번한 경우 list 유리
* 
*    (★★★★★)데이터 삭제도 많고 접근도 많으면?? : ?? unordered_map

     vector 
	 unordered_map  사실상 웬만한 게임제작시 두개 사용해도 될정도. 
*/

/*
* Vector, Lisst 크게 차이점이 없다.
* Vector[]인덱스로 데이터로 출력할 수 있다.
* List[]인덱스로 데이터로 출력할 수 없다. // 배열이 아니면 어떻게 자료를 표현할수 있을까?
* 
* 차이점을 눈으로 확인하기 위해서 화면설정을 진행한다.
*/


struct Node
{
	int value;
	Node* NextPtr; //다음주소
	Node* prevPtr; //이전주소
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
	std::cout << "임의의 데이터 접근시간" << std::endl;
	std::cout << nums[900] << std::endl;
    //erase함수, n번 사용하는 예제
}

void listExample()
{
	std::list<int>nums;
	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}
	std::cout << "임의의 데이터 접근시간" << std::endl;
	//erase함수, n번 사용하는 예제


	auto it = std::next(nums.begin(), 900);
	std::cout << *it << std::endl;

}

int main()
{
	//Test1_vector();
	//Test2_List();
	
	
	// 자료구조 시간 테스트
	//TimeCheckTest();
	//TimeCheckTest2();

	//함수 포인터 예제
	//Test();

	
	ConsoleUtil::TimeCheck(VectorExample);
	ConsoleUtil::TimeCheck(listExample);
}