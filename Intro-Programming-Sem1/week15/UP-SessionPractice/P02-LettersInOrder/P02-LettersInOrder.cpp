// P02-LettersInOrder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int size;
	std::cin >> size;
	char* lettersArr = new char[size];
	char* digitsArr = new char[size];

	std::cin >> lettersArr;
	std::cin >> digitsArr;


	for (int i = 0; i < size; i++)
	{
		if (!(lettersArr[i] >= 'a' && lettersArr[i] <= 'j') || !(digitsArr[i] >= '0' && digitsArr[i] <= '9') ||
			lettersArr[i] - 'a' != digitsArr[i] - '0') {
			std::cout << std::boolalpha << false << std::endl;
			return 0;
		}
	}

	std::cout << std::boolalpha << true << std::endl;
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
