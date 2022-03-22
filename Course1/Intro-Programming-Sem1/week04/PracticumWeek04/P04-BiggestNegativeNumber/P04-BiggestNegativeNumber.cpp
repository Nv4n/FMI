// P04-BiggestNegativeNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::endl;

int main()
{
	int count;
	std::cout << "Input how many numbers you want to input: ";
	std::cin >> count;
	int biggestNegativeNumber = 1;

	for (int i = 0; i < count; i++)
	{
		int inputNumber;
		std::cin >> inputNumber;
		if (inputNumber < 0 && (inputNumber > biggestNegativeNumber || biggestNegativeNumber > 0)) {
			biggestNegativeNumber = inputNumber;
		}
	}

	if (biggestNegativeNumber == 1) {
		std::cout << "No negative numbers were inputed!" << endl;
	}
	else {
		std::cout << "Biggest negative number is: " << biggestNegativeNumber << endl;
	}
}
