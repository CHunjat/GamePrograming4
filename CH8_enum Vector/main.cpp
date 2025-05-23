/*
* enum 선언하세요
* 
* class 안에 enum을 활용해보세요
*/

/*
* enum : 열거형
* enum 으로 상수를 저장할 수 있다.
*/

#include <vector>
#include <iostream>

enum Trait
{
	strenth,
	Dexterity,
	Inteligence,
	None // none은 마지막에 반드시 
};


enum Stat
{
	damage,
	Health,
	Mana,
	speed

};

/*
* trait - stat 관계를 정의해야 한다.
* STR 1 올렸을때 :  damage(기존 수치) + (  ); // 합연산
* Dex 올라ㅣspeed 올리는 시스템 구현
* 
* 배열 형태로 저장되어있는 자료구조이기 때문에, 자료의 삭제 및 추가를 할 때 문제점이ㅏ 발생할 수 있다.
* 순서대로 정리안된 데이터의 변경이 발생했을때 
*/

/*
* vector 타입의 한꼐점.
* stat,traG
*/

class TraitBonus
{
private:
	void IncreaseStat(Stat stat, int amount)
{
	stats[static_cast<int>(stat)] += amount;
}

public:
	std::vector<int> stats;

	TraitBonus() : stats(4, 0) {}

	void GetTrait(Trait trait)
	{
		switch (trait)
		{
		case Trait::strenth:
			IncreaseStat(damage, 5);
			IncreaseStat(Health, 1);
			break;
		case Trait::Dexterity:
			IncreaseStat(speed, 1);
			break;
		case Trait::Inteligence:
			IncreaseStat(Mana, 5);
			break;
		}
	}

	void Showstat()
	{
		std::cout << "Damage : " << stats[damage] << std::endl;
		std::cout << "Health : " << stats[Health] << std::endl;
		std::cout << "Mana   : " << stats[Mana] << std::endl;
		std::cout << "Speed   : " << stats[speed] << std::endl;
	}
};


class Player
{
private:
	TraitBonus traitbonus;
public:
	Player() :traitbonus() {}

	TraitBonus GetTraits() const { return traitbonus; }

	void GetTraits(Trait trait)
	{
		traitbonus.GetTrait(trait);
	}

	void ShowStatus()
	{
		traitbonus.Showstat();
	}
};

/*
* C형태의 Casting 문제점
*  - 여러가지 형변환을 동시에 할 수 있다.
* 
* CPP형태의 Casting 
*  - static_cast, const_cast, reimterpret_cast // dynamic_cast
*   
*  C언어는 의도치 않은 형변환이 발생 할 수 있다.
* 
* Tip) int, double, string, primitive Type 타입을 변환하고 싶으면 static_cast사용
* const_cast : 상수를 없애주는 형변환
* reinterpret_cast : 메모리에 접근하여 int* -> double* 재해석하여 변환하는 변환
* dynamic_cast : 클래스의 상속관계를 형변환하여, 실제 데이터가 존재하지 않으면 null을 반환한다.
* ex) if dynamic_cast<Monster> d)
*     {
*      }
* 
* 
*/

void EnumTest1()
{
	// enum을 정수로, 정수를 enum으로 변환하는 예제입니다.

	int num = Stat::damage;

	Stat someType = (Stat)num; // C언어형태의 형변환
	Stat someType2 = static_cast <Stat>(num);// C++형태의 형변환

		if (someType == Stat::damage)
		{
			std::cout<<"스탯::데미지가 출력되었습니다" << std::endl;
		}
}

//enum을 vector 타입으로 형변환하여 사용하는 예제
void EnumTest2()
{
	//Player player;
	//player.IncreatseStat(Stat::damage, 5); //플레이어의 공격력 스탯을 5만틈 증가시켜라
}

void EnumTest3()
{
	TraitBonus traits;
	traits.GetTrait(Trait::strenth);
	traits.Showstat();

	//플레ㅣ어의 특성을 증거시킬 걸 증가, 특정 스태ㅣㅅ을 증가하게 하려면 어떠한 코드를 작성>?
}

void EnumTest4()
{
	Player player;
	//player.GetTraits().GetTrait(Trait::strenth);
	//player.GetTraits().Showstat();*/

	player.GetTraits(Trait::strenth);
	player.ShowStatus();

}


int main()
{
	//EnumTest1();
	//EnumTest2();
	//EnumTest3();
	//EnumTest4();

	//입려을 사용하여 스탯을 증가시켜보세요

	//화면출력 : 1을 누르면 strenth 증가시킨다 2를 누르면 3을누르면

	Player player;
	std::cout << " ============레벨업============" << std::endl;

	int input;
	std::cout << "숫자 몇번을 입력했을 때 특성을 A 올립니다." << std::endl;
	std::cin >> input;


	if (input >= Trait::None)
	{
		std::cout << "잘못된 숫자를 입력했습니다." << std::endl;
	}
	else
	{
		player.GetTraits(static_cast<Trait>(input));
	}
	player.ShowStatus();

}