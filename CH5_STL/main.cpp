#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <algorithm> // 90개 정도의 다양한 함수가 구현되어있다. en.cppreference.com/w/cpp/algorithm
#include "algo.h"


/*
* iterator(반복기)
* 포인터 역할을 하는 클래스
* 자료구조:: iterator
* 
*/

/*
* iterator를 사용해서 자료구조의 element를 출력할 수있다.
* begin(), cbegin(), rbegin(), crbegin()
* end()  ,  cend() , rend() , crend()    
* 
* auto it = 이름. 
* 
*/
// iterator의 기본 사용법
void test1()
{
	std::vector<int> nums = { 1,2,3,4,5 };
	std::list<int> intlist = { 1,2,3,4,5 };
	std::vector<int>::iterator it = nums.begin();

	std::cout << " iterator 를 활용한 자료구조 전체 데이터 출력" << std::endl;
	while (it != nums.end())
	{
		std::cout << *it << " "; //iterator 저장된 주소의 값을 역참조해서 출력
		it++;
	}

	std::cout << " for 반복문을 활용한 자료구조 전체 데이터출력" << std::endl;
	for (int i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i] << " ";
	}

	//vector가 아닌 다른 자료구조에서 데이터를 순회, 사용
	std::list<int>::iterator it2 = intlist.begin();
	std::cout << " ==============================================" << std::endl;
	std::cout << " list 자료구조를 전체 출력한 코드" << std::endl;
	while (it2 != intlist.end())
	{
		std::cout << *it2 << " ";
		it2++;
	}
}


//역순으로 출력하는 방법
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
	std::cout << "list를 역순으로 출력" << std::endl;
	std::list<int> lis{ 2,4,5,6,7,8,9 };
	auto it2 = lis.rbegin();
	while (it2 != lis.rend())
	{
		std::cout << *it2 << " ";
		it2++;

	}

}

//auto 키워드 사용법
void test3()
{
	std::cout << "\n===================================" << std::endl;

	// 예시1 
	auto x = 5;

	// 예시2 언제 사용하면 좋은가? -> 타입 이름이 매우 긴 예제들이 있다.
	std::vector<int> nums = { 1,2,3,4,5 };
	auto it = nums.begin();

	// 주의할 사항: 대입 연산자 오른쪽에 오늘 value 불특정한 데이터일때 사용을 하지 말것,

	// 예시3.
	

	// 데이터 자료형이 매우 작을 때 

	/*
	* auto			:	int , double, primitive type 사용할때 편하게 사용 (복사해서 만들어진다.)
	* auto&			:	메모리에 접근해서 데이터를 변경할 수 있다. 
	* const auto&	:   메모리에 데이터를 문법적으로 변경하지 못하게 한다.
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

// 상수 iterator
//

void test4()
{
	std::cout << "\n===================================" << std::endl;
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9 };

	//std::vector<int>::const_iterator it = vec.cbegin(); // 아래 auto 코드와 같다.
	auto it = vec.cbegin();

	while (it != vec.cend())
	{
		std::cout << *it << " ";
		it++;
	}
}
// iterator 응용 포인터 연산자
void test5()
{
	std::cout << "\n===================================" << std::endl;
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 }; 

	auto start = vec.begin() + 2; // 3번째 element 가리키고 있다. 3부터 시작하게됨
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

