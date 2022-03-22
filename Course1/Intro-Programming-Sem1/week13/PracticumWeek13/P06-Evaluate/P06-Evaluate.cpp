// P06-Evaluate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void countDigitsAndLetters(const char* str, int& digitsCount, int& smallLettersCount, int& bigLettersCount) {
	if (*str == '\0') {
		return;
	}

	if (*str >= 'a' && *str <= 'z') {
		smallLettersCount++;
	}
	else if (*str >= 'A' && *str <= 'Z') {
		bigLettersCount++;
	}
	else if (*str >= '0' && *str <= '9') {
		digitsCount++;
	}

	countDigitsAndLetters(str + 1, digitsCount, smallLettersCount, bigLettersCount);
}
void evaluate(const char* str) {
	int digitsCount = 0;
	int smallLettersCount = 0;
	int bigLettersCount = 0;
	countDigitsAndLetters(str, digitsCount, smallLettersCount, bigLettersCount);

	std::cout << "Broi malki bukvi: " << smallLettersCount
		<< "\nBroi golemi bukvi: " << bigLettersCount
		<< "\nBroig cifri: " << digitsCount << std::endl;
}


int main()
{
	char str[256];
	std::cin.getline(str, 256);
	evaluate(str);
}
//Задача 6
//Напишете рекурсивна функция с прототип void evaluate(const char*), която намира и изпечатва броят на малки и големи букви и броят на цифрите в даденият низ.
//
//Пример:
//
//evaluate("3 Doors Down")
//
//= &gt; Брой малки букви : 7
//
//Брой големи букви : 2
//
//Брой цифри : 1