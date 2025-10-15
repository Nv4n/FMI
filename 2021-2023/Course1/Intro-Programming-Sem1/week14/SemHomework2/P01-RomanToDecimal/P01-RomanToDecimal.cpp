// P01-RomanToDecimal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int letterToValue(char r);
int romanToDecimal(char* str);
bool romanNumberValidation(char* str);

int main()
{
	bool flag = false;
	char str[14];
	int decimalNumber = 0;
	do
	{
		std::cin >> str;
		flag = romanNumberValidation(str);
	} while (flag);

	std::cout << romanToDecimal(str) << std::endl;
	return 0;
}

int romanToDecimal(char* str)
{
	int result = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		int currentLetterValue = letterToValue(str[i]);

		if (str[i + 1] != '\0')
		{
			int nextLetterValue = letterToValue(str[i + 1]);

			if (currentLetterValue >= nextLetterValue)
			{
				result += currentLetterValue;
			}
			else
			{
				result += (nextLetterValue - currentLetterValue);
				i++;
			}
		}
		else {
			result += currentLetterValue;
		}
	}
	return result;
}

int letterToValue(char letter)
{
	switch (letter) {
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	default:
		return -1;
	}
}

bool romanNumberValidation(char* str) {
	int lettersCount['Z' - 'A' + 1];
	for (int i = 0; i < 26; i++)
	{
		lettersCount[i] = 0;
	}

	if (str[1] == 'M' && str[0] == 'M')
	{
		return true;
	}

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != 'I' &&
			str[i] != 'V' &&
			str[i] != 'X' &&
			str[i] != 'L' &&
			str[i] != 'C' &&
			str[i] != 'D' &&
			str[i] != 'M')
		{
			return true;
		}
		lettersCount[str[i] - 'A']++;
	}

	if (lettersCount['M' - 'A'] > 1 ||
		lettersCount['D' - 'A'] > 1 ||
		lettersCount['C' - 'A'] > 3 ||
		lettersCount['L' - 'A'] > 1 ||
		lettersCount['X' - 'A'] > 3 ||
		lettersCount['V' - 'A'] > 1 ||
		lettersCount['I' - 'A'] > 3)
	{
		return true;
	}

	if ((str[11] == 'I' ||
		str[11] == 'V' ||
		str[11] == 'X' ||
		str[11] == 'L' ||
		str[11] == 'C' ||
		str[11] == 'D' ||
		str[11] == 'M') &&
		str[12] != '\0') {
		return true;
	}

	return false;
}
//DCCCLXXXVIII

//I		1
//IV	4
//V		5
//IX	9
//X		10
//XL	40
//L		50
//XC	90
//C		100
//CD	400
//D		500
//CM	900
//M		1000