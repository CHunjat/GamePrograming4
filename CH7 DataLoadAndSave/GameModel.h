#pragma once
#include <iostream>
#include <vector>
#include <fstream>
/*
*  ��ǥ : ������ �ý��� �����ϰ� �ʹ�.
*  int exp; , int maxexp;  ���� ����ġ > maxexp ������ 1�ø���.
*/

/*
*  ��ǥ2 : ������ ���� ����ġ �䱸���� �ڷᱸ���� ǥ���ϱ�!
*  vector< " " >
*/

/*
* �����͸� ǥ���ϱ� ���� Ŭ������ �����ϼ��� LevelExp
*  Ư�� Ŭ���� �ȿ� ǥ���ϱ� ���� Ŭ������ �ڷᱸ���� �����ϼ��� Player-> std::vector<LevelExp> levelTable;
*/

/*
* �����ڿ� �����͸� ���� �ۼ��Ѵ�.
*	 vector.push_back() 
	 vector.emplace_back()
*/


struct LevelExp
{
	int level;
	int Maxexp;

	LevelExp(int level, int Maxexp) : level(level), Maxexp(Maxexp) {}
};

class Player
{
private:
	int exp;
	int Maxexp;
	int level;
	std::vector<LevelExp> levelTable;

public:
	Player() : exp(0), level(1), Maxexp(100) {}
	Player(int exp, int Maxexp) : level(1), exp(exp), Maxexp(Maxexp) 
	{
		levelTable.emplace_back(1, 100);
		levelTable.emplace_back(2, 100);
		levelTable.emplace_back(3, 100);
		levelTable.emplace_back(4, 150);
		levelTable.emplace_back(5, 150);
		levelTable.emplace_back(6, 150);
		levelTable.emplace_back(7, 200);
		levelTable.emplace_back(8, 200);
		levelTable.emplace_back(9, 200);
	}


	int GetMaxExpForLevel(int level)
	{
		for (const auto& data : levelTable)
		{
			//  ������ table ������ ���϶�
			if (level == data.level)
			{
				return data.Maxexp;
			}
		}

		return -1; // -1��ȯ�ϸ� ������ �ν��϶�. cpp ����
	}

	void GetExp(int amount) //����ġ�� ȹ��. 
	{
		exp += amount;      // exp �� ��ġ��ŭ �� ���ش�.

		Maxexp = GetMaxExpForLevel(level);

		if (Maxexp == -1)
		{
			std::cout << "�ִ� ������ �����߽��ϴ�, ������ ����մϴ�" << std::endl;
			return; // ����ó�� �ڵ� �˸� �� �Լ�����.
		}

		if (exp >= Maxexp)  // "������ �ִ� ����ġ�� �������� ��"
		{
			level++;
			exp -= Maxexp;
		}
	}

	void Show() const
	{
		std::cout << "level : " << level << std::endl;
		std::cout << "Exp : " << exp << std::endl;
		std::cout << "Maxexp : " << Maxexp << std::endl;
	}

	void SaveData(const std::string& filename)
	{
		std::ofstream file(filename);
		if (file.is_open())
		{
			file << level << " " << exp << std::endl;
			file.close(); // close(); ȣ�� �ݵ��
		}
		//
	}
	void loadData(const std::string& filename)
	{
		std::ifstream file(filename);
		int _level, _exp, _maxExp;
		file >> _level >> _exp >> _maxExp;

		level = _level;
		exp = +exp;
	}
};

