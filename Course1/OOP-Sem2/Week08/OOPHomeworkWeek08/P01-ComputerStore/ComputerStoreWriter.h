#ifndef COMPUTER_STORE_WRITER_H
#define COMPUTER_STORE_WRITER_H
#include "ComputerStore.h"

#pragma once
class ComputerStoreWriter
{
private:
	ComputerStore compStore;
public:
	ComputerStoreWriter() = delete;
	ComputerStoreWriter(std::ofstream& os, const ComputerStore& compStore);
	~ComputerStoreWriter();
private:
	void write(std::ofstream& os);

	//void destroy();
};
#endif // !COMPUTER_STORE_WRITER_H