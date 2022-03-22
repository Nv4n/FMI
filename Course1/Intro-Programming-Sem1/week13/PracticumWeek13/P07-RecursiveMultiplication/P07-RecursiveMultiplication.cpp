// P07-RecursiveMultiplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int mult(int m, int n) {
	if (n == 1) {
		return m;
	}

	return m + mult(m, n - 1);
}

int main()
{
	int m, n;
	std::cin >> m >> n;
	std::cout << mult(m, n) << std::endl;
}

//Задача 7
//Произведението на две положителни цели числа може да се дефинира по следния начин :
//
//mult(m, n) = m, ако n = 1
//
//mult(m, n) = m + mult(m, n − 1), иначе.