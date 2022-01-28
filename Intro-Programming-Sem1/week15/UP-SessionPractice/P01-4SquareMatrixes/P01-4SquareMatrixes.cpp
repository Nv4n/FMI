// P01-4SquareMatrixes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
bool areDiagonalSumEqual(int** matrix, int size);
int main()
{
	int size;
	do
	{
		std::cin >> size;
	} while (size < 3);
	int** matrix = new int* [size];
	for (int row = 0; row < size; row++)
	{
		matrix[row] = new int[size];
		for (int col = 0; col < size; col++)
		{
			std::cin >> matrix[row][col];
		}
	}

	std::cout << std::boolalpha << areDiagonalSumEqual(matrix, size) << std::endl;

	for (int i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

bool areDiagonalSumEqual(int** matrix, int size) {
	int index = 0;
	int sums[] = { 0,0,0,0 };
	for (int row = 0, col = 0; row < size + 1; row++, col++)
	{
		if (col == size && row == size)
		{
			break;
		}
		if (row == size)
		{
			row = size / 2;
			index++;
			continue;
		}
		if (col == size) {
			index++;
			col = -1;
			continue;
		}
		if (col == size / 2) {
			index++;
			row = -1;
			continue;
		}
		sums[index] += matrix[row][col];
	}

	if (sums[0] == sums[1] &&
		sums[2] == sums[3] &&
		sums[0] == sums[2])
	{
		return true;
	}
	return false;
}
