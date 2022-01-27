// P03-NumberToArr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int numberLength(int n) {
	if (n == 0) {
		return 0;
	}

	return 1 + numberLength(n / 10);
}
void helper(char* str, int number, int index) {
	if (number == 0) {
		return;
	}
	str[index] = number % 10;

	helper(str, number / 10, index - 1);
}

char* convert(int number) {
	int length = numberLength(number);
	char* str = new char[length + 1];
	helper(str, number, length - 1);
	return;
}

int main()
{

}

//3.Да се реализира функция, която приема число, която конвертира в символен низ и връща указател към първия елемент на масива.