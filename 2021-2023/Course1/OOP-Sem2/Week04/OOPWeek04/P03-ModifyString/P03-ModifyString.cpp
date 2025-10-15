// P03-ModifyString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cstring>

#define PATH_FILE "file"
//Напишете програма, която приема стринг и има следните функции : -функция, която обработва въведения стринг - променя всички малки букви в главни -
//функция, която записва променения стринг в бинарен файл

void modifyStringAndSave(const char* filePath, char* inputText);
void modifyString(char* inputText);

int main()
{
	//fhx PathFile
	char text[] = "Hello";
	modifyStringAndSave(PATH_FILE, text);
	return 0;
}

void modifyStringAndSave(const char* filePath, char* inputText) {
	std::ofstream writeStream(filePath, std::ios::binary);

	if (!writeStream.is_open()) {
		return;
	}

	modifyString(inputText);
	writeStream.write(reinterpret_cast<const char*>(&inputText), sizeof(inputText));

	writeStream.close();
}

void modifyString(char* inputText) {
	for (int index = 0; index < std::strlen(inputText); index++) {
		if (inputText[index] >= 'a' && inputText[index] <= 'z') {
			inputText[index] -= ('a' - 'A');
		}
		else if (inputText[index] >= 'A' && inputText[index] <= 'Z') {
			inputText[index] += ('a' - 'A');
		}
	}
}
