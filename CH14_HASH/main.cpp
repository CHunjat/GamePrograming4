#include <iostream>
#include <map>
#include <unordered_map>
#include "ConsoleUtility.h"

#pragma region �ؽ� �Լ��� �����ΰ�?
/*
* Hash Function Hashing�ϴ��� �ǹ�?
*  - �����ϴ� Ÿ���� Ư���� ��Ģ���� �ٸ� Ÿ������ ��ȯ�ϴ� �۾�
*  Hashing ����� �����͸� �������ؼ� ����� �� �ִ�.
*/

/*
* Hash���� �ڷᱸ���� ����?
*
* map ���� ������ ������ ������, ������ Ž���� ������.
*/

int HashFunction(int input)
{
	return input % 10; // 0 ~ 9
}
void Test1()
{
	HashFunction(2500094535); // 2500094535 -> 9
	// unordered_map : [key - value] :: 9��� �ؽ������� 25234924���ڰ� ����ֽ��ϴ�.

	std::unordered_map<std::string, int > umap;
	umap.insert({ "�ٳ���", 5 });
	umap.insert({ "���",3 });

	std::cout << "���� 1" << std::endl;
	std::cout << "�ٳ����� ���� : " << umap["�ٳ���"] << std::endl;

	std::cout << "���� 2" << std::endl;
	std::cout << "���ξ����� �����ϳ���?" << std::endl;
	
	auto it = umap.find("���ξ���");
	if (it != umap.end())
	{
		std::cout << "ã�ҽ��ϴ�." << std::endl;

	}
	else
	{
		std::cout << "�����ϴ�" << std::endl;
	}
}




#pragma endregion

#pragma region map�� unordered_map �� ����?

/*
*  Ž���ϴµ� unorderd_map�� map���� ������
*  �������� ���� ������ �������� unordred_map �� �����ϴ�.
*  unordred_map�� �����ϴ�.
* 
*  ?? �� �����ұ�?
*  �����͸� �ʱ�ȭ �Ҷ� �ɸ��� �ð�
*  ���� �����̳� > ���� �����̳� (map) > unordered_map (�ؽ��Լ� �����Ǿ��ְ�, �ؽ��Լ��� �����ϴ� ���� �����Ͱ� �� ����) 
*   
*  �ؽ��Լ��� ����
*   - �ؽ��浹�� �߻��� �� �������ϰ� �߻� �� �� �ִ�.
*/
void MapTimeTest()
{
	std::map<std::string, int > map;
	map.insert({ "A", 1 });
	map.insert({ "B", 1 });
	map.insert({ "C", 1 });
	map.insert({ "D", 1 });
	map.insert({ "E", 1 });

	for (int i = 0; i < 100000; i++)
	{
		map.find("A");
	}

}

void UMapTiemTest()
{
	std::map<std::string, int > newmap;
	newmap.insert({ "A", 1 });
	newmap.insert({ "B", 1 });
	newmap.insert({ "C", 1 });
	newmap.insert({ "D", 1 });
	newmap.insert({ "E", 1 });

	for (int i = 0; i < 100000; i++)
	{
		newmap.find("A");
	}
}

void Test2()
{
	std::cout << " ù��° ��. ������ �Է½ð� �� :  " << std::endl;
	ConsoleUtil::TimeCheck(MapTimeTest);
	ConsoleUtil::TimeCheck(UMapTiemTest);

	std::cout << " map ���� : �������� �ڵ������� �߻� " << std::endl;
	std::cout << "������ �� �����͸� �ʿ��� �� map�� ����";
	std::cout << "�� �̿ܿ� �����̳� �ȿ� ������ �����͸� ã�� �����ϰ� �ʹ�." << std::endl;

	std::cout << "�ι�° �� - ������ �˻� �ð� �� " << std::endl;
}


#pragma endregion


int main()
{
	Test1();
	Test2();
}