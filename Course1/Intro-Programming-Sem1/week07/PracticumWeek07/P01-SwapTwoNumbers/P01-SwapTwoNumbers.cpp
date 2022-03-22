// P01-SwapTwoNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void swapNumbers(int &firstValue, int &secondValue) {
	int tempValue = firstValue;
	firstValue = secondValue;
	secondValue = tempValue;
}

int main()
{
	int firstNumber;
	int secondNumber;
	std::cin >> firstNumber >> secondNumber;
	swapNumbers(firstNumber, secondNumber);
	std::cout << firstNumber << " " << secondNumber << std::endl;
}