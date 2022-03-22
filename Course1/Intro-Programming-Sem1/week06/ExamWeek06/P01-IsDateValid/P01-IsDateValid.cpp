// P01-IsDateValid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int inputNumber;
	do
	{
		std::cin >> inputNumber;
	} while (inputNumber / 100000000 != 0);
	int year;
	int month;
	int day;

	year = inputNumber % 10000;
	inputNumber /= 10000;

	month = inputNumber % 100;
	inputNumber /= 100;

	day = inputNumber;

	if (day > 32) {
		std::cout << "NO" << std::endl;
	}
	else {
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			if (day <= 31) {
				std::cout << "YES" << std::endl;
			}
			else {
				std::cout << "NO" << std::endl;
			}
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11	:
		{
			if (day <= 30) {
				std::cout << "YES" << std::endl;
			}
			else {
				std::cout << "NO" << std::endl;
			}
			break;
		}
		case 2:
		{
			if (day <= 28) {
				std::cout << "YES" << std::endl;
			}
			else {
				std::cout << "NO" << std::endl;
			}
			break;
		}
		default:
			std::cout << "NO" << std::endl;
			break;
		}
	}
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
