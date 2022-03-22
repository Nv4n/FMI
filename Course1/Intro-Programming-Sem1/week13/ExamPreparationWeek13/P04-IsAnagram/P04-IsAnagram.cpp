// P04-IsAnagram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int lettersCount(char* str) {
	int counter = 0;
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'z')
		{
			counter++;
		}
		str++;
	}
}
bool isLetter(char symbol) {
	return symbol >= 'A' && symbol <= 'z';
}
bool isAnagram(char* str1, char* str2) {
	if (lettersCount(str1) == lettersCount(str2))
	{
		for (int index = 0; str1[index] != '\0' && str2[index] != '\0'; index++)
		{
			if (!isLetter(str1[index])) {
				continue;
			}
			char currentLetter = str1[index];
			int counter1 = 0, counter2 = 0;
			for (size_t i = 0; str1[i] != '\0'; i++)
			{
				if (str1[i] == currentLetter)
				{
					counter1++;
				}
			}

			for (size_t i = 0; str2[i] != '\0'; i++)
			{
				if (str2[i] == currentLetter)
				{
					counter2++;
				}
			}
			if (counter1 != counter2) {
				return false;
			}
		}
		return true;
	}

	return false;
}

int main()
{
	std::cout << "Hello World!\n";
}

//Задача 4
//Две изречения са анаграми едно на друго, ако съдържат еднакъв брой букви(английски) и всяка буква от едното изречение се среща еднакъв брой пъти и в двете изречения.Не правим разлика между главни и малки английски букви.Напишете функция, която по два символни низа, съдържащи английски букви и евентуално интервали, проверява дали двата низа са анаграми един на друг.
//
//Пример:
//
//Пример:
//Вход:
//"Astronomer"
//"Moon starer"
//Изход :
//    YES
//    Вход :
//"A B B A"
//"baba"
//Изход :
//    YES