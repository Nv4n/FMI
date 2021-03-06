// P03-InversionsCount.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int arrLength;
	int numbersArray[1000];

	do
	{
		std::cin >> arrLength;
	} while (arrLength < 2 && arrLength > 1000);

	for (int i = 0; i < arrLength; i++)
	{
		std::cin >> numbersArray[i];
	}

	int inversionsCount = 0;
	for (int i = 0; i < arrLength - 1; i++)
	{
		for (int j = i + 1; j < arrLength; j++)
		{
			if (numbersArray[i] > numbersArray[j])
			{
				inversionsCount++;
			}
		}
	}

	std::cout << inversionsCount << std::endl;
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
