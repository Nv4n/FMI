// P01-SwapNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void swapNumber(int& firstNumber, int& secondNumber);

int main()
{
	int firstNumber;
	int secondNumber;
	std::cin >> firstNumber >> secondNumber;
	swapNumber(firstNumber, secondNumber);
	std::cout << firstNumber << " " << secondNumber << std::endl;
}

void swapNumber(int& firstNumber, int& secondNumber) {
	int tempNum = firstNumber;
	firstNumber = secondNumber;
	secondNumber = tempNum;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
