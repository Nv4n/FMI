// P01-PrintOutNumAfterOperations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void printOutChangedNumber(int number, int multiplicationNumber);
int returnReversedChangedNumber(int number, int multiplicationNumber);

int main()
{
	int inputNumber, multiplicationNumber;
	do
	{
		std::cin >> inputNumber >> multiplicationNumber;
	} while (multiplicationNumber < 0 || multiplicationNumber > 9);

	printOutChangedNumber(inputNumber, multiplicationNumber);
}

void printOutChangedNumber(int number, int multiplicationNumber) {
	int reversedChangedNumber = returnReversedChangedNumber(number, multiplicationNumber);
	while (reversedChangedNumber != 0)
	{
		std::cout << reversedChangedNumber % 10;
		reversedChangedNumber /= 10;
	}
}

int returnReversedChangedNumber(int number, int multiplicationNumber) {

	int reversedResultNumber = 0;
	while (number != 0)
	{
		int multiplication = (number % 10) * multiplicationNumber;
		if (multiplication > 9) {
			multiplication /= 10;
		}

		reversedResultNumber = reversedResultNumber * 10 + multiplication;
		number /= 10;
	}

	return reversedResultNumber;
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
