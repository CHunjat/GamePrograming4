/*
* enum �����ϼ���
* 
* class �ȿ� enum�� Ȱ���غ�����
*/

/*
* enum : ������
* enum ���� ����� ������ �� �ִ�.
*/

#include <vector>
#include <iostream>

enum Trait
{
	strenth,
	Dexterity,
	Inteligence,
	None // none�� �������� �ݵ�� 
};


enum Stat
{
	damage,
	Health,
	Mana,
	speed

};

/*
* trait - stat ���踦 �����ؾ� �Ѵ�.
* STR 1 �÷����� :  damage(���� ��ġ) + (  ); // �տ���
* Dex �ö��speed �ø��� �ý��� ����
* 
* �迭 ���·� ����Ǿ��ִ� �ڷᱸ���̱� ������, �ڷ��� ���� �� �߰��� �� �� �������̤� �߻��� �� �ִ�.
* ������� �����ȵ� �������� ������ �߻������� 
*/

/*
* vector Ÿ���� �Ѳ���.
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
* C������ Casting ������
*  - �������� ����ȯ�� ���ÿ� �� �� �ִ�.
* 
* CPP������ Casting 
*  - static_cast, const_cast, reimterpret_cast // dynamic_cast
*   
*  C���� �ǵ�ġ ���� ����ȯ�� �߻� �� �� �ִ�.
* 
* Tip) int, double, string, primitive Type Ÿ���� ��ȯ�ϰ� ������ static_cast���
* const_cast : ����� �����ִ� ����ȯ
* reinterpret_cast : �޸𸮿� �����Ͽ� int* -> double* ���ؼ��Ͽ� ��ȯ�ϴ� ��ȯ
* dynamic_cast : Ŭ������ ��Ӱ��踦 ����ȯ�Ͽ�, ���� �����Ͱ� �������� ������ null�� ��ȯ�Ѵ�.
* ex) if dynamic_cast<Monster> d)
*     {
*      }
* 
* 
*/

void EnumTest1()
{
	// enum�� ������, ������ enum���� ��ȯ�ϴ� �����Դϴ�.

	int num = Stat::damage;

	Stat someType = (Stat)num; // C��������� ����ȯ
	Stat someType2 = static_cast <Stat>(num);// C++������ ����ȯ

		if (someType == Stat::damage)
		{
			std::cout<<"����::�������� ��µǾ����ϴ�" << std::endl;
		}
}

//enum�� vector Ÿ������ ����ȯ�Ͽ� ����ϴ� ����
void EnumTest2()
{
	//Player player;
	//player.IncreatseStat(Stat::damage, 5); //�÷��̾��� ���ݷ� ������ 5��ƴ �������Ѷ�
}

void EnumTest3()
{
	TraitBonus traits;
	traits.GetTrait(Trait::strenth);
	traits.Showstat();

	//�÷��Ӿ��� Ư���� ���Ž�ų �� ����, Ư�� ���¤Ӥ��� �����ϰ� �Ϸ��� ��� �ڵ带 �ۼ�>?
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

	//�Է��� ����Ͽ� ������ �������Ѻ�����

	//ȭ����� : 1�� ������ strenth ������Ų�� 2�� ������ 3��������

	Player player;
	std::cout << " ============������============" << std::endl;

	int input;
	std::cout << "���� ����� �Է����� �� Ư���� A �ø��ϴ�." << std::endl;
	std::cin >> input;


	if (input >= Trait::None)
	{
		std::cout << "�߸��� ���ڸ� �Է��߽��ϴ�." << std::endl;
	}
	else
	{
		player.GetTraits(static_cast<Trait>(input));
	}
	player.ShowStatus();

}