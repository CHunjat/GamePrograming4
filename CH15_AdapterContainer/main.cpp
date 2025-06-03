/*
* adapt �����̳�
* vector, list, deque ������� Ư���� �����̳�.
* 
* stack,queue,priority_queue
* ����,ť,�켱���� ť
*/

#include <iostream>
#pragma region ����
/*
* �޸� ���� LIFO�̴�. LAST IN FIRST OUT
* �����͸� ����ϴ� ��Ģ�� �����ϴ� ������ ȿ���� ��� �ڷᱸ��
* iTERATOR �������� �ʴ´�. (���������� iterator Ŭ���� ����)
* ctrl+z (history - Ư�� ��ġ�� ���ư� �� �ִ�.
*/
#include <stack>

void Test1()
{
	std::cout << "���û�뿹��" << std::endl;
	std::stack<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);

	}
	std::cout << "nums�� ���������" << std::endl;
	// iterator�� �������� �ʾ� ���� ��� for loop ���Ұ���
	/*for (const auto& num : nums)
	{ 
		std::cout << num << " ";
		
	}*/

	while (!nums.empty()) // �ڷᱸ���� ������� ������ �ݺ��϶�.
	{
		std::cout << nums.top() << " "; // top ���� ���� �����͸� ����϶�
		nums.pop();						//top �� �����͸� �����϶�.
	}
	// size() =nums�� �ִ밪�� ��ȯ

	/*for (int i = 0; i < nums.size(); i++)
	{
		std::cout << nums.top() << " "; 
		nums.pop();
	}*/


}

#pragma endregion

#pragma region ť
/*
* �޸� ���� FIFO�̴�, FIRST IN FIRST OUT
*/
#include<queue>

void Test2()
{
	std::cout << "\n\nť ��뿹��" << std::endl;
	std::queue<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);

	}


	while (!nums.empty()) // �ڷᱸ���� ������� ������ �ݺ��϶�.
	{
		std::cout << nums.front() << " "; // top ���� ���� �����͸� ����϶�
		nums.pop();						//top �� �����͸� �����϶�.
	}
	// size() =nums�� �ִ밪�� ��ȯ

	/*for (int i = 0; i < nums.size(); i++)
	{
		std::cout << nums.top() << " ";
		nums.pop();
	}*/


}
#pragma endregion

#pragma region �켱���� ť!!

//ť : ���� ������� ������.(x) ���� �������� ����� ���� ������.
// ���. �Ϲ� �ʴ��, Ư���ʴ��?
// �ð�, ��
// �� �Ȱ��� �ð��� ���� ��, 

//#include <queue> // ���ԵǾ��ִ�.
// heap �˰������� �����Ǿ� �ֽ��ϴ�. ���� ����(ū) �� Ʈ�� ������ ������ ������ ����
// heapipy

void Test3()
{
	std::cout << "\n\n�켱���� ť ��뿹��" << std::endl; //���ڰ� ū�༮�� �켱������ �����Ǿ� �ִ�.
	std::priority_queue<int> nums;

	nums.push(0);
	nums.push(5);
	nums.push(7);
	nums.push(3);
	nums.push(9);


	while (!nums.empty()) // �ڷᱸ���� ������� ������ �ݺ��϶�.
	{
		std::cout << nums.top() << " "; // top ���� ���� �����͸� ����϶�
		nums.pop();						//top �� �����͸� �����϶�.
	}
	// size() =nums�� �ִ밪�� ��ȯ

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
	

//Ư�� �ڷᱸ���� ���
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
	std::cout << "\n\n�������� ť ��뿹��" << std::endl;
	Myqueue<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);

	}


	while (!nums.empty()) // �ڷᱸ���� ������� ������ �ݺ��϶�.
	{
		std::cout << nums.empty() << " "; // top ���� ���� �����͸� ����϶�
		nums.pop();						//top �� �����͸� �����϶�.
	}
	// size() =nums�� �ִ밪�� ��ȯ

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
	std::cout << "\n\n�������� ���� ��뿹��" << std::endl;
	Mystack<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);

	}

	std::cout << "nums�� ������ ���" << std::endl;
	while (!nums.empty()) // �ڷᱸ���� ������� ������ �ݺ��϶�.
	{
		std::cout << nums.top() << " "; // top ���� ���� �����͸� ����϶�
		nums.pop();						//top �� �����͸� �����϶�.
	}
	// size() =nums�� �ִ밪�� ��ȯ

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