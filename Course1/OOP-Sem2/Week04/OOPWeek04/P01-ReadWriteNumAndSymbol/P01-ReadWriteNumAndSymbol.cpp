// P01-ReadWriteNumAndSymbol.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

#define PATH_FILE "dataFile.txt"

void write(const char* filePath, const int num);
void write(const char* filePath, const char symbol);

void read(const char* filePath, int num);
void read(const char* filePath, char symbol);

int main()
{
	std::cout << "Hello World!\n";
}

void write(const char* filePath, const int num) {
	std::ofstream writeStream(filePath, std::ios::binary);

	if (!writeStream.is_open()) {
		std::cout << "Error!" << std::endl;
		return;
	}

	writeStream.write(reinterpret_cast<const char*>(num), sizeof(num));

	writeStream.close();
}
void write(const char* filePath, const char symbol) {
	std::ofstream writeStream(filePath, std::ios::binary);

	if (!writeStream.is_open()) {
		std::cout << "Error!" << std::endl;
		return;
	}

	writeStream.write(reinterpret_cast<const char*>(symbol), sizeof(symbol));

	writeStream.close();
}

void read(const char* filePath, int& num) {
	std::ifstream readStream(filePath, std::ios::binary);

	if (!readStream.is_open()) {
		std::cout << "Error!" << std::endl;
		return;
	}

	readStream.read(reinterpret_cast<char*>(num), sizeof(num));

	readStream.close();
}
void read(const char* filePath, char& symbol) {
	std::ifstream readStream(filePath, std::ios::binary);

	if (!readStream.is_open()) {
		std::cout << "Error!" << std::endl;
		return;
	}

	readStream.read(reinterpret_cast<char*>(symbol), sizeof(symbol));

	readStream.close();
}