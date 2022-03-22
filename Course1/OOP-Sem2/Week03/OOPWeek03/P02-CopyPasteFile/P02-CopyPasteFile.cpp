// P02-CopyPasteFile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

#define MAX_SIZE 256

bool copyFileContentIntoAnother(const char* mainFilePath, const char* copyFilePath) {
	std::ifstream fileReadStream(mainFilePath);
	std::ofstream fileWriteStream(copyFilePath);

	if (!fileReadStream.is_open() || !fileWriteStream.is_open()) {
		std::cout << "ERROR!" << std::endl;
		return false;
	}

	char buffer[MAX_SIZE];

	while (!fileReadStream.eof()) {
		fileReadStream.getline(buffer, MAX_SIZE);
		fileWriteStream << buffer << std::endl;
	}

	fileReadStream.close();
	fileWriteStream.close();
	return true;
}
int main()
{
	std::cout << std::boolalpha << copyFileContentIntoAnother("P02-CopyPasteFile.cpp", "P02Copy.txt") << std::endl;
}