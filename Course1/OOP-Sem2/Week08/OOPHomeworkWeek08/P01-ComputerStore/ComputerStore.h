#ifndef COMPUTER_STORE_H
#define COMPUTER_STORE_H

#include "ComputerPart.h"
class PartStorage {
private:
	ComputerPart computerPart;
	int quantity;
public:
	PartStorage();
	PartStorage(const Co);
};

#pragma once
class ComputerStore
{
private:
	char* name;
	char workTime[12];
	double capacity;
	int partsQuantity;
	PartStorage* parts;
public:
	ComputerStore();
	ComputerStore(const ComputerStore& other);
	ComputerStore& operator=(const ComputerStore& other);
	~ComputerStore();
private:
	void copy(const ComputerStore& other);
	void destroy();
};

#endif // !COMPUTER_STORE_H