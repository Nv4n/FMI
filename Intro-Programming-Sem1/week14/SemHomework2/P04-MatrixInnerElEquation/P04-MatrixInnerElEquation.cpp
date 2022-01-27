// P04-MatrixInnerElEquation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
bool areInnerMatrixElEqual(int** matrix, int size);
int main()
{
	int size;
	std::cin >> size;
	int** matrix = new int* [size];
	for (int row = 0; row < size; row++)
	{
		matrix[row] = new int[size];
		for (int col = 0; col < size; col++)
		{
			std::cin >> matrix[row][col];
		}
	}
	std::cout << std::boolalpha << areInnerMatrixElEqual(matrix, size) << std::endl;

	for (int row = 0; row < size; row++)
	{
		delete[] matrix[row];
	}
	delete[] matrix;
	return 0;
}

bool areInnerMatrixElEqual(int** matrix, int size) {
	for (int row1 = 0, row2 = size - 1; row1 < size / 2; row1++, row2--)
	{
		for (int col = row1 + 1; col < size - 1 - row1; col++)
		{
			if (matrix[row1][col] != matrix[row2][col])
			{
				return false;
			}
		}
	}

	for (int col1 = 0, col2 = size - 1; col1 < size / 2; col1++, col2--)
	{
		for (int row = col1 + 1; row < size - 1 - col1; row++)
		{
			if (matrix[row][col1] != matrix[row][col2])
			{
				return false;
			}
		}
	}

	return true;
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
