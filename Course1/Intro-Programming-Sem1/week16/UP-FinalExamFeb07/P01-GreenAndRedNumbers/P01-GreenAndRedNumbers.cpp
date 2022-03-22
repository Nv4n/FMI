// P01-GreenAndRedNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

bool isNumberRed(int number);
bool isNumberGreen(int number);
bool areThereAnyGreenOrRedNumber(int startNumber, int endNumber);
int main()
{
	int startNumber;
	int endNumber;
	do
	{
		std::cin >> startNumber >> endNumber;
	} while (startNumber > endNumber);
	std::cout << (areThereAnyGreenOrRedNumber(startNumber, endNumber) ? "YES" : "NO") << std::endl;
	return 0;
}

bool areThereAnyGreenOrRedNumber(int startNumber, int endNumber) {
	for (int num = startNumber; num <= endNumber; num++)
	{
		if (isNumberRed(num) || isNumberGreen(num)) {
			return true;
		}
	}

	return false;
}

bool isNumberRed(int number) {
	int sum = 0;
	int helperNum = number;
	while (helperNum != 0)
	{
		sum += (helperNum % 10);
		helperNum /= 10;
	}

	if (number % sum == 0) {
		return true;
	}
	return false;
}

bool isNumberGreen(int number) {
	int sum = 0;
	int helperNum = number;
	while (helperNum != 0)
	{
		sum += (std::pow(helperNum % 10, 3));
		helperNum /= 10;
	}

	if (sum == number)
	{
		return true;
	}
	return false;
}