// P01-SpecialNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::endl;

int main()
{
	/*Задача 1

		Да се напише програма, която въвежда от клавиатурата многоцифрено число n.Програмата да проверява дали произведението от цифрите му е трицифрено число.Ако произведението от цифрите му е трицифрено число, да извежда YES и разликата от произведението и сбора на цифрите му, в противен случай NO и произведението от цифрите му.

		Примерен вход : 369 Примерен изход : YES 144

		Примерен вход : 123 Примерен изход : NO 6*/

	int number;
	std::cout << "Input multi digit number: ";
	std::cin >> number;
	int digitsMultiplication = 1, digitsSum = 0;
	for (; number != 0; number /= 10)
	{
		int digit = number % 10;
		digitsMultiplication *= digit;
		digitsSum += digit;
	}

	if (digitsMultiplication >= 100) {
		std::cout << "YES " << digitsMultiplication - digitsSum << endl;
	}
	else {
		std::cout << "NO " << digitsMultiplication << endl;
	}
}