// P02-IsTheMatrixSymetric.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
bool isSymmetrical(int** matrix, const size_t n) {
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (matrix[i][j] != matrix[j][i]) {
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int size;
	std::cin >> size;
	int** matrix = new int* [size];

	for (size_t i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
		for (size_t j = 0; j < size; j++)
		{
			std::cin >> matrix[i][j];
		}
	}

	std::cout <<std::boolalpha<< isSymmetrical(matrix, size);

	for (size_t i = 0; i < size; i++)
	{
		delete[]matrix[i];
	}

	delete[]matrix;
}

//Задача 2
//Въведете квадратна матрица с големина n ^ 2, проверете дали въведената матрица е симетрична.Симетрична означава, че елементите на позиции(i, j) и(j, i) са еднакви.Пример:
//
//Пример:
//Вход:
//3
//4 - 5 2
//- 5 0 1
//2 1 8
//Изход :
//    YES
//    Вход :
//4
//1 2 3 4
//5 6 7 8
//9 0 0 0
//3 2 1 - 1
//Изход :
//    NO