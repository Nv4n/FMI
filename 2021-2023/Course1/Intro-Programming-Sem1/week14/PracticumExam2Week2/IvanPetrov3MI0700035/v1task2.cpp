// v1task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void countWords(char* str) {
	char words[501][1000];
	int wordMatchCount[501];
	int wordIndex = 0;
	int wordCount = 0;
	int letterIndex = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ') {
			words[wordIndex][letterIndex] = str[i];
			letterIndex++;
		}
		else if (str[i] == ' ' && str[i + 1] != ' ') {
			letterIndex = 0;
			bool match = true;
			int count = 0;
			for (int j = 0; str[j] != '\0'; j++, letterIndex++)
			{
				if (match && str[j] == ' ' && str[j + 1] != ' ') {
					count++;
					letterIndex = 0;
				}
				else if (match && str[j] != ' ' && (words[wordIndex][letterIndex] == '\0' || words[wordIndex][letterIndex] != str[j]))
				{
					match = false;
				}

				else if (str[j] == ' ' && str[j + 1] != ' ') {
					match = true;
				}
			}
			letterIndex = 0;
			wordMatchCount[wordIndex] = count;
			wordCount++;
			wordIndex++;
		}
	}

	for (int i = 0; i < wordCount; i++)
	{
		for (int j = 0; words[i][j] != '\0'; j++)
		{
			std::cout << words[i][j];
		}
		std::cout << " - " << wordMatchCount[i] << std::endl;
	}

}
int main()
{
	char str[1000];
	std::cin.getline(str, 1000);
	countWords(str);
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
