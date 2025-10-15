#include <iostream>
char* printWord(char text[], int wordLastIndex, int previousCount)
{
	char* word = new char[previousCount + 1];
	for (int i = wordLastIndex - previousCount + 1, j = 0; j < previousCount; j++, i++)
	{
		word[j] = text[i];
	}
	word[previousCount] = '\0';
	return word;
}

char* func(char text[], int wordLastIndex = 0, int index = 0, int previousCount = 0, int counter = 0)
{
	if (text[index] == '\0')
	{
		return printWord(text, wordLastIndex, previousCount);
	}
	if (text[index] == ' ')
	{
		if (previousCount < counter)
		{
			previousCount = counter;
			wordLastIndex = index;
		}
		counter = 0;
	}
	return func(text, wordLastIndex, index + 1, previousCount, counter + 1);
}


int main()
{
	int size;
	std::cin >> size;
	char* text = new char[size + 1];

	std::cin.ignore();
	std::cin.getline(text, size);

	char* longestWord = func(text);
	for (int i = 0; longestWord[i] != '\0'; i++)
	{
		std::cout << longestWord[i];
	}

	std::cout << std::endl;

	delete[] text;
	delete[] longestWord;

	return 0;
}