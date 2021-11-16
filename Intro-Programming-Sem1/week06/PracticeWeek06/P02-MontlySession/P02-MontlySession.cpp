// P02-MontlySession.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int year;
	std::cin >> year;
	int daysInFebruary = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 29 : 28;
	double grades = 0;
	for (int day = 1; day <= daysInFebruary; day++)
	{
		bool isItPrimeDay = true;
		for (int devider = 2; devider <= day / 2; devider++)
		{
			if (day % devider == 0) {
				isItPrimeDay = false;
				break;
			}
		}

		if (isItPrimeDay) {
			grades += 2;
		}
		else if (day % 2 == 0) {
			grades += 2.99;
		}
		else {
			grades += 3;
		}
	}

	grades += 1;//it counted 1st Feb as a Prime day
	std::cout << std::round(grades / daysInFebruary * 1000) / 1000.0 << std::endl;
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
