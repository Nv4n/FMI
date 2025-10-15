// P01-PrintYourself.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

#define MAX_SIZE = 256

int main()
{
	char buffer[]
	std::ifstream fileReadStream("P01-PrintYourself.cpp");

	if (!fileReadStream.is_open()) {
		std::cout << "Failed opening!" << std::endl;
		return -1;
	}

	while (!fileReadStream.eof()){
		fileReadStream.getline(buffer)
	}
}