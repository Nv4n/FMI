// P02-FixMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void fixMatrix(int** matrix, int rowCount, int colCount);
void reverseCollumn(int** matrix, int rowCount, int colIndex);
void reverseDiagonals(int** matrix, int size);

int main()
{
	int rowCount;
	int colCount;
	do
	{
		std::cin >> rowCount >> colCount;
	} while (rowCount < 1 || colCount < 1);
	int** matrix = new int* [rowCount];

	for (int row = 0; row < rowCount; row++)
	{
		matrix[row] = new int[colCount];
		for (int col = 0; col < colCount; col++)
		{
			std::cin >> matrix[row][col];
		}
	}

	fixMatrix(matrix, rowCount, colCount);

	std::cout << std::endl;
	for (int row = 0; row < rowCount; row++)
	{
		for (int col = 0; col < colCount; col++)
		{
			std::cout << matrix[row][col] << " ";
		}
		std::cout << std::endl;
	}

	for (int row = 0; row < rowCount; row++)
	{
		delete[] matrix[row];
	}
	delete[] matrix;
	return 0;
}

void fixMatrix(int** matrix, int rowCount, int colCount) {
	for (int col = 0; col < colCount; col++)
	{
		int evenCount = 0;
		int oddCount = 0;
		for (int row = 0; row < rowCount; row++)
		{
			if (matrix[row][col] % 2 == 0) {
				evenCount++;
			}
			else {
				oddCount++;
			}
		}

		if (evenCount < oddCount)
		{
			reverseCollumn(matrix, rowCount, col);
		}
	}

	if (rowCount == colCount) {
		reverseDiagonals(matrix, rowCount);
	}
}

void reverseCollumn(int** matrix, int rowCount, int colIndex) {
	for (int row = 0; row < rowCount / 2; row++)
	{
		int helperNum = matrix[row][colIndex];
		matrix[row][colIndex] = matrix[rowCount - 1 - row][colIndex];
		matrix[rowCount - 1 - row][colIndex] = helperNum;
	}
}

void reverseDiagonals(int** matrix, int size) {
	for (int diagIndex = 0; diagIndex < size / 2; diagIndex++)
	{
		int helperNum = matrix[diagIndex][diagIndex];
		matrix[diagIndex][diagIndex] = matrix[size - 1 - diagIndex][size - 1 - diagIndex];
		matrix[size - 1 - diagIndex][size - 1 - diagIndex] = helperNum;
	}

	for (int row = 0, col = size - 1; row < size / 2; row++, col--)
	{
		int helperNum = matrix[row][col];
		matrix[row][col] = matrix[size - 1 - row][size - 1 - col];
		matrix[size - 1 - row][size - 1 - col] = helperNum;
	}
}