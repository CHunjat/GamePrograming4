#pragma once

/*
* ������ ����. 
* 1�ܰ� �÷��̾��� ������ ����ġ
* 2�ܰ� �����͸� �ڷᱸ�� ���·� ����.
* 1 100
* 2 200
*/

#include <fstream>
#include <iostream>
class Data
{
public:
	int exp;
	int level;

public:
	Data() : exp(100), level(1) {}
	void SaveData(const std::string& filename)
	{
		std::ofstream file(filename);

		// file �����.
		if (file.is_open())
		{
			file << level << " " << exp << std::endl;
			file.close(); // close(); ȣ�� �ݵ��
		}
		// �޸��忡 exp�� level�� �����ض�.
		
	}

	void loadData(const std::string& filename)
	{
		std::ifstream file(filename);

		int _exp, _level; //���Ͽ��� �ҷ����°�

		file >> _level >> _exp;

		level = _level;
		exp = _exp;
	}
};