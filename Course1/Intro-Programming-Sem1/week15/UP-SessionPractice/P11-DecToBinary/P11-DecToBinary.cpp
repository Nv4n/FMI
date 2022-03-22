// P11-DecToBinary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
char* returnReversedBinaryNumber(char* str, int size) {
	for (int firstEl = 0, secondEl = size - 1; firstEl < size / 2; firstEl++, secondEl--)
	{
		char helper = str[secondEl];
		str[secondEl] = str[firstEl];
		str[firstEl] = helper;
	}
	return str;
}
char* returnDecToBinaryNumber(int number, char str[255], int length = 0) {
	if (number / 2 == 0)
	{
		str[length] = '1';
		length++;
		return returnReversedBinaryNumber(str, length);
	}
	str[length] = number % 2 + '0';
	number /= 2;
	return returnDecToBinaryNumber(number, str, ++length);
}

int main()
{
	int number;
	std::cout << INT_MAX << std::endl;
	std::cin >> number;
	char binNumber[32];
	returnDecToBinaryNumber(number, binNumber);
	for (int i = 0; binNumber[i] != '\0'; i++)
	{
		std::cout << binNumber[i];
	}
	std::cout << std::endl;
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
