#pragma once

// int array[100];
// 1. vector<int> vec;

// 2. template 간단한 코드로 구현해볼 것


// vector< > 여러분들이 직접 정의한 클래스를 한번 저장하고, 정렬하고, 출력하는 예제를 한번 만들어보세요.
// 은행 계좌 
// 게임에 데이터를 클래스로 표현.
// vector<<< >>>

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class PocketMonster
{
private:
	int _number;
	string _name;

public:
	PocketMonster(int number, string name)
		: _number(number), _name(name) {}

	int Get_Number() const
	{
		return _number;
	}

	string Get_Name() const
	{
		return _name;
	}

	bool operator<(const PocketMonster& other)
	{
		// this->_number : 자신의 도감 번호
		// other.Get_Number() : 비교 대상의 도감 번호

		return this->_number < other.Get_Number();

		//return this->_name.length() < other.Get_Name().length();
	}

	bool operator>(const PocketMonster& other)
	{
		return this->_number > other.Get_Number();
	}
	
	bool operator=(const PocketMonster& other)
	{
		return this->_number = other.Get_Number();
	}
};

// 15분.  

class Player
{
	vector<PocketMonster> myPocketmon;
};



void Example1()
{
	PocketMonster pica(25, "피카츄");
	PocketMonster 이상해씨(1, "이상해씨");
	PocketMonster 파이리(4, "파이리");
	PocketMonster 꼬부기(7, "꼬부기");
	PocketMonster 구구(16, "구구");
	PocketMonster 버터풀(25, "버터풀");

	//cout << "No." << pica.Get_Number() << " " << pica.Get_Name() << endl;

	if (버터풀 = pica)
	{
		cout << "같으면 출력" << endl;
	}

	cout << "이상해씨가 피카츄 보다 도감 번호가 큰가요?";
	if (pica < 이상해씨)
	{
		cout << "네" << endl;
	}
	else
	{
		cout << "아니요" << endl;
	}
	

	vector<PocketMonster> pocketDatabase;

	// 데이터 입력

	pocketDatabase.push_back(pica);
	pocketDatabase.push_back(이상해씨);
	pocketDatabase.push_back(파이리);
	pocketDatabase.push_back(꼬부기);
	pocketDatabase.push_back(구구);

	// 데이터 알고리즘 (정렬)
	sort(pocketDatabase.begin(), pocketDatabase.end());

	// 데이터 출력
	for (auto& pocketmon : pocketDatabase)
	{
		cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
	}

	// 데이터 찾기(검색)
	for (auto& pocketmon : pocketDatabase)
	{
		if (pocketmon.Get_Number() == 25)
		{
			cout << pocketmon.Get_Number() << "번 몬스터를 찾았다.";
			cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
		}
		else
		{
			cout << "못찾앗다";
			cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
		}

	}

}