// P04-AsterixHistogram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int number;
	do
	{
		std::cout << "Vavedi chislo: ";
		std::cin >> number;
	} while (number < 1);


	while (number != 1)
	{
		int asterixLength = number / 10 + 1;
		for (int collumn = 0; collumn < asterixLength; collumn++)
		{
			std::cout << "*";
		}

		std::cout << number << std::endl;

		if (number % 2 == 0) {
			number /= 2;
		}
		else {
			number = number * 3 + 1;
		}
	}
	std::cout << "*1" << std::endl;
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
