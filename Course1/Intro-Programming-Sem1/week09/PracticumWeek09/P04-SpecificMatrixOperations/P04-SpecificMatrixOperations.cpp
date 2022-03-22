// P04-SpecificMatrixOperations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void sum2Matrix(int** matrixA, int** matrixB, int size);
void specialSum2Matrix(int** matrixA, int** matrixB, const int size);
int main()
{
	int size;
	std::cin >> size;
	int** matrixA = new int* [size];
	for (int row = 0; row < size; row++)
	{
		matrixA[row] = new int[size];
		for (int collumn = 0; collumn < size; collumn++)
		{
			std::cin >> matrixA[row][collumn];
		}
	}

	int** matrixB = new int* [size];
	for (int row = 0; row < size; row++)
	{
		matrixB[row] = new int[size];
		for (int collumn = 0; collumn < size; collumn++)
		{
			std::cin >> matrixB[row][collumn];
		}
	}

	sum2Matrix(matrixA, matrixB, size);
	specialSum2Matrix(matrixA, matrixB, size);
}

void sum2Matrix(int** matrixA, int** matrixB, const int size) {
	int** resultMatrix = new int* [size];

	for (int row = 0; row < size; row++)
	{
		resultMatrix[row] = new int[size];
		for (int collumn = 0; collumn < size; collumn++)
		{
			resultMatrix[row][collumn] = matrixA[row][collumn] + matrixB[row][collumn];
		}
	}

	for (int row = 0; row < size; row++)
	{
		for (int collumn = 0; collumn < size; collumn++)
		{
			std::cout << resultMatrix[row][collumn] << " ";
		}
		std::cout << std::endl;
	}
}

void specialSum2Matrix(int** matrixA, int** matrixB, const int size) {
	int** resultMatrix = new int* [size];

	for (int row = 0; row < size; row++)
	{
		resultMatrix[row] = new int[size];
		for (int collumn = 0; collumn < size; collumn++)
		{
			resultMatrix[row][collumn] = 2 * matrixA[row][collumn] + 3 * matrixB[row][collumn];
		}
	}

	for (int row = 0; row < size; row++)
	{
		for (int collumn = 0; collumn < size; collumn++)
		{
			std::cout << resultMatrix[row][collumn] << " ";
		}
		std::cout << std::endl;
	}
}
//4 задача
//След въвеждането на 2 квадратни матрици А и B с еднакъв размер нека се изведат на конзолата следната нова матрица
//
//А + B
//
//- (A)
//
//2A + 3B