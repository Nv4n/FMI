// P08-AreAllNumbersIncluded.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool isSymbolInArray(int number, int* arr, int size, int index = 0)
{
	if (index == size)
	{
		return false;
	}

	if (number == arr[index])
	{
		return true;
	}

	isSymbolInArray(number, arr, size, ++index);
}

bool areAllNumbersIncluded(int* arr1, int* arr2, int size1, int size2, int index = 0, bool flag = true) {
	if (index == size1) {
		return flag;
	}

	if (!isSymbolInArray(arr1[index], arr2, size2))
	{
		flag = false;
	}

	return areAllNumbersIncluded(arr1, arr2, size1, size2, ++index, flag);
}

int main()
{
	int size1;
	std::cin >> size1;
	int* arr1 = new int[size1];
	for (int i = 0; i < size1; i++)
	{
		std::cin >> arr1[i];
	}

	int size2;
	std::cin >> size2;
	int* arr2 = new int[size2];
	for (int i = 0; i < size2; i++)
	{
		std::cin >> arr2[i];
	}

	std::cout << (areAllNumbersIncluded(arr1, arr2, size1, size2) ? "YES" : "NO") << std::endl;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
