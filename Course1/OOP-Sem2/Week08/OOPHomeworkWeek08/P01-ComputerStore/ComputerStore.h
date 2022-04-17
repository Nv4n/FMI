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
	ComputerStore(const ComputerStore& other);
	ComputerStore& operator=(const ComputerStore& other);
	~ComputerStore();

	//TODO ComputerStore.h acceptance criteria methods
	const char* getName() const;
	char* getWorkTime() const;
	double getTurnover()const;
	const Storage* getParts() const;
	const size_t getPartsCount();

	void addPart(ComputerPart part, size_t quantity);
	void removePart(ComputerPart part);
	ComputerPart* findPart(PartType type, char* brand);

private:
	//TODO ComputerStore.h setters
	void setName(char* name);
	void setWorkTime(char workTime[12]);
	void setTurnover(double turnover);

	void setParts(Storage& parts);

	void resize();
	void copy(const ComputerStore& other);
	void destroy();
};

#endif // !COMPUTER_STORE_H