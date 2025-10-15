#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include "ComputerPart.h"

struct Item {
	ComputerPart computerPart;
	size_t quantity;
};

#pragma once
class Configuration
{
private:
	Item* items;
	size_t size;
	size_t capacity;
public:
	Configuration();
	Configuration(size_t size, Item* items);
	Configuration(const Configuration& other);
	Configuration& operator=(const Configuration& other);
	~Configuration();

	Item& operator[](size_t index);
private:
	void resize();
	void copy(const Configuration& other);
	void destroy();
};
#endif // !CONFIGURATION_H