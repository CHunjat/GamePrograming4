#pragma once
#include "ConsoleUtility.h"
#include <iostream>

// 복습 계산기 기능. 함수 포인터로 표현하기

#pragma region 심화. 함수 포인터에 일반화 프로그래밍 Generic Programing 적용


template <typename T>
void plus(T a, T b)
{
	std::cout << "더 하기기 결과 : ";
	std::cout << a + b << std::endl;
}
template <typename T>
void minus(T a, T b)
{
	std::cout << "빼기 결과 : ";
	std::cout << a - b << std::endl;
}

template <typename T>
void Multiply(T a, T b)
{
	std::cout << "곱하기 결과 : ";
	std::cout << a * b << std::endl;
}

template <typename T>
void devide(T a, T b)
{

	if (b == 0)
	{
		return;
	}
	std::cout << "나누기 결과 : ";
	std::cout << a / b << std::endl;
}


template <typename T>
void calculate(void (*Func)(T a, T b), T outa, T outb)
{
	Func(outa, outb);
}
#pragma endregion

#pragma region 심화(2). 열거형과 클래스로 함수포인터 사용

class Actor
{
private:
	static void Move()
	{
		std::cout << "움직입니다" << std::endl;

	}

	static void Talk()
	{
		std::cout << "말합니다" << std::endl;
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
#pragma region 가위바위보 예제
	enum RSP_TYPE
	{
		ROCK,SCISSORS,PAPER
	};

	class RSPgame
	{
		
		//함수 포인터 선언
		void(*Action)();

		static void Rock()
		{
			std::cout << "바위" << std::endl;
		}
		static void Scissors()
		{
			std::cout << "가위" << std::endl;
		}
		static void Paper()
		{
			std::cout << "보" << std::endl;
		}
		RSP_TYPE computer;
		RSP_TYPE player; 

		int userScore;
		int computerscore;

		// switch(RSP_TYPE) 각타입에 맞게 함수포인터의 함수를 넣는 코드를 만들어보세요
		
		void Result()
		{
			//유저, 컴퓨터 같다 :비김

			//유저 > 컴퓨터 :이김

			//그게 아니면 졌다.
			if (player == computer)
			{
				std::cout << "비겼다" << std::endl;
			}
			else if (player == ROCK && computer == SCISSORS ||
				player == SCISSORS && computer == PAPER ||
				player == PAPER && computer == ROCK)
			{
				std::cout << "이겼다" << std::endl;
				userScore++;
			}
			else
			{
				std::cout << "졌다" << std::endl;
				computerscore++;
			}
		}


	public:

		RSPgame() : userScore(0), computerscore(0) {}
		void startGame()
		{
			while (true)
			{
				std::cout << "0 : 바위, 1: 가위, 2 : 보" << std::endl;
				std::cout << "선택해주세여" << std::endl;
				int input = 0;
				std::cin >> input;
				player = static_cast<RSP_TYPE>(input);

				//컴퓨터가 선택할 번호를 랜덤으로 받습니다.
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
				// 함수포인터의 함수를 실행
				std::cout << "컴퓨터가 선택한 행동 : " << " ";
				Action();
				Result();

				if (userScore >= 3 || computerscore >= 3)
				{
					break;
				}
			}

			if (userScore >= 3)
			{
				std::cout << "유저가 이겼습니다" << std::endl;
			
			}
			else if (computerscore >= 3)
			{
				std::cout << "컴퓨터가 이겼습니다 " << std::endl;
			} 
		}
	};


#pragma endregion

	void Think()
	{
		int select = ConsoleUtil::GetRandomInt(2);
		// 랜덤한 숫자를 받아서, 0이나오면 움직여라
			switch (select-1)
			{
			case 0:Action = Move;
				break;
			case 1:Action = Talk;
				break;
			default:
				std::cout << " 잘못된 입력을 받아왔습니다 << std::endl";

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