// v1task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void rotateMatrix(int** matrix, int size, int turns);
void printRotatedMatrix(int** matrix, int size);
int main()
{
	int size;
	do
	{
		std::cin >> size;
	} while (size < 1 || size>20);
	int** matrix = new int* [size];
	for (int row = 0; row < size; row++)
	{
		matrix[row] = new int[size];
		for (int col = 0; col < size; col++)
		{
			std::cin >> matrix[row][col];
		}
	}

	int degrees;
	do
	{
		std::cin >> degrees;
	} while (degrees == 0 || degrees % 90 != 0);
	int turns = (degrees % 360) / 90;
	if (turns < 0)
	{
		turns = 4 + turns;
	}

	rotateMatrix(matrix, size, turns);
	for (int i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void rotateMatrix(int** matrix, int size, int turns) {
	int** tempMatrix = new int* [size];
	for (int row = 0; row < size; row++)
	{
		tempMatrix[row] = new int[size];
	}

	switch (turns)
	{
	case 1:
	{
		for (int resultCol = size - 1, row = 0; resultCol >= 0; resultCol--, row++)
		{
			for (int resultRow = 0, col = 0; resultRow < size; resultRow++, col++)
			{
				tempMatrix[resultRow][resultCol] = matrix[row][col];
			}
		}
		break;
	}
	case 2:
	{
		for (int resultRow = size - 1, row = 0; resultRow >= 0; resultRow--, row++)
		{
			for (int resultCol = size - 1, col = 0; resultCol >= 0; resultCol--, col++)
			{
				tempMatrix[resultRow][resultCol] = matrix[row][col];
			}
		}
		break;
	}
	case 3:
		for (int resultCol = 0, row = 0; resultCol < size; resultCol++, row++)
		{
			for (int resultRow = size - 1, col = 0; resultRow >= 0; resultRow--, col++)
			{
				tempMatrix[resultRow][resultCol] = matrix[row][col];
			}
		}
		break;
	}

	printRotatedMatrix(tempMatrix, size);

	for (int i = 0; i < size; i++)
	{
		delete[] tempMatrix[i];
	}
	delete[] tempMatrix;
}

void printRotatedMatrix(int** matrix, int size) {

	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			std::cout << matrix[row][col] << " ";
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
