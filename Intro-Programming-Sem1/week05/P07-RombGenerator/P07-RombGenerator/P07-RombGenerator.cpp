// P07-RombGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::endl;

int main()
{
	int largestRow;
	std::cout << "Input the largest row's number: ";
	std::cin >> largestRow;

	for (int row = 0; row < largestRow; row++)
	{
		for (int collumn = 0; collumn < largestRow - row; collumn++)
		{
			std::cout << " ";
		}
		for (int collumn = 0; collumn <= row * 2; collumn++)
		{
			std::cout << "*";
		}
		std::cout << endl;
	}

	for (int row = largestRow ; row >= 0; row--)
	{
		for (int collumn = largestRow - row; collumn > 0; collumn--)
		{
			std::cout << " ";
		}
		for (int collumn = 0; collumn <= row * 2; collumn++)
		{
			std::cout << "*";
		}
		std::cout << endl;
	}
}

//Задача 7
//Направете следния диамант : Входни данни - цяло число показващо броя на редовете до най - широкия от страна на символи ред.Пример : Вход - 5
