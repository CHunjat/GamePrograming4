#include "GameModel.h"
#include "DropTable.h"
#include "conio.h"
#include "DataHandler.h"

/*
*  경험치 테이블 만든다.
*  1레벨 - 100
*  2레벨 - 100
*  3레벨 - 100
*  4레벨 - 150
*  5레벨 - 150
*/

int main()
{
	Player player(0,100); // exp0 level 1 , maxepx 100
	Monster monster(0, 0);

	player.loadData("player.txt");

	Data data;
	data.SaveData("data.txt");
	data.loadData("data.txt");

	std::cout << "data의 level : " << data.level << "exp : " << data.exp << std:: endl;


	_getch();

	int count = 0;
	while (true)
	{
		system("cls");
		player.GetExp(30);
		player.Show();
		count++;
		_getch();
		if (count >= 10)
		{
			break;
		}

	}

	player.SaveData("player.txt");
}