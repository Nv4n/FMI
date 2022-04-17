#ifndef COMPUTER_STORE_WRITER_H
#define COMPUTER_STORE_WRITER_H
#include "ComputerStore.h"

#pragma once
class ComputerStoreWriter
{
private:
	std::ofstream os;
	char* filename;
	ComputerStore compStore;
public:
	ComputerStoreWriter() = delete;
	ComputerStoreWriter(const char* filename, const ComputerStore& compStore);
	~ComputerStoreWriter();

	void save();
	void close();
private:
	void destroy();
};
#endif // !COMPUTER_STORE_WRITER_H