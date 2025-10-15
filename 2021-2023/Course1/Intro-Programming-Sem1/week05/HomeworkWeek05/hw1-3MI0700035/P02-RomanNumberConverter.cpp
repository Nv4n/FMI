// P02-RomanNumberConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int decimalNumber;
	do
	{
		std::cout << "Vavedi chislo ot 1 do 1000: ";
		std::cin >> decimalNumber;
	} while (decimalNumber < 1 || decimalNumber > 1000);

	int thousands = decimalNumber / 1000;;
	int hundreds = decimalNumber % 1000 / 100;;
	int tens = decimalNumber % 100 / 10;
	int ones = decimalNumber % 10;

	//Thousands
	if (thousands == 1)
	{
		std::cout << "M";
	}

	//Printing the special cases before printing other symbols
	//Hundreds
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

	//Tens
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

	//Ones
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