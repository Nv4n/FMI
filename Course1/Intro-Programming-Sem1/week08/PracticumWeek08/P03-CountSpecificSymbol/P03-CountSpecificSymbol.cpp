// P03-CountSpecificSymbol.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int countNeededSymbol(char symbolArr[], char symbolToFind) {
	int i = 0;
	int count = 0;
	while (symbolArr[i] != '\0')
	{
		if (symbolArr[i] == symbolToFind)
		{
			count++;
		}
		i++;
	}

	return count;
}

int main()
{
	/*int arrLength;
	std::cin >> arrLength;
	char* symbolArray = new char[arrLength];
	char symbolToSearch;
	std::cin >> symbolToSearch;

	for (int i = 0; i < arrLength; i++)
	{
		std::cin >> symbolArray[i];
	}


	int count = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (symbolArray[i] == symbolToSearch)
		{
			count++;
		}
	}

	std::cout << count << std::endl;*/

	//int arrLength;
	//std::cin >> arrLength;
	char symbol[10];
	char symbolToFind;
	std::cin >> symbolToFind;

	int symbolCount = 0;
	std::cin >> symbol;

	std::cout << countNeededSymbol(symbol, symbolToFind) << std::endl;

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
