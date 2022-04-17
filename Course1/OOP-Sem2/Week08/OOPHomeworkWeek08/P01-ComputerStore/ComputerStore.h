#ifndef COMPUTER_STORE_H
#define COMPUTER_STORE_H

#include "ComputerPart.h"
struct Storage {
	ComputerPart computerPart;
	size_t quantity;
};

#pragma once
class ComputerStore
{
private:
	char* name;
	char workTime[12];
	double turnover;
	Storage* parts;
	size_t size;
	size_t capacity;
public:
	ComputerStore();
	ComputerStore(char* name, char workTime[12], double turnover, Storage* parts, size_t size, size_t capacity);
	ComputerStore(const ComputerStore& other);
	ComputerStore& operator=(const ComputerStore& other);
	~ComputerStore();

	const char* getName() const;
	char* getWorkTime() const;
	double getTurnover();
	const Storage* getParts() const;
	const size_t getPartsCount();

	void addPart(ComputerPart& part, size_t quantity);
	void removePart(ComputerPart& part);
	const ComputerPart& findPart(PartType type, char* brand);

private:
	void setName(const char* name);
	void setWorkTime(const char workTime[12]);
	void setTurnover(const double turnover);
	void setParts(const Storage* parts);

	void resize();
	void copy(const ComputerStore& other);
	void destroy();
};

#endif // !COMPUTER_STORE_H