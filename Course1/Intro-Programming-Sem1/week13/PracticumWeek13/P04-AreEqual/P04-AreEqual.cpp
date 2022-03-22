// P04-AreEqual.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
bool areEqual(const char* str1, const char* str2);
int main()
{
	char string1[100];
	char string2[100];
	std::cin >> string1 >> string2;
	std::cout << std::boolalpha << areEqual(string1, string2);
}
bool areEqual(const char* str1, const char* str2) {
	if (*str1 == '\0' && *str2 == '\0') {
		return 1;
	}
	else {
		return 0;
	}
	return areEqual(str1 + 1, str2 + 1);
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
