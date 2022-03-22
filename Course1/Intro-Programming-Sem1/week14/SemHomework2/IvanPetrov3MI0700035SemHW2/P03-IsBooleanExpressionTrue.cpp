// P03-IsBooleanExpressionTrue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void printExpressionValidation(char* str);
void removeNonLogicSymbols(char* str);
bool isBooleanExpressionTrue(char* str);
int main()
{
	char* str = new char[100];
	std::cin >> str;
	printExpressionValidation(str);
	delete[] str;
	return 0;
}

void printExpressionValidation(char* str) {
	removeNonLogicSymbols(str);
	if (isBooleanExpressionTrue(str))
	{
		std::cout << "Boolean expression " << str << " valid!" << std::endl;
	}
	else
	{
		std::cout << "Boolean expression " << str << " is NOT valid!" << std::endl;
	}
}

bool isBooleanExpressionTrue(char* str) {
	if (*str == '\0')
	{
		if ((*(str - 1) == '0' || *(str - 1) == '1') && *(str - 2) == '='){
			return true;
		}
		else {
			return false;
		}
	}
	if ((*str == '0' || *str == '1') &&
		(*(str + 1) == '0' || *(str + 1) == '1'))
	{
		return false;
	}
	if ((*str == '&' || *str == '|') &&
		(*(str + 1) == '&' || *(str + 1) == '|'))
	{
		return false;
	}
	if (*str == '=' && *(str + 1) == '=') {
		return false;
	}

	isBooleanExpressionTrue(str + 1);
}
void removeNonLogicSymbols(char* str) {
	if (*str == '\0') {
		return;
	}
	if (*str != '0' && *str != '1' && *str != '&' && *str != '|' && *str != '=') {
		int i = 0;
		for (; str[i] != '\0'; i++)
		{
			str[i] = str[i + 1];
		}
		str[i - 1] = '\0';
		removeNonLogicSymbols(str);
	}

	removeNonLogicSymbols(str + 1);
}