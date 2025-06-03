/*
* adapt 컨테이너
* vector, list, deque 만들어진 특별한 컨테이너.
* 
* stack,queue,priority_queue
* 스택,큐,우선순위 큐
*/

#include <iostream>
#pragma region 스택
/*
* 메모리 구조 LIFO이다. LAST IN FIRST OUT
* 데이터를 사용하는 규칙을 제한하는 것으로 효율을 얻는 자료구조
* iTERATOR 지원하지 않는다. (내부적으로 iterator 클래스 없음)
* ctrl+z (history - 특정 위치로 돌아갈 수 있다.
*/
#include <stack>

void Test1()
{
	std::cout << "스택사용예시" << std::endl;
	std::stack<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);

	}
	std::cout << "nums의 데이터출력" << std::endl;
	// iterator를 지원하지 않아 범위 기반 for loop 사용불가능
	/*for (const auto& num : nums)
	{ 
		std::cout << num << " ";
		
	}*/

	while (!nums.empty()) // 자료구조가 비어있지 않을때 반복하라.
	{
		std::cout << nums.top() << " "; // top 제일 위에 데이터를 출력하라
		nums.pop();						//top 의 데이터를 삭제하라.
	}
	// size() =nums의 최대값을 반환

	/*for (int i = 0; i < nums.size(); i++)
	{
		std::cout << nums.top() << " "; 
		nums.pop();
	}*/


}

#pragma endregion

#pragma region 큐
/*
* 메모리 구조 FIFO이다, FIRST IN FIRST OUT
*/
#include<queue>

void Test2()
{
	std::cout << "\n\n큐 사용예시" << std::endl;
	std::queue<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);

	}


	while (!nums.empty()) // 자료구조가 비어있지 않을때 반복하라.
	{
		std::cout << nums.front() << " "; // top 제일 위에 데이터를 출력하라
		nums.pop();						//top 의 데이터를 삭제하라.
	}
	// size() =nums의 최대값을 반환

	/*for (int i = 0; i < nums.size(); i++)
	{
		std::cout << nums.top() << " ";
		nums.pop();
	}*/


}
#pragma endregion

#pragma region 우선순위 큐!!

//큐 : 들어온 순서대로 나간다.(x) 먼저 나가야할 사람이 빨리 나간다.
// 사람. 일반 초대권, 특별초대권?
// 시간, 돈
// 다 똑같은 시간에 왔을 때, 

//#include <queue> // 포함되어있다.
// heap 알고리즘으로 구현되어 있습니다. 가장 작은(큰) 값 트리 구조의 맨위로 보내는 형태
// heapipy

void Test3()
{
	std::cout << "\n\n우선순위 큐 사용예시" << std::endl; //숫자가 큰녀석이 우선순위가 설정되어 있다.
	std::priority_queue<int> nums;

	nums.push(0);
	nums.push(5);
	nums.push(7);
	nums.push(3);
	nums.push(9);


	while (!nums.empty()) // 자료구조가 비어있지 않을때 반복하라.
	{
		std::cout << nums.top() << " "; // top 제일 위에 데이터를 출력하라
		nums.pop();						//top 의 데이터를 삭제하라.
	}
	// size() =nums의 최대값을 반환

	/*for (int i = 0; i < nums.size(); i++)
	{
		std::cout << nums.top() << " ";
		nums.pop();
	}*/
}

#pragma endregion

#include <vector>
#include <deque>
template <typename T>
class Myqueue
{
private:
	int _size;
	std::deque<T> data;
	

//특정 자료구조를 사용
public: 

	Myqueue() :_size(0) {}


	void push(T& e)
	{
		_size++;
		data.push_back(e);
	}

	T top()
	{
		return data[0];
	}

	void pop()
	{
		_size--;
		data.pop_front();

	}

	int size()
	{
		return _size;
	}

	bool empty()
	{
		return _size == 0;
	}
};

void Test4()
{
	std::cout << "\n\n내가만든 큐 사용예시" << std::endl;
	Myqueue<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);

	}


	while (!nums.empty()) // 자료구조가 비어있지 않을때 반복하라.
	{
		std::cout << nums.empty() << " "; // top 제일 위에 데이터를 출력하라
		nums.pop();						//top 의 데이터를 삭제하라.
	}
	// size() =nums의 최대값을 반환

	/*for (int i = 0; i < nums.size(); i++)
	{
		std::cout << nums.top() << " ";
		nums.pop();
	}*/



}


template <typename T>
class Mystack
{
private:
	int _size;
	std::vector<T> data;
public:
	Mystack() : _size(0) {}

	void push(T& e)
	{
		_size++;
		data.push_back(e);
	}

	T top()
	{
		return data[_size -1];
	}

	void pop()
	{
		_size--;
		data.pop_back();

	}

	int size()
	{
		return _size;
	}

	bool empty()
	{
		return _size == 0;
	}
};



void Test5()
{
	std::cout << "\n\n내가만든 스택 사용예시" << std::endl;
	Mystack<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);

	}

	std::cout << "nums의 데이터 출력" << std::endl;
	while (!nums.empty()) // 자료구조가 비어있지 않을때 반복하라.
	{
		std::cout << nums.top() << " "; // top 제일 위에 데이터를 출력하라
		nums.pop();						//top 의 데이터를 삭제하라.
	}
	// size() =nums의 최대값을 반환

	/*for (int i = 0; i < nums.size(); i++)
	{
		std::cout << nums.top() << " ";
		nums.pop();
	}*/



}


int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
}