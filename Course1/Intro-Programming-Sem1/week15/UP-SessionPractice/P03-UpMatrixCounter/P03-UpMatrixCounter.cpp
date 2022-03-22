// P03-UpMatrixCounter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int rowCount;
	int colCount;
	do
	{
		std::cin >> rowCount;
		std::cin >> colCount;
	} while (rowCount < 1 || colCount < 1 || rowCount > 10 || colCount > 10);

	char** matrix = new char* [rowCount];
	for (int row = 0; row < rowCount; row++)
	{
		matrix[row] = new char[colCount];
		for (int col = 0; col < colCount; col++)
		{
			std::cin >> matrix[row][col];
		}
	}

	int count = 0;
	for (int row = 0; row < rowCount; row++)
	{
		for (int col = 0; col < colCount; col++)
		{
			if (matrix[row][col] == 'u')
			{
				if (col < colCount - 1 && matrix[row][col + 1] == 'p')
				{
					count++;
				}
				if (row < rowCount - 1 && matrix[row + 1][col] == 'p')
				{
					count++;
				}
			}
		}
	}

	std::cout << count << std::endl;
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
