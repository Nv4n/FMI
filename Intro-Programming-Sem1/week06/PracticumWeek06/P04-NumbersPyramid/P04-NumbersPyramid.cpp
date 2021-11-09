// P04-NumbersPyramid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int maxNumber;
	std::cin >> maxNumber;
	for (int row = 1; row <= maxNumber; row++)
	{
		for (int collumn = 1; collumn <= maxNumber; collumn++)
		{
			if (row > collumn) {
				std::cout << " ";
			}
			else {
				std::cout << collumn;
			}
		}
		std::cout << std::endl;
	}
	for (int row = maxNumber-1; row >= 1; row--)
	{
		for (int collumn = 1; collumn <= maxNumber; collumn++)
		{
			if (row > collumn) {
				std::cout << " ";
			}
			else {
				std::cout << collumn;
			}
		}
		std::cout << std::endl;
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
