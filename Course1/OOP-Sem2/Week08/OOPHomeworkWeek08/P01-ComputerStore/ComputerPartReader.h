#ifndef COMPUTER_PART_READER_H
#define COMPUTER_PART_READER_H

#include "ComputerPart.h"

#pragma once
class ComputerPartReader
{
private:
	std::ifstream is;
	char* filename;
public:
	ComputerPartReader() = delete;
	ComputerPartReader(const char* filename);
	//TODO Copy and operator=S
	~ComputerPartReader();

	ComputerPart& read();
	void close();
private:
	void readChar(char& chr);
	void destroy();
};

#endif // !COMPUTER_PART_READER_H