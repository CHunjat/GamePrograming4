#pragma once

#include <iostream>

/*
*  1�ܰ�.�Լ����� (   ��ȯ��(*�Լ��̸�){} ) 
*  2�ܰ�.ȣ���� �Լ��� ���ڰ� �ִ°��
   �Լ����� (Ÿ���̸�,Ÿ���̸�),Ÿ���̸�, Ÿ���̸�)
*/ 

void add(int a, int b)
{
	std::cout << "���ϱ� ����" << std::endl;
	std::cout << a + b << std::endl;
}

void minus(int a, int b)
{
	std::cout << "���� ����" << std::endl;
	std::cout << a - b << std::endl;

}
void multiply(int a, int b)
{
	std::cout << "���ϱ� ����" << std::endl;
	std::cout << a * b << std::endl;
}
void divide (int a, int b)
{
	if (b == 0)
	{
		return;
	}

	std::cout << "������ ����" << std::endl;
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