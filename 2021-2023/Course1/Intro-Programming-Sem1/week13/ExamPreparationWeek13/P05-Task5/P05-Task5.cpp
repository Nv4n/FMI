// P05-Task5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

double recursiveMultiplication(double arr[], int length) {
	if (length <= 0) {
		return 1;
	}
	if (*arr > *(arr + 1) && *(arr + 1) > 0) {
		return *(arr + 1) * recursiveMultiplication(++arr, --length);
	}
	return recursiveMultiplication(++arr, --length);
}

int main()
{
	int size;
	std::cin >> size;
	double* arr = new double[size];
	for (size_t i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
	std::cout << recursiveMultiplication(arr, size - 1) << std::endl;

	delete[]arr;
}

//Задача 5
//Да се напише рекурсивна функция, която по даден масив от дробни числа намира произведението на всички положителни числа, които са по - малки от числото, стоящо вляво от тях(само ако има такова).Забележка: коректни, но нерекурсивни решения на зад. 3 ще носят много по - малко точки.удвоен.Пример :
//
//    Пример :
//    Вход :
//    8
//    2.1, 0, 9.9, 3, 1, -1, 14.5, 7
//    Изход :
//    21 (обяснение : -21 = 3 * 1 * (-1) * 7; пропускаме 2.1, тъй като вляво от него няма число)