// P03-SumOfNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::endl;

int main()
{
	/*Задача 3

		От клавиатурата се въвеждат произволен брой числа.Намерете сбора на всички числа до въвеждането на 0.*/
	std::cout << "Input numbers, program stops when you input 0: " << endl;
	int sum = 0;

	for (int inputNumber = 1; inputNumber != 0; std::cin >> inputNumber)
	{
		sum += inputNumber;
	}

	std::cout << sum - 1 << endl;
}