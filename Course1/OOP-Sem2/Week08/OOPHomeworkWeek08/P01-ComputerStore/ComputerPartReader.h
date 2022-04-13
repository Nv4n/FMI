#ifndef COMPUTER_PART_READER_H
#define COMPUTER_PART_READER_H
#pragma once
class ComputerPartReader
{
private:
	std::ifstream os;
	char* filename;
};


#include "ComputerPart.h"

#pragma once
class ComputerPartWriter
{
private:
	
public:
	ComputerPartWriter() = delete;
	ComputerPartWriter(const char* filename, const ComputerPart& compPart);
	~ComputerPartWriter();

	void save();
	void close();
private:
	void destroy();
};

#endif // !COMPUTER_PART_READER_H