#pragma once

/*
* 데이터 저장. 
* 1단계 플레이어의 레벨과 경험치
* 2단계 데이터를 자료구조 형태로 저장.
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

		// file 열어라.
		if (file.is_open())
		{
			file << level << " " << exp << std::endl;
			file.close(); // close(); 호출 반드시
		}
		// 메모장에 exp와 level을 저장해라.
		
	}

	void loadData(const std::string& filename)
	{
		std::ifstream file(filename);

		int _exp, _level; //파일에서 불러오는거

		file >> _level >> _exp;

		level = _level;
		exp = _exp;
	}
};