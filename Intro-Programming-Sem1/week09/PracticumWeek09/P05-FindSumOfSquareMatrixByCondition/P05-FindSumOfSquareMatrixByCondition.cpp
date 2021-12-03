// P05-FindSumOfSquareMatrixByCondition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void sumEveryRow(int** matrix, int size);
void sumEveryColumn(int** matrix, int size);
void sumMainDiagonal(int** matrix, int size);
void sumSecondDiagonal(int** matrix, int size);
void sumUnderMainDiagonal(int** matrix, int size);
void sumAboveMainDiagonal(int** matrix, int size);

int main()
{
	int size;
	std::cin >> size;
	int** matrix = new int* [size];
	for (int row = 0; row < size; row++)
	{
		matrix[row] = new int[size];
		for (int collumn = 0; collumn < size; collumn++)
		{
			std::cin >> matrix[row][collumn];
		}
	}

	sumEveryRow(matrix, size);
	sumEveryColumn(matrix, size);
	sumMainDiagonal(matrix, size);
	sumSecondDiagonal(matrix, size);
	sumUnderMainDiagonal(matrix, size);
	sumAboveMainDiagonal(matrix, size);
}
void sumEveryRow(int** matrix, int size) {
	for (int row = 0; row < size; row++)
	{
		int sum = 0;
		for (int collumn = 0; collumn < size; collumn++)
		{
			sum += matrix[row][collumn];
		}
		std::cout << "Sum of Row[" << row << "]: " << sum << std::endl;
	}
}
void sumEveryColumn(int** matrix, int size) {
	for (int collumn = 0; collumn < size; collumn++)
	{
		int sum = 0;
		for (int row = 0; row < size; row++)
		{
			sum += matrix[row][collumn];
		}
		std::cout << "Sum of Collumn[" << collumn << "]: " << sum << std::endl;
	}
}

void sumMainDiagonal(int** matrix, int size) {
	int sum = 0;
	for (int row = 0; row < size; row++)
	{
		sum += matrix[row][row];
	}

	std::cout << "Sum main diagonal: " << sum << std::endl;
}
void sumSecondDiagonal(int** matrix, int size) {
	int sum = 0;
	for (int row = 0, collumn = size - 1; row < size; row++, collumn--)
	{
		sum += matrix[row][collumn];
	}

	std::cout << "Sum second diagonal: " << sum << std::endl;
}
void sumUnderMainDiagonal(int** matrix, int size) {
	int sum = 0;
	for (int row = 0; row < size; row++)
	{
		for (int collumn = 0; collumn < row; collumn++)
		{
			sum += matrix[row][collumn];
		}
	}
	std::cout << "Sum under the main diagonal: " << sum << std::endl;
}
void sumAboveMainDiagonal(int** matrix, int size) {
	int sum = 0;
	for (int row = 0; row < size; row++)
	{
		for (int collumn = row + 1; collumn < size; collumn++)
		{
			sum += matrix[row][collumn];
		}
	}
	std::cout << "Sum above the main diagonal: " << sum << std::endl;
}

//5 задача
//Програмата да намира и извежда сумата от елементите на квадратна матрица на :
//
//всеки ред
//всеки стълб
//главния диагонал
//под главния диагонал
//над главния диагонал
//вторичния диагонал