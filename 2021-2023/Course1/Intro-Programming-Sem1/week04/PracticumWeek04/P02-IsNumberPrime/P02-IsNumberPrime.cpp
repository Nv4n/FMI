// IsNumberPrime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::endl;

int main()
{
	/*Задача 2

		По дадено естествено число определете дали то е просто.*/
	int number;
	std::cout << "Input a number: ";
	std::cin >> number;

	for (int i = 2; i <= number / 2; i++)
	{
		if (number % i == 0) {
			std::cout << "Not a prime number!" << endl;
			return 0;
		}
	}

	std::cout << "It's a prime number!" << endl;
}
