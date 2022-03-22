// P06-OperationsWithMatrixes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void sum2Matrixes(int matrixA[][3], int matrixB[][3]);
void substract2Matrixes(int matrixA[][3], int matrixB[][3]);
void multiply2Matrixes(int matrixA[][3], int matrixB[][3]);
void findDetOfMatrix(int matrix[][3]);

int main()
{
	int matrixA[3][3];
	int matrixB[3][3];
	for (int row = 0; row < 3; row++)
	{
		for (int collumn = 0; collumn < 3; collumn++)
		{
			std::cin >> matrixA[row][collumn];
		}
	}

	for (int row = 0; row < 3; row++)
	{
		for (int collumn = 0; collumn < 3; collumn++)
		{
			std::cin >> matrixB[row][collumn];
		}
	}
	sum2Matrixes(matrixA, matrixB);
	substract2Matrixes(matrixA, matrixB);
	multiply2Matrixes(matrixA, matrixB);
	findDetOfMatrix(matrixA);
}

void sum2Matrixes(int matrixA[][3], int matrixB[][3]) {
	int resultMatrix[3][3];
	for (int row = 0; row < 3; row++)
	{
		for (int collumn = 0; collumn < 3; collumn++)
		{
			resultMatrix[row][collumn] = matrixA[row][collumn] + matrixB[row][collumn];
		}
	}

	for (int row = 0; row < 3; row++)
	{
		for (int collumn = 0; collumn < 3; collumn++)
		{
			std::cout << resultMatrix[row][collumn] << " ";
		}
		std::cout << std::endl;
	}
}
void substract2Matrixes(int matrixA[][3], int matrixB[][3]) {
	int resultMatrix[3][3];
	for (int row = 0; row < 3; row++)
	{
		for (int collumn = 0; collumn < 3; collumn++)
		{
			resultMatrix[row][collumn] = matrixA[row][collumn] - matrixB[row][collumn];
		}
	}

	for (int row = 0; row < 3; row++)
	{
		for (int collumn = 0; collumn < 3; collumn++)
		{
			std::cout << resultMatrix[row][collumn] << " ";
		}
		std::cout << std::endl;
	}
}
void multiply2Matrixes(int matrixA[][3], int matrixB[][3]) {
	int resultMatrix[3][3];
	for (int row = 0; row < 3; row++)
	{
		for (int collumn = 0; collumn < 3; collumn++)
		{
			resultMatrix[row][collumn] = 0;
			for (int i = 0; i < 3; i++)
			{
				resultMatrix[row][collumn] += matrixA[row][i] * matrixB[i][row];
			}
		}
	}

	for (int row = 0; row < 3; row++)
	{
		for (int collumn = 0; collumn < 3; collumn++)
		{
			std::cout << resultMatrix[row][collumn] << " ";
		}
		std::cout << std::endl;
	}
}
void findDetOfMatrix(int matrix[][3]) {
	std::cout << matrix[0][0] * matrix[1][1] * matrix[2][2]
		+ matrix[1][0] * matrix[2][1] * matrix[0][2]
		+ matrix[0][1] * matrix[1][2] * matrix[2][0]
		- matrix[0][2] * matrix[1][1] * matrix[2][0]
		- matrix[0][1] * matrix[1][0] * matrix[2][2]
		- matrix[1][2] * matrix[2][1] * matrix[0][0] << std::endl;

	/*
	a b c
	d e f
	g h i
	*/
}