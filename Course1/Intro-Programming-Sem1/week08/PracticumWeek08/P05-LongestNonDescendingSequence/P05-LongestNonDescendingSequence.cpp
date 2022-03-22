// P05-LongestNonDescendingSequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int arrLength;
	do
	{
		std::cin >> arrLength;
	} while (arrLength < 1 && arrLength>100);

	int numbersArray[100];
	for (int i = 0; i < arrLength; i++)
	{
		std::cin >> numbersArray[i];
	}

	int count = 1;
	int longestSequenceCount = 0;
	for (int i = 0; i < arrLength - 1; i++)
	{
		if (numbersArray[i] <= numbersArray[i + 1]) {
			count++;
		}
		else if (longestSequenceCount < count) {
			longestSequenceCount = count;
			count = 1;
		}
	}

	if (count>longestSequenceCount)
	{
		longestSequenceCount = count;
	}

	std::cout << longestSequenceCount << std::endl;
}

//Да се напише програма, която извежда дължината на най - дългата последователност от ненамаляващи числа.Пример:
//
//Sequence length : 10
//Input sequence : 1 2 3 - 5 11 23 47 9 1 0
//Longest sequence : 4