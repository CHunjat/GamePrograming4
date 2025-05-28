#include "ConsoleUtility.h"


// Sequence Container : Vector, list , deque
// #include <�����̳�>

#include <vector>
#include <list>
#include <deque>

// ���� �����̳� associate Container : (multi, unordered) ,set, map ������ set �� 

#include <set>
#include <map>
#include <algorithm> // �����̳ʿ� �����͸� ó���ϴ� ��ɵ��� ����Ǿ��ִ� ���̺귯����.

// 1�ܰ� ���� �����̳��� ������ �Է� �ð� ��
// 2�ܰ� ���� �����̳��� �߰� ������ �Է� �ð� ��
// 3�ܰ� ������, �߰� ������ ������ ���Ͽ� ������ ���� �����̳� ����ϱ�

#pragma region // 1�ܰ� ���� �����̳��� ������ �Է� �ð� ��

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
	std::cout << "������ �Է� �ð� ��" << std::endl;
	std::cout << "vector �� �ð� : "; 
	ConsoleUtil::TimeCheck(DatapushByVector);
	std::cout << "List �� �ð� : "; 
	ConsoleUtil::TimeCheck(DatapushByList);
	std::cout << "deque �� �ð� : "; 
	ConsoleUtil::TimeCheck(DatapushByDeque);

	std::cout << "��� : �ܼ� �����͸� �Է� �� �� vector ���� ������." << std::endl;
	std::cout << std::endl;
}

#pragma endregion

#pragma region // 2�ܰ� ���� �����̳��� �߰� ������ �Է� �ð� ��

void InsertDataByVector()
{
	std::vector<int> nums;
	for (int i = 0; i < 10; i++)
	{
		nums.push_back(i);
	}
	for (int i = 0; i < 10000; i++)
	{
		auto it = nums.begin() + 5; //�߰����� �ڵ�, +5�� ���°ĭ��? 
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
		auto it = std::next(nums.begin(), 5); // list�� �߰����� �ڵ� vector�� deque�� �ٸ��� list�� �ٸ�
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
		auto it = nums.begin() + 5; //�߰����� �ڵ�, +5�� ���°ĭ��? 
		nums.insert(it, 1);
	}

}

void Test2()
{
	std::cout << "�߰������� �Է� �ð� ��" << std::endl;
	std::cout << "vector �� �ð� : ";
	ConsoleUtil::TimeCheck(InsertDataByVector);
	std::cout << "List �� �ð� : ";
	ConsoleUtil::TimeCheck(InsertDataByList);
	std::cout << "deque �� �ð� : ";
	ConsoleUtil::TimeCheck(InsertDataByDeque);

	std::cout << "��� : ó���� �����͸� �Է������� vector�� ������ " << std::endl;
	std::cout << "���2 : �߰� ����(����)�ϴ� ������ ������ �������� list�� �������� �ִ�! " << std::endl;
	std::cout << std::endl;
}

#pragma endregion

#pragma region //2-2�ܰ� ���� �����̳� �����͸� �� �տ� �߰��Ҷ� �ɸ��� �ð� ��

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
	std::cout << "ù��°������ �Է� �ð� ��" << std::endl;
	std::cout << "vector �� �ð� : ";
	ConsoleUtil::TimeCheck(FrontpushByVector);
	std::cout << "List �� �ð� : ";
	ConsoleUtil::TimeCheck(FrontpushBylist);
	std::cout << "deque �� �ð� : ";
	ConsoleUtil::TimeCheck(FrontpushBydeque);

	std::cout << "��� : 1��° ���Ҹ� �ִ� ��쿡 vector�� ������ ������ �ذ��� �� �ִ�. " << std::endl;
	std::cout << std::endl;
}



#pragma endregion

#pragma region //2-3�ܰ� ���� �����̳ʿ��� ���� ���� ���ٿ� �ɸ��� �ð� ��

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
	std::cout << "���� ��ġ�� �����͸� �����ϴ� �ð� ��" << std::endl;
	std::cout << "vector �� �ð� : ";
	ConsoleUtil::TimeCheck(RandomAccessByVector);
	std::cout << "List �� �ð� : ";
	ConsoleUtil::TimeCheck(RandomAccessBylist);
	std::cout << "deque �� �ð� : ";
	ConsoleUtil::TimeCheck(RandomAccessBydeque);

	std::cout << "��� : �迭������ �ڷᱸ�� (vector, deque) �ٷ� ������ �� �ִ�. " << std::endl;
	std::cout << "��� : list�� ���� ���۰� �Ÿ��� �ָ� �ּ��� �ð��� ���� �ɸ���. " << std::endl;
	std::cout << std::endl;
}



#pragma endregion

#pragma region //���� �����̳� ��
/*	        |      vector      |         list          |       deque        |
*   push    |         1        |          3            |         2          |
*  insert   |         2        |          1            |         3          |         
*  front    |         3        |          2            |         1          |
*  access   |         1        |          3            |         2          | 
*/

/*
* case1. ��Ȳ �ο� . �������� �Է��� (����) �߻��� �ϰ�, �߰��������� �Է��� (������) �տ� ������(������), ���������� ������� 
*/

#pragma endregion 

#pragma region //3�ܰ� ���� �����̳ʿ� ���� �����̳� (set) �̶�� �༮��

// �����͸� �����ϴ� �������� �����̳ʸ� �����ϰ� �������.
// std::vector<monster> nums;  monster a = nums[?]
// �����̳� �ȿ� �ش��ϴ� �����Ͱ� ������? ������ �߻��Ѵ�. if(�����Ͱ� ���� �ϳ���?) -> ����
bool Find(int value)
{
	int nums[10] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 10; i++)
	{
		if (nums[i] == value)
		{
			std::cout << nums[i] << " ���� ã�ҽ��ϴ�" << std::endl;
			return true;
		}
	}
	std::cout << "���� ��ã�ҽ��ϴ�" << std::endl;
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
void FindByset() // set�� �ֻ���ؾ��ұ�? �⺻������ ���ڸ��� �ڵ����� ������ �ȴٴ� Ư¡������.
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
	std::cout << "�����͸� �˻��ϴ� �ð� ��" << std::endl;
	std::cout << "vector �� �ð� : ";
	ConsoleUtil::TimeCheck(FindByVector);
	std::cout << "List �� �ð� : ";
	ConsoleUtil::TimeCheck(FindBylist);
	std::cout << "deque �� �ð� : ";
	ConsoleUtil::TimeCheck(FindBydeque);
	std::cout << "set �� �ð� : ";
	ConsoleUtil::TimeCheck(FindByset);

	std::cout << "��� : ���� �����̳ʴ� �����͸� �Է��ϴµ� ������. " << std::endl;
	std::cout << "��� : ���� �����̳ʴ� ��ü������ �����͸� �Է��ϴ� ������ �����ϱ� ������ �ð��� ���ɸ���.. " << std::endl;
	std::cout << "�����͸� ���������� �Է��ϴ� ��찡 �ƴϸ鼭 ���� �����͸� �˻��ؾ� �Ҷ� ����Ѵ� (set) " << std::endl;
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