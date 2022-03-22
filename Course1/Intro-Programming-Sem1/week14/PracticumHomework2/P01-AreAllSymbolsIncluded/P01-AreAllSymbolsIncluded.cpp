// P01-AreAllSymbolsIncluded.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
bool isSymbolInArray(char symbol, char* str) {
	if (*str == '\0')
	{
		return false;
	}
	if (symbol == *str) {
		return true;
	}
	return isSymbolInArray(symbol, str + 1);
}
bool areAllSymbolsIncluded(char* str1, char* str2, bool* unCheckedSymbols) {
	if (*str1 == '\0') {
		return true;
	}

	if (unCheckedSymbols[*str1] && !isSymbolInArray(*str1, str2))
	{
		return false;
	}

	unCheckedSymbols[*str1] = false;
	return areAllSymbolsIncluded(str1 + 1, str2, unCheckedSymbols);
}

int main()
{
	char str1[256];
	std::cin >> str1;
	char str2[256];
	std::cin >> str2;
	bool unCheckedSymbols[256];
	std::cout << (areAllSymbolsIncluded(str1, str2, unCheckedSymbols) ? "YES" : "NO") << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
