#include "ConsoleUtility.h"


// Sequence Container : Vector, list , deque
// #include <컨테이너>

#include <vector>
#include <list>
#include <deque>

// 연관 컨테이너 associate Container : (multi, unordered) ,set, map 오늘은 set 만 

#include <set>
#include <map>
#include <algorithm> // 컨테이너에 데이터를 처리하는 기능들이 저장되어있는 라이브러리다.

// 1단계 순차 컨테이너의 데이터 입력 시간 비교
// 2단계 순차 컨테이너의 중간 데이터 입력 시간 비교
// 3단계 갯수와, 중간 데이터 삭제를 비교하여 적합한 순차 컨테이너 사용하기

#pragma region // 1단계 순차 컨테이너의 데이터 입력 시간 비교

void DatapushByVector()
{
	std::vector<int> nums; 
	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}
}

void DatapushByList()
{
	std::list<int> nums;
	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}

}

void DatapushByDeque()
{
	std::deque<int> nums;
	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}
}

void Test1()
{
	std::cout << "데이터 입력 시간 비교" << std::endl;
	std::cout << "vector 의 시간 : "; 
	ConsoleUtil::TimeCheck(DatapushByVector);
	std::cout << "List 의 시간 : "; 
	ConsoleUtil::TimeCheck(DatapushByList);
	std::cout << "deque 의 시간 : "; 
	ConsoleUtil::TimeCheck(DatapushByDeque);

	std::cout << "결과 : 단순 데이터를 입력 할 때 vector 가장 빠르다." << std::endl;
	std::cout << std::endl;
}

#pragma endregion

#pragma region // 2단계 순차 컨테이너의 중간 데이터 입력 시간 비교

void InsertDataByVector()
{
	std::vector<int> nums;
	for (int i = 0; i < 10; i++)
	{
		nums.push_back(i);
	}
	for (int i = 0; i < 10000; i++)
	{
		auto it = nums.begin() + 5; //중간삽입 코드, +5는 몇번째칸에? 
		nums.insert(it, 1);
	}
	
}
void InsertDataByList()
{
	std::list<int> nums;
	for (int i = 0; i < 10; i++)
	{
		nums.push_back(i);
	}
	for (int i = 0; i < 10000; i++)
	{
		auto it = std::next(nums.begin(), 5); // list의 중간삽입 코드 vector와 deque와 다르게 list는 다름
		nums.insert(it, 1);
	}

	

}
void InsertDataByDeque()
{
	std::deque<int> nums;
	for (int i = 0; i < 10; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 10000; i++)
	{
		auto it = nums.begin() + 5; //중간삽입 코드, +5는 몇번째칸에? 
		nums.insert(it, 1);
	}

}

void Test2()
{
	std::cout << "중간데이터 입력 시간 비교" << std::endl;
	std::cout << "vector 의 시간 : ";
	ConsoleUtil::TimeCheck(InsertDataByVector);
	std::cout << "List 의 시간 : ";
	ConsoleUtil::TimeCheck(InsertDataByList);
	std::cout << "deque 의 시간 : ";
	ConsoleUtil::TimeCheck(InsertDataByDeque);

	std::cout << "결과 : 처음에 데이터를 입력했을때 vector가 빠르다 " << std::endl;
	std::cout << "결과2 : 중간 삽입(삭제)하는 과정이 많으면 많을수록 list가 빨라질수 있다! " << std::endl;
	std::cout << std::endl;
}

#pragma endregion

#pragma region //2-2단계 순차 컨테이너 데이터를 맨 앞에 추가할때 걸리는 시간 비교

void FrontpushByVector()
{
	std::vector<int> nums;
	
	for (int i = 0; i < 1000; i++)
	{
		auto it = nums.begin();
		nums.insert(it, i);
	}
}

// double entiti queue
//

void FrontpushBylist()
{
	std::list<int> nums;

	for (int i = 0; i < 1000; i++)
	{
		nums.push_front(i);
	}

}
void FrontpushBydeque()
{
	std::deque<int> nums;
	for (int i = 0; i < 1000; i++)
	{
		nums.push_front(i);
	}

}

void Test2_2()
{
	std::cout << "첫번째데이터 입력 시간 비교" << std::endl;
	std::cout << "vector 의 시간 : ";
	ConsoleUtil::TimeCheck(FrontpushByVector);
	std::cout << "List 의 시간 : ";
	ConsoleUtil::TimeCheck(FrontpushBylist);
	std::cout << "deque 의 시간 : ";
	ConsoleUtil::TimeCheck(FrontpushBydeque);

	std::cout << "결과 : 1번째 원소를 넣는 경우에 vector의 장점과 단점을 해결할 수 있다. " << std::endl;
	std::cout << std::endl;
}



#pragma endregion

#pragma region //2-3단계 순차 컨테이너에서 랜덤 원소 접근에 걸리는 시간 비교

void RandomAccessByVector()
{
	std::vector<int> nums;
	for (int i = 0; i < 100; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 50; i++)
	{
		nums[i] =0;
	}
}
void RandomAccessBylist()
{
	std::list<int> nums;
	for (int i = 0; i < 100; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 50; i++)
	{
		auto it = std::next(nums.begin(), i);
		*it = 0;
	}
}
void RandomAccessBydeque()
{
	std::deque<int> nums;

	for (int i = 0; i < 100; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 50; i++)
	{
		nums[i] = 0;
	}
}

