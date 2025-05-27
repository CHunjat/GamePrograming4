#pragma once
#include "ConsoleUtility.h"
#include <iostream>

// ���� ���� ���. �Լ� �����ͷ� ǥ���ϱ�

#pragma region ��ȭ. �Լ� �����Ϳ� �Ϲ�ȭ ���α׷��� Generic Programing ����


template <typename T>
void plus(T a, T b)
{
	std::cout << "�� �ϱ�� ��� : ";
	std::cout << a + b << std::endl;
}
template <typename T>
void minus(T a, T b)
{
	std::cout << "���� ��� : ";
	std::cout << a - b << std::endl;
}

template <typename T>
void Multiply(T a, T b)
{
	std::cout << "���ϱ� ��� : ";
	std::cout << a * b << std::endl;
}

template <typename T>
void devide(T a, T b)
{

	if (b == 0)
	{
		return;
	}
	std::cout << "������ ��� : ";
	std::cout << a / b << std::endl;
}


template <typename T>
void calculate(void (*Func)(T a, T b), T outa, T outb)
{
	Func(outa, outb);
}
#pragma endregion

#pragma region ��ȭ(2). �������� Ŭ������ �Լ������� ���

class Actor
{
private:
	static void Move()
	{
		std::cout << "�����Դϴ�" << std::endl;

	}

	static void Talk()
	{
		std::cout << "���մϴ�" << std::endl;
	}

public:
	Actor() = default;

	void (*Action)();

	void ActionMove()
	{
		Action = Move;
	}
	void ActionTalk()
	{
		Action = Talk;

	}
#pragma region ���������� ����
	enum RSP_TYPE
	{
		ROCK,SCISSORS,PAPER
	};

	class RSPgame
	{
		
		//�Լ� ������ ����
		void(*Action)();

		static void Rock()
		{
			std::cout << "����" << std::endl;
		}
		static void Scissors()
		{
			std::cout << "����" << std::endl;
		}
		static void Paper()
		{
			std::cout << "��" << std::endl;
		}
		RSP_TYPE computer;
		RSP_TYPE player; 

		int userScore;
		int computerscore;

		// switch(RSP_TYPE) ��Ÿ�Կ� �°� �Լ��������� �Լ��� �ִ� �ڵ带 ��������
		
		void Result()
		{
			//����, ��ǻ�� ���� :���

			//���� > ��ǻ�� :�̱�

			//�װ� �ƴϸ� ����.
			if (player == computer)
			{
				std::cout << "����" << std::endl;
			}
			else if (player == ROCK && computer == SCISSORS ||
				player == SCISSORS && computer == PAPER ||
				player == PAPER && computer == ROCK)
			{
				std::cout << "�̰��" << std::endl;
				userScore++;
			}
			else
			{
				std::cout << "����" << std::endl;
				computerscore++;
			}
		}


	public:

		RSPgame() : userScore(0), computerscore(0) {}
		void startGame()
		{
			while (true)
			{
				std::cout << "0 : ����, 1: ����, 2 : ��" << std::endl;
				std::cout << "�������ּ���" << std::endl;
				int input = 0;
				std::cin >> input;
				player = static_cast<RSP_TYPE>(input);

				//��ǻ�Ͱ� ������ ��ȣ�� �������� �޽��ϴ�.
				int select = ConsoleUtil::GetRandomInt(3); //1,2,3
				computer = static_cast<RSP_TYPE>(select - 1);

				switch (computer)
				{
				case ROCK:Action = Rock;
					break;
				case SCISSORS:Action = Scissors;
					break;
				case PAPER:Action = Paper;
					break;
				}
				// �Լ��������� �Լ��� ����
				std::cout << "��ǻ�Ͱ� ������ �ൿ : " << " ";
				Action();
				Result();

				if (userScore >= 3 || computerscore >= 3)
				{
					break;
				}
			}

			if (userScore >= 3)
			{
				std::cout << "������ �̰���ϴ�" << std::endl;
			
			}
			else if (computerscore >= 3)
			{
				std::cout << "��ǻ�Ͱ� �̰���ϴ� " << std::endl;
			} 
		}
	};


#pragma endregion

	void Think()
	{
		int select = ConsoleUtil::GetRandomInt(2);
		// ������ ���ڸ� �޾Ƽ�, 0�̳����� ��������
			switch (select-1)
			{
			case 0:Action = Move;
				break;
			case 1:Action = Talk;
				break;
			default:
				std::cout << " �߸��� �Է��� �޾ƿԽ��ϴ� << std::endl";

			}
	}
};

#pragma endregion
	void FPtest()
	{
		calculate(plus, 5, 6);
		calculate(plus, 5.2, 6.6);
		calculate(minus, 1.1, 6.2);
		calculate(devide, 1.1, 6.2);
		calculate(Multiply, 1.1, 6.2);
	}
	void FPTest2()
	{
		Actor actor;
		actor.Think();
		actor.Action();
	}