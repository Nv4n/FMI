// P08-IsDateValid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

bool isDateValid(int day, int month, int year) {
	if (day > 32) {
		return 0;
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
				return 1;
			}
			else {
				return 0;
			}
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11:
		{
			if (day <= 30) {
				return 1;
			}
			else {
				return 0;
			}
			break;
		}
		case 2:
		{
			if (day <= 28) {
				return 1;
			}
			else {
				return 0;
			}
			break;
		}
		default:
			return 0;
			break;
		}
	}
}

int main()
{
	int day;
	int month;
	int year;
	std::cin >> day >> month >> year;
	std::cout << std::boolalpha << isDateValid(day, month, year) << std::endl;
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
