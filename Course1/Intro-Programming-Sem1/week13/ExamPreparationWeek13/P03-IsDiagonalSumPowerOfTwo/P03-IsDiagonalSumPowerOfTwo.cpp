// P03-IsDiagonalSumPowerOfTwo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool isPowerOfTwo(int n) {

	if (n <= 0) return false;
	if (n % 2 != 0)return false;
	if (n == 2 || n == 1) return true;

	return isPowerOfTwo(n / 2);
}

int getSum(int** matrix, const size_t size) {
	int sum = 0;
	for (size_t i = 0, j = 0; i < size; i++, j++)
	{
		sum += matrix[i][j];
	}

	for (size_t i = 0, j = size - 1; i < size; i++, j--)
	{
		sum += matrix[i][j];
	}

	if (size % 2 != 0) {
		sum -= matrix[size / 2][size / 2];
	}

	return sum;
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
	int matrixSum = getSum(matrix, size);
	std::cout << matrixSum << " " << std::boolalpha << isPowerOfTwo(matrixSum) << std::endl;

	for (size_t i = 0; i < size; i++)
	{
		delete[]matrix[i];
	}

	delete[]matrix;
}

//Задача 3
//Да се напише програма, която въвежда квадратна матрица от цели числа с размер nxn(n също се въвежда от клавиатурата), след което намира сумата от елементите на главния и второстепенния диагонал(центърът да се брои само веднъж).Да се провери дали сумата е степен на двойката.Пример:
//
//Пример:
//Вход:
//3
//1 2 3
//4 5 6
//7 8 9
//Изход :
//	25 NO(обяснение : 1 + 5 + 9 + 3 + 7 = 25 = > не е степен на двойката)