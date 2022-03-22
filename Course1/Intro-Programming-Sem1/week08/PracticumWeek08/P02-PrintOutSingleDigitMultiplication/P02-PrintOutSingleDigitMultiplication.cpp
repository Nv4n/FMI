// P02-PrintOutSingleDigitMultiplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool isDigitsMultiplicationSingleDigit(int number) {
	int multiplication = 1;
	while (number != 0)
	{
		multiplication *= number % 10;
		number /= 10;
	}
	return multiplication >= 0 && multiplication <= 9;
}

int getSpecialNumbersCount(int* numArr, int arrLength) {
	int count = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (isDigitsMultiplicationSingleDigit(numArr[i])) {
			count++;
		}
	}

	return count;
}

int main()
{
	int arrLength;
	std::cin >> arrLength;
	int* numArray = new int[arrLength];

	for (int i = 0; i < arrLength; i++)
	{
		std::cin >> numArray[i];
	}

	std::cout << getSpecialNumbersCount(numArray, arrLength) << std::endl;
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
