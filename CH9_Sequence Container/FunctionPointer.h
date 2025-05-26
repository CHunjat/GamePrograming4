#pragma once

#include <iostream>

/*
*  1단계.함수선언 (   반환값(*함수이름){} ) 
*  2단계.호출할 함수의 인자가 있는경우
   함수선언 (타입이름,타입이름),타입이름, 타입이름)
*/ 

void add(int a, int b)
{
	std::cout << "더하기 실행" << std::endl;
	std::cout << a + b << std::endl;
}

void minus(int a, int b)
{
	std::cout << "빼기 실행" << std::endl;
	std::cout << a - b << std::endl;

}
void multiply(int a, int b)
{
	std::cout << "곱하기 실행" << std::endl;
	std::cout << a * b << std::endl;
}
void divide (int a, int b)
{
	if (b == 0)
	{
		return;
	}

	std::cout << "나누기 실행" << std::endl;
	std::cout << a / b << std::endl;
}



void Calculate(void (*Func)(int a, int b), int a, int b)
{
	Func(a,b);
}

void Test()
{
	Calculate(minus, 150, 75);
	Calculate(add, 150, 75);
	Calculate(divide, 150, 75);
	Calculate(multiply, 150, 75);

}