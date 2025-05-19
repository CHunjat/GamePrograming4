
#include "ConsoleUtility.h"
#include <iostream>

int main()
{

    while (true)
    {
        int random = ConsoleUtil::GetRandomInt(100);
        std::cout << random << std::endl;
        Sleep(100);
        break;
    }
    
    ConsoleUtil::GotoXY(0, 10);
    std::cout << "숫자" << std::endl;
    ConsoleUtil::GotoXY(10, 10);
    std::cout << "숫자" << std::endl;
}