/*
* �����͸� �����ϴ� Ŭ����
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
		std::cout << "Ű�� �Է��ϸ� ���� ������ ����˴ϴ�." << std::endl;
		_getch();
		
	}
}