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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
