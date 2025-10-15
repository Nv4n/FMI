// P07-PrintOutSymbolSquare.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::endl;

int main()
{
	//Задача 7

	//	По дадено число N изкарайте на екрана квадрат от N x N символи, където по главния диагонал стоят нули, над него + , а под него - .

	int squareSide;
	std::cout << "Input square's side: ";
	std::cin >> squareSide;

	for (int row = 0; row < squareSide; row++)
	{
		for (int column = 0; column < row; column++)
		{
			std::cout << "- ";
		}

		std::cout << "0 ";

		for (int column = row + 1; column < squareSide; column++)
		{
			std::cout << "+ ";
		}
		std::cout << endl;
	}
}
