// P04-PrintFunc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void print(int arr[], int size, char splitter = ' ');
void printReverse(int arr[], int size, char splitter = ' ');

int main()
{
	int size;
	std::cin >> size;
	int* arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	print(arr, size);
	printReverse(arr, size, '_');
}

void print(int arr[], int size, char splitter) {
	for (int i = 0; i < size; i++)
	{
		std::cout << *(arr + i) << splitter;
	}
	std::cout << std::endl;
}
void printReverse(int arr[], int size, char splitter) {
	for (int i = size - 1; i >= 0; i--)
	{
		std::cout << *(arr + i) << splitter;
	}
	std::cout << std::endl;
}

//Задача 3
//Напишете функция с прототип void print(int[], int), която изпечатва масив от цели числа, без да използва оператора[]:
//
//Отпред назад
//Отзад напред
