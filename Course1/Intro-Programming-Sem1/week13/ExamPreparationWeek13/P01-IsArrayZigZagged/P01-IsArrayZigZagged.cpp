// P01-IsArrayZigZagged.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//1 3 2 4 3 7
bool isZigZag(int* arr, size_t length) {
	for (size_t i = 1; i < length; i++)
	{
		if (i % 2 == 0 && arr[i] >= arr[i - 1]) {
			return false;
		}
		else if (i % 2 != 0 && arr[i] <= arr[i - 1]) {
			return false;
		}
	}

	return true;
}

int main()
{
	int size;
	std::cin >> size;
	int* arr = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
	std::cout << std::boolalpha << isZigZag(arr, 6) << std::endl;
	delete[] arr;
}
