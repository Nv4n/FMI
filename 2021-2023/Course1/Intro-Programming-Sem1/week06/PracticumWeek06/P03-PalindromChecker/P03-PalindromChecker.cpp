// P03-PalindromChecker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int number;
	std::cin >> number;
	int mirroredNumber = 0;
	for (int tempNumber = number; tempNumber != 0;)
	{
		mirroredNumber = mirroredNumber * 10 + tempNumber % 10;
		tempNumber /= 10;
	}

	if (number == mirroredNumber) {
		std::cout << "YES" << std::endl;
	}
	else {
		std::cout << "NO" << std::endl;
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
