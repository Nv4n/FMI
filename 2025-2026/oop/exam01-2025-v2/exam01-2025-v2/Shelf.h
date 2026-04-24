#pragma once
#include "Book.h"
class Shelf
{
private:
	Book** books;
	unsigned pageCapacity;
	std::size_t size;
	std::size_t length;
public:
	Shelf(unsigned pageCapacity);
	Shelf(const Shelf&) = delete;
	Shelf& operator=(const Shelf&) = delete;
	~Shelf();
};

