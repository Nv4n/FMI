// P01-PrintSquareSumNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>

int main()
{
	int startingNumber;
	int endingNumber;

	do
	{
		std::cout << "Enter the first number of the interval: ";
		std::cin >> startingNumber;
		std::cout << "Enter the last number of the interval: ";
		std::cin >> endingNumber;
	} while (startingNumber < 1 || endingNumber < 1);

	for (int currentNumber = startingNumber; currentNumber <= endingNumber; currentNumber++)
	{
		int numberSqrt = ceil(sqrt(currentNumber));
		//a^2 + b^2 = c^2   number = c^2

		for (int possible1stNumber = numberSqrt - 1; possible1stNumber >= 1; possible1stNumber--)
		{
			int squared2ndNumber = currentNumber - possible1stNumber * possible1stNumber;
			double sqrt2ndNumber = sqrt(squared2ndNumber);
			if ((int)sqrt2ndNumber == sqrt2ndNumber) {
				std::cout << currentNumber << " "
					<< "Numbers: " << possible1stNumber << " " << sqrt2ndNumber
					<< std::endl;
				break;
			}
		}
	}
}


//Даден е интервал[a, b].Да се напише програма, която извежда на конзолата, всички числа в
//интервала, които могат да се представят като сума от квадратите на две естествени числа.

//Interval [a,b]... Make program that prints out on the console, all numbers in the interval,
//which can be represented as sum of 2 squared natural numbers