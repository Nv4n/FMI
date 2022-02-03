// P08-CountWords.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int countWords(char* arr, int words = 0);
int main()
{
	int size;
	std::cin >> size;
	char* arr = new char[size];
	std::cin.ignore();
	std::cin.getline(arr, size);
	std::cout << countWords(arr) << std::endl;
	delete[] arr;
}
int countWords(char* arr, int words) {
	while (*arr != '\0')
	{
		if (*arr == ' ' && *(arr + 1) != ' ')
		{
			words++;
		}
		arr++;
	}
	return words + 1;
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
