// P03-RemoveElementFromArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void removeNumberFromTheArray(int numArr[], int arrLength, int numToFind);
int main()
{
	int arrLength;
	std::cin >> arrLength;
	//int* numArr = new int[arrLength];
	int numArr[1000];

	for (int i = 0; i < arrLength; i++)
	{
		std::cin >> numArr[i];
	}

	int numToFind;
	std::cin >> numToFind;
	removeNumberFromTheArray(numArr, arrLength, numToFind);

}

void removeNumberFromTheArray(int numArr[], int arrLength, int numToFind) {

	for (int i = 0; i < arrLength; i++)
	{
		if (numToFind == numArr[i])
		{
			for (int currentIndex = i; currentIndex < arrLength - 1; currentIndex++)
			{
				numArr[currentIndex] = numArr[currentIndex + 1];

			}
			arrLength--;
			i--;
		}
	}

	for (int i = 0; i < arrLength; i++)
	{
		std::cout << numArr[i] << " ";
	}
	std::cout << std::endl;
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

void removeNumberFromTheArray()
{
}
