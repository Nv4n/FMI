// P07-Task7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
bool validation(char* str) {
	while (*str != '\0') {
		if (*(str + 1) == '\0') {
			if (*str == '.' || *str == '!' || *str == '?')
			{

			}
			return true;
		}
		str++;

	}
	std::cout << "Ivalid! " << std::endl;
	return false;
}

double averageStr(char* str) {
	int letterCount = 0, wordCount = 1;
	while (*str != '\0') {
		if (*str >= 'A' && *str <= 'z')
		{
			letterCount++;
		}
		else if (*str == ' ') {
			wordCount++;
			while (*str == ' ')
			{
				str++;
			}
		}
		str++;
	}
	return 1.0 * letterCount / wordCount;
}

int main()
{
	char sentence[] = "Lorem Ipsum.";
	if (validation(sentence)) {
		std::cout << averageStr(sentence) << std::endl;
	}
}

/// Задача 7
//Напишете функция, която приема текст и пресмята средната дължина на думите(броя букви, разделен на броя на думите).Изреченията в текста завършват с един от следните символи : точка(.), удивителна(!) и въпросителна(? )..Вземете под внимание, че един текст може да има няколко спейса един след друг.
