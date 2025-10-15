#ifndef COMPUTER_PART_WRITER_H
#define COMPUTER_PART_WRITER_H

#include "ComputerPart.h"

#pragma once
class ComputerPartWriter
{
private:
	//char* filename;
	ComputerPart compPart;
public:
	ComputerPartWriter() = delete;
	ComputerPartWriter(std::ofstream& os, const ComputerPart& compPart);
	//ComputerPartWriter(const char* filename, const ComputerPart& compPart);
	//~ComputerPartWriter();

	//void save();
	//void close();
private:
	void write(std::ofstream& os);
	//void destroy();
};

#endif // !COMPUTER_PART_WRITER_H