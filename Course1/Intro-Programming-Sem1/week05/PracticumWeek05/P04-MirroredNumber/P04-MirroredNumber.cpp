// P04-MirroredNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int number;
	std::cout << "Input number: ";
	std::cin >> number;
	bool isNumberEven = number % 2;

	int mirroredNum = 0;
	while (number != 0)
	{
		mirroredNum = mirroredNum * 10 + number % 10;
		number /= 10;
	}

	bool isMirroredNumberEven = mirroredNum % 2;
	if (isNumberEven == isMirroredNumberEven) {
		std::cout << mirroredNum << " - YES!" << std::endl;
	}
	else {
		std::cout << mirroredNum << " - NO!" << std::endl;
	}
}
