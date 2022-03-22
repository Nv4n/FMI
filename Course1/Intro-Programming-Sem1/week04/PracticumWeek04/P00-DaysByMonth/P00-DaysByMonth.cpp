// P00-DaysByMonth.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::endl;

int main()
{
	int month;
	std::cout << "Input month: ";
	std::cin >> month;

	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		std::cout << "31 days" << endl;
		break;
	}
	case 4:
	case 6:
	case 9:
	case 11:
	{
		std::cout << "30 days" << endl;
		break;
	}
	case 2:
	{
		std::cout << "28 days" << endl;
	}
	default:
	{
		std::cout << "Month doesn't exist!" << endl;
	}
	}
}
