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
	ComputerPartReader(std::ifstream& is, ComputerPart& compPart);
	ComputerPartReader(const char* filename);
	~ComputerPartReader();

	ComputerPart& read();
	void close();
private:
	void read_(std::ifstream& is, ComputerPart& compPart);
	void destroy();
};

#endif // !COMPUTER_PART_READER_H