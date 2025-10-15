#ifndef COMPUTER_STORE_READER_H
#define COMPUTER_STORE_READER_H
#include "ComputerStore.h"

#pragma once
class ComputerStoreReader
{
private:
	std::ifstream is;
	char* filename;
public:
	ComputerStoreReader() = delete;
	ComputerStoreReader(std::ifstream& is);
	ComputerStoreReader(const char* filename);
	~ComputerStoreReader();

	ComputerStore& read();
	void close();
private:
	ComputerStore& read_(std::ifstream& os);
	void destroy();
};
#endif // !COMPUTER_STORE_READER_H