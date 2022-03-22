// P02-BullsAndCows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>

int* generateSecretNumber();
int getUserInput();
void countBullsAndCows(int& bulls, int& cows, int* secretNumber, int* inputNumber);

int main()
{
	int* secretNumber = generateSecretNumber();
	while (true)
	{
		int inputNumber = getUserInput();
		int inputNumberArr[4] = {
			inputNumber / 1000, //1st digit
			inputNumber % 1000 / 100, //2nd digit
			inputNumber % 100 / 10, //3rd digit
			inputNumber % 10 }; //4th digit

		int bulls = 0;
		int cows = 0;
		countBullsAndCows(bulls, cows, secretNumber, inputNumberArr);

		if (bulls == 4) {
			std::cout << "Congratulations you guessed the number!" << std::endl;
			return 0;
		}
		else {
			std::cout << "Bulls: " << bulls << " Cows: " << cows << std::endl;
		}
	}

}
int getUserInput() {
	int input;
	do
	{
		std::cout << "Enter your guess: ";
		std::cin >> input;
	} while (input < 1234 || input > 9876);

	return input;
}

void countBullsAndCows(int& bulls, int& cows, int* secretNumber, int* inputNumber) {
	for (int secretNumIndex = 0; secretNumIndex < 4; secretNumIndex++)
	{
		for (int inputNumIndex = 0; inputNumIndex < 4; inputNumIndex++)
		{
			//std::cout << secretNumber[secretNumIndex] << " " << inputNumber[inputNumIndex] << std::endl;
			if (secretNumber[secretNumIndex] == inputNumber[inputNumIndex]) {
				secretNumIndex == inputNumIndex ? bulls++ : cows++;
				break;
			}
		}
	}
}

int* generateSecretNumber() {
	srand(time(0));
	int digits[9] = { 1,2,3,4,5,6,7,8,9 };
	static int secretNumber[4];
	for (int secretNumIndex = 0; secretNumIndex < 4; secretNumIndex++)
	{
		int digitIndex;
		do
		{
			digitIndex = rand() % 9;
		} while (digits[digitIndex] == 0);
		secretNumber[secretNumIndex] = digits[digitIndex];
		digits[digitIndex] = 0;
	}

	return secretNumber;
}