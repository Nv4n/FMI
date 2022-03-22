// P02-ReturnPointerToArrElemenet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int* findElementInMatrix(int arr[], int size, int elementToFind);

int main()
{
	int size;
	std::cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	int elementToFind;
	std::cin >> elementToFind;

	std::cout << findElementInMatrix(arr, size, elementToFind) << std::endl;
	std::cout << *findElementInMatrix(arr, size, elementToFind) << std::endl;
}

int* findElementInMatrix(int arr[], int size, int elementToFind) {
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == elementToFind)
		{
			return &arr[i];
		}
	}
	return nullptr;
}

//Задача 1
//Напишете функция, която по подаден масив и елемент от същия тип като елементите на масива намира първото му срещане в масива и връща указател към него.Ако елементът не е намерен да върне null pointer.