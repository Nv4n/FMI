// P01-IncreaseTheMatrixBy10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int rowCount;
	int collumnCount;
	std::cin >> rowCount >> collumnCount;

	int** matrix = new int* [rowCount];
	for (int row = 0; row < rowCount; row++)
	{
		matrix[row] = new int[collumnCount];
		for (int collumn = 0; collumn < collumnCount; collumn++)
		{
			std::cin >> matrix[row][collumn];
		}
	}

	for (int row = 0; row < rowCount; row++)
	{
		for (int collumn = 0; collumn < collumnCount; collumn++)
		{
			std::cout << matrix[row][collumn] + 10 << " ";
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
