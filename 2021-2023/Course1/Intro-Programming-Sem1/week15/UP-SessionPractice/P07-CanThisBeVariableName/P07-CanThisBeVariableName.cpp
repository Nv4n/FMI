// P07-CanThisBeVariableName.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Напишете булева функция, която определя дали даден низ може да бъде идентификатор на променлива.
#include <iostream>
bool isThisPossibleVariableName(char* str);

int main()
{
	int size;
	std::cin >> size;
	char* str = new char[size];
	std::cin >> str;
	std::cout << isThisPossibleVariableName(str) << std::endl;
	delete[] str;
}
bool isThisPossibleVariableName(char* str) {
	if (!(str[0] >= 'a' && str[0] <= 'z'))
	{
		return false;
	}
	for (int i = 1; str[i] != '\0'; i++)
	{
		if (!(str[i] >= 'a' && str[i] <= 'Z' ||
			str[i] >= '0' && str[i] <= '9' ||
			str[i] == '_'))
		{
			return false;
		}
	}
	return true;
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
