// P00-AvgArrElements.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int arrLength;
	std::cin >> arrLength;
	int* numberArr = new int[arrLength];
	for (int i = 0; i < arrLength; i++)
	{
		std::cin >> numberArr[i];
	}

	int sum = 0;
	for (int i = 0; i < arrLength; i++)
	{
		sum += numberArr[i];
	}

	std::cout << 1.0 * sum / arrLength << std::endl;
}