// P04-Meeting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::endl;

int main()
{
	int year;
	std::cout << "Input an year: ";
	std::cin >> year;

	if (year % 400 == 0 || year % 4 == 0) {
		std::cout << "There will be meeting!" << endl;
	}
	else {
		std::cout << "There won't be meeting this year!" << endl;
	}
}