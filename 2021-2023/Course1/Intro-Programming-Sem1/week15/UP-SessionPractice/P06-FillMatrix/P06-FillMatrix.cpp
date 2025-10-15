// P06-FillMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void fillMatrix(int** matrix, int size);

int main()
{
	int size;
	std::cin >> size;
	int** matrix = new int* [size];
	for (int row = 0; row < size; row++)
	{
		matrix[row] = new int[size];
	}

	fillMatrix(matrix, size);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;

}

void fillMatrix(int** matrix, int size) {
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			if (row == col)
			{
				matrix[row][col] = row;
			}
			else if (row > col)
			{
				matrix[row][col] = row * col;
			}
			else
			{
				matrix[row][col] = col - row;
			}
		}
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
