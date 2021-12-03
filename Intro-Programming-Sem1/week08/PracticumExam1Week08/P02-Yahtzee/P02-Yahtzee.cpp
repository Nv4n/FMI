// P02-Yahtzee.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int throwDie();
bool areThere3SameNumbers(int diceResults[]);
int getTriesCount();

int main()
{
	srand(time(NULL));
	std::cout << getTriesCount() << std::endl;
}

int getTriesCount() {
	int diceResults[5];
	int sequenceLength = 0;
	int triesCount = 0;

	while (sequenceLength != 3)
	{
		for (int i = 0; i < 5; i++)
		{
			diceResults[i] = throwDie();
		}

		triesCount++;
		if (areThere3SameNumbers(diceResults)) {
			sequenceLength++;
		}
		else {
			sequenceLength = 0;
		}
	}

	return triesCount;
}

bool areThere3SameNumbers(int diceResults[]) {
	int maxSameNumCount = 0;
	int sameNumCount = 0;

	for (int numToCheck = 1; numToCheck <= 6; numToCheck++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (diceResults[i] == numToCheck) {
				sameNumCount++;
			}
		}

		if (maxSameNumCount < sameNumCount) {
			maxSameNumCount = sameNumCount;
		}
		if (maxSameNumCount >= 3)
		{
			break;
		}

		sameNumCount = 0;
	}

	return maxSameNumCount >= 3;
}

int throwDie() {
	return rand() % 6 + 1;
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