void Test2_3()
{
	std::cout << "랜덤 위치에 데이터를 접근하는 시간 비교" << std::endl;
	std::cout << "vector 의 시간 : ";
	ConsoleUtil::TimeCheck(RandomAccessByVector);
	std::cout << "List 의 시간 : ";
	ConsoleUtil::TimeCheck(RandomAccessBylist);
	std::cout << "deque 의 시간 : ";
	ConsoleUtil::TimeCheck(RandomAccessBydeque);

	std::cout << "결과 : 배열형태의 자료구조 (vector, deque) 바로 접근할 수 있다. " << std::endl;
	std::cout << "결과 : list의 경우는 시작과 거리가 멀면 멀수록 시간이 오래 걸린다. " << std::endl;
	std::cout << std::endl;
}



#pragma endregion

#pragma region //순차 컨테이너 비교
/*	        |      vector      |         list          |       deque        |
*   push    |         1        |          3            |         2          |
*  insert   |         2        |          1            |         3          |         
*  front    |         3        |          2            |         1          |
*  access   |         1        |          3            |         2          | 
*/

/*
* case1. 상황 부여 . 데이터의 입력이 (많이) 발생을 하고, 중간데이터의 입력이 (적으며) 앞에 데이터(적으며), 랜덤접근이 많은경우 
*/

#pragma endregion 

#pragma region //3단계 순차 컨테이너와 연관 컨테이너 (set) 이라는 녀석만

// 데이터를 저장하는 공간으로 컨테이너를 선언하고 만들었다.
// std::vector<monster> nums;  monster a = nums[?]
// 컨테이너 안에 해당하는 데이터가 없으면? 에러가 발생한다. if(데이터가 존재 하나요?) -> 실행
bool Find(int value)
{
	int nums[10] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 10; i++)
	{
		if (nums[i] == value)
		{
			std::cout << nums[i] << " 값을 찾았습니다" << std::endl;
			return true;
		}
	}
	std::cout << "값을 못찾았습니다" << std::endl;
	return false;
}

void FindByVector()
{
	std::vector<int>nums;
	for (int i = 10; i > 0; i--)
	{
		nums.push_back(i);
	}

	for (auto num : nums)
	{
		std::cout << num << " ";
	}
	for (int i = 0; i < 1000; i++)
	{
		std::find(nums.begin(), nums.end(), i);
	}
	
}
void FindBylist()
{
	std::list<int>nums;
	for (int i = 10; i > 0; i--)
	{
		nums.push_back(i);
	}
	for (auto num : nums)
	{
		std::cout << num << " ";
	}

	for (int i = 0; i < 1000; i++)
	{
		std::find(nums.begin(), nums.end(), i);
	}
}
void FindBydeque()
{
	std::deque<int>nums;
	for (int i = 10; i > 0; i--)
	{
		nums.push_back(i);
	}
	for (auto num : nums)
	{
		std::cout << num << " ";
	}

	for (int i = 0; i < 1000; i++)
	{
		std::find(nums.begin(), nums.end(), i);
	}
}
void FindByset() // set을 왜사용해야할까? 기본적으로 넣자마자 자동으로 정렬이 된다는 특징이있음.
{
	std::set<int> nums;
	for (int i = 10; i > 0; i--)
	{
		nums.insert(i);
	}
	nums.insert(100);
	nums.insert(120);

	nums.insert(1);


	for (auto num : nums)
	{
		std::cout << num << " ";
	}

	for (int i = 0; i < 1000; i++)
	{
		nums.find(i);
	}
}

void Test3()
{
	std::cout << "데이터를 검색하는 시간 비교" << std::endl;
	std::cout << "vector 의 시간 : ";
	ConsoleUtil::TimeCheck(FindByVector);
	std::cout << "List 의 시간 : ";
	ConsoleUtil::TimeCheck(FindBylist);
	std::cout << "deque 의 시간 : ";
	ConsoleUtil::TimeCheck(FindBydeque);
	std::cout << "set 의 시간 : ";
	ConsoleUtil::TimeCheck(FindByset);

	std::cout << "결과 : 순차 컨테이너는 데이터를 입력하는데 빠르다. " << std::endl;
	std::cout << "결과 : 연관 컨테이너는 자체적으로 데이터를 입력하는 로직이 존재하기 떄문에 시간이 더걸린다.. " << std::endl;
	std::cout << "데이터를 지속적으로 입력하는 경우가 아니면서 자주 데이터를 검색해야 할때 사용한다 (set) " << std::endl;
	std::cout << std::endl;
}


#pragma endregion 

int main()
{
	Test1();
	Test2();
	Test2_2();
	Test2_3();

	/*std::cout << std::boolalpha;
	std::cout << Find(10);*/

	Test3();

	FindByVector();
	std::cout << std::endl;
	FindBylist();
	std::cout << std::endl;
	FindBydeque();
	std::cout << std::endl;
	FindByset();
	std::cout << std::endl;

}