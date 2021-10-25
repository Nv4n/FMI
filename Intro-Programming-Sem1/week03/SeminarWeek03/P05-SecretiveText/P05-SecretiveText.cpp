// P05-SecretiveText.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::endl;

int main()
{
	char symbol;
	std::cout << "Input symbol: ";
	std::cin >> symbol;

	if (symbol >= 'a' && symbol <= 'z') {
		std::cout << symbol << " is an lowercase letter. It transforms in " << (char)(symbol - 32) << endl;
	}
	else if (symbol >= 'A' && symbol <= 'Z') {
		std::cout << symbol << " is an upppercase letter. It transforms in " << (char)(symbol + 32) << endl;
	}
	else if (symbol >= '0' && symbol <= '9') {
		std::cout << symbol << " is digit. " << symbol << " + 1 = " << symbol - '0' + 1 << endl;
	}
}
