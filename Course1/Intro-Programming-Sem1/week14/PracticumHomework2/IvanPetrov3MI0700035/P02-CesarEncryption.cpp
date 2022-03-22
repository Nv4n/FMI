// P02-CesarEncryption.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void encrypt(char* str, int offset);
int main()
{
	char str[256];
	std::cin >> str;
	int offset;
	std::cin >> offset;
	encrypt(str, offset % 26);
	std::cout << str << std::endl;
}
void encrypt(char* str, int offset) {
	if (*str == '\0') {
		return;
	}

	*str = *str - offset < 'A' ? *str - offset + 26 : *str - offset;
	encrypt(str + 1, offset);
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
