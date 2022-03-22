// P07-PrintNumbersWithPrimeDividers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool isNumberPrime(int number) {
	for (int divider = 2; divider <= number / 2; divider++)
	{
		if (number % divider == 0) {
			return 0;
		}
	}
	return 1;
}

void printNumbersWithPrimeDividers(int startNum, int endNum, int dividerCount) {
	for (int number = startNum; number <= endNum; number++)
	{
		int primeDividerCount = 0;
		if (isNumberPrime(number)) {
			primeDividerCount = 1;
		}
		else {
			for (int divider = 2; divider <= number / 2; divider++)
			{
				if (number % divider == 0 && isNumberPrime(divider)) {
					primeDividerCount++;
				}
			}
		}

		if (primeDividerCount == dividerCount) {
			std::cout << number << " ";
		}
	}

	std::cout << std::endl;
}

int main()
{
	int startNum;
	int endNum;
	int dividerCount;
	std::cin >> startNum >> endNum >> dividerCount;
	printNumbersWithPrimeDividers(startNum, endNum, dividerCount);
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
