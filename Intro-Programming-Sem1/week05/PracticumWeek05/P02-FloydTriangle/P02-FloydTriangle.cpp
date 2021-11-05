// P02-FloydTriangle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int rowCount;
	std::cout << "Input the rows count: ";
	std::cin >> rowCount;
	for (int row = 0, number = 1; row < rowCount; row++)
	{
		for (int collumn = 0; collumn <= row; collumn++, number++)
		{
			std::cout << number << " ";
		}
		std::cout << std::endl;
	}
}

//Задача 2
//Създайте триъгълник на Флойд.Входни данни : Брой на редове
//
//
//Пример : редове = 4