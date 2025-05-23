#pragma once
#include <iostream>
#include <vector>
#include <fstream>
/*
*  목표 : 레벨업 시스템 구현하고 싶다.
*  int exp; , int maxexp;  현재 경험치 > maxexp 레벨을 1올린다.
*/

/*
*  목표2 : 레벨에 따른 경험치 요구량을 자료구조로 표현하기!
*  vector< " " >
*/

/*
* 데이터를 표현하기 위한 클래스를 생성하세요 LevelExp
*  특정 클래스 안에 표현하기 위한 클래스의 자료구조로 선언하세요 Player-> std::vector<LevelExp> levelTable;
*/

/*
* 생성자에 데이터를 직접 작성한다.
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
			//  레벨과 table 레벨을 비교하라
			if (level == data.level)
			{
				return data.Maxexp;
			}
		}

		return -1; // -1반환하면 에러로 인식하라. cpp 에선
	}

	void GetExp(int amount) //경험치를 획득. 
	{
		exp += amount;      // exp 그 수치만큼 더 해준다.

		Maxexp = GetMaxExpForLevel(level);

		if (Maxexp == -1)
		{
			std::cout << "최대 레벨에 도달했습니다, 실행을 취소합니다" << std::endl;
			return; // 예외처리 코드 알림 후 함수종료.
		}

		if (exp >= Maxexp)  // "레벨의 최대 경험치에 도달했을 때"
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
			file.close(); // close(); 호출 반드시
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

