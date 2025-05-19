/*
* 데이터를 저장하는 클래스
* T value. pointer
*/




#include<iostream>
#include "CustomVector.h"
#include "RandomEncounter.h"
#include "conio.h"
int main()
{
	//test1();
	test2();

	Player player;

	while (true)
	{
		system("cls");
		Battle(player);
		player.display();
		std::cout << "키를 입력하면 다음 전투가 진행됩니다." << std::endl;
		_getch();
		
	}
}