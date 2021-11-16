// P04-DeviderCount.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int startingNumber;
	int endingNumber;
	int devidersNeeded;
	do
	{
		std::cin >> startingNumber;
		std::cin >> endingNumber;
		std::cin >> devidersNeeded;
	} while (startingNumber < 0 && endingNumber < 0 && devidersNeeded < 0);


	for (int number = startingNumber; number <= endingNumber; number++)
	{
		int deviderCount = 2;
		for (int devider = 2; devider <= number / 2; devider++)
		{
			if (number % devider == 0) {
				deviderCount++;
			}
		}
		if (deviderCount < devidersNeeded) {
			std::cout << "NO" << std::endl;
			return 0;
		}
	}

	std::cout << "YES" << std::endl;
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
