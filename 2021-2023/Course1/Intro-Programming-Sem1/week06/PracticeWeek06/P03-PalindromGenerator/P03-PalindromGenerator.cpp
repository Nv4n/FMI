// P03-PalindromGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int smallestDigit;
	std::cin >> smallestDigit;
	int secondDigit;
	std::cin >> secondDigit;
	int largestDigit;
	std::cin >> largestDigit;

	if (secondDigit < smallestDigit && secondDigit != 0) {
		int tempNumber = smallestDigit;
		smallestDigit = secondDigit;
		secondDigit = tempNumber;
	}
	if (largestDigit < smallestDigit && largestDigit != 0) {
		int tempNumber = smallestDigit;
		smallestDigit = largestDigit;
		largestDigit = tempNumber;
	}
	if (largestDigit < secondDigit) {
		int tempNumber = secondDigit;
		secondDigit = largestDigit;
		largestDigit = tempNumber;
	}

	if (smallestDigit == secondDigit) {
		if (smallestDigit == 0) {
			if (largestDigit == 0) {
				std::cout << 0;
			}
			else {
				std::cout << largestDigit << smallestDigit << secondDigit << largestDigit;
			}
		}
		else {
			std::cout << smallestDigit << largestDigit << secondDigit;
		}
	}
	else {
		if (smallestDigit == 0) {
			std::cout << secondDigit << smallestDigit << largestDigit << smallestDigit << secondDigit;
		}
		else {
			std::cout << smallestDigit << secondDigit << largestDigit << secondDigit << smallestDigit;
		}
	}

	std::cout << std::endl;
}