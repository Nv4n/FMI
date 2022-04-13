#ifndef COMPUTER_PART_WRITER_H
#define COMPUTER_PART_WRITER_H

#include "ComputerPart.h"

#pragma once
class ComputerPartWriter
{
private:
	std::ofstream os;
	char* filename;
	ComputerPart compPart;
public:
	ComputerPartWriter() = delete;
	ComputerPartWriter(const char* filename, const ComputerPart& compPart);
	~ComputerPartWriter();

	void save();
	void close();
private:
	void destroy();
};

#endif // !COMPUTER_PART_WRITER_H