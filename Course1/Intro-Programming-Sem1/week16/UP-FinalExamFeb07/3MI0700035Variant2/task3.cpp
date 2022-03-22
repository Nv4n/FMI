// P03-CountLettersAndNumbersBeforeBigLetter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int countLettersAndDigitsBeforeBigLetter(char* str);
int main()
{
	int size;
	do
	{
		std::cin >> size;
	} while (size < 1);
	char* str = new char[size + 1];

	std::cin.ignore();
	std::cin.getline(str, size);
	std::cout << countLettersAndDigitsBeforeBigLetter(str) << std::endl;
	delete[] str;
	return 0;
}

int countLettersAndDigitsBeforeBigLetter(char* str) {
	if (*str == '\0') {
		return 0;
	}
	bool isSymbolSmallLetterOrDigit = (*str >= 'a' && *str <= 'z') || (*str >= '0' && *str <= '9');
	bool isNextSymbolBigLetter = *(str + 1) >= 'A' && *(str + 1) <= 'Z';

	if (isSymbolSmallLetterOrDigit && isNextSymbolBigLetter) {
		return 1 + countLettersAndDigitsBeforeBigLetter(str + 1);
	}
	else {
		return countLettersAndDigitsBeforeBigLetter(str + 1);
	}
}