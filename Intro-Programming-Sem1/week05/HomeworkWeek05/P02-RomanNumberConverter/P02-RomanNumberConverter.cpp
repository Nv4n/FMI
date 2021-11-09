// P02-RomanNumberConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int input;
	std::cout << "Vavedi chislo po-malko ili ravno na 1000: ";
	std::cin >> input;
	int thousands = input / 1000;;
	int hundreds = input % 1000 / 100;;
	int tens = input % 100 / 10;
	int ones = input % 10;

	if (thousands == 1)
	{
		std::cout << "M";
	}

	if (hundreds == 9) {
		std::cout << "CM";
		hundreds -= 9;
	}
	else if (hundreds >= 5)
	{
		std::cout << "D";
		hundreds -= 5;
	}
	else if (hundreds == 4) {
		std::cout << "CD";
		hundreds -= 4;
	}
	for (int hundredsCount = 0; hundredsCount < hundreds; hundredsCount++)
	{
		std::cout << "C";
	}

	if (tens == 9) {
		std::cout << "XC";
		tens -= 9;
	}
	else if (tens == 4) {
		std::cout << "XL";
		tens -= 4;
	}
	else if (tens >= 5)
	{
		std::cout << "L";
		tens -= 5;
	}
	for (int tensCount = 0; tensCount < tens; tensCount++)
	{
		std::cout << "X";
	}

	if (ones == 9) {
		std::cout << "IX";
		ones -= 9;
	}
	else if (ones == 4) {
		std::cout << "IV";
		ones -= 4;
	}
	else if (ones >= 5)
	{
		std::cout << "V";
		ones -= 5;
	}
	for (int onesCount = 0; onesCount < ones; onesCount++)
	{
		std::cout << "I";
	}

}