#include "BookShelf.h"

Bookshelf::~Bookshelf()
{
	delete[] shelves;
	shelves = nullptr;
}
