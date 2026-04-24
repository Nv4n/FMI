#pragma once
#include "Shelf.h"
class Bookshelf
{
private:
	Shelf* shelves;
	const unsigned shelfCount;
public:
	Bookshelf(unsigned shelfCount, unsigned shelfSize);
	~Bookshelf();
	Bookshelf(const Bookshelf&)=delete;
	Bookshelf& operator=(const Bookshelf&) = delete;
};

