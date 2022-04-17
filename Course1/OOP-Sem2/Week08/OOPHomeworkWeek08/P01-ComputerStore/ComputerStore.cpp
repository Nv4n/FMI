#include<iostream>
#include<cstring>
#include <stdexcept>
#include "ComputerStore.h"

ComputerStore::ComputerStore() :name(nullptr),
turnover(0),
workTime("HH:MM-HH:MM"),
size(0),
capacity(8) {
	parts = new Storage[capacity];
}

ComputerStore::ComputerStore(const ComputerStore& other) {
	copy(other);
}

ComputerStore& ComputerStore::operator=(const ComputerStore& other) {
	if (this != &other) {
		destroy();
		copy(other);
	}

	return *this;
}

ComputerStore::~ComputerStore() {
	destroy();
}
#pragma endregion

#pragma region Getters
const char* ComputerStore::getName() const {
	return name;
}
char* ComputerStore::getWorkTime() const {
	char* temp = new char[12];
	strcpy_s(temp, 12, workTime);
	return temp;
}
double ComputerStore::getTurnover()const {
	return turnover;
}
const Storage* ComputerStore::getParts() const {
	return parts;
}
const size_t ComputerStore::getPartsCount() {
	return size;
}
#pragma endregion

#pragma region PrivateMethods
void ComputerStore::copy(const ComputerStore& other) {
	size_t size = std::strlen(other.name) + 1;
	name = new char(size);
	strcpy_s(name, size, other.name);

	for (size_t i = 0; i < 12; i++) {
		workTime[i] = other.workTime[i];
	}

	turnover = other.turnover;

	size = other.size;
	capacity = other.capacity;
	parts = new Storage[capacity];
	for (size_t i = 0; i < size; i++) {
		parts[i].computerPart = other.parts[i].computerPart;
		parts[i].quantity = other.parts[i].quantity;
	}
}

void ComputerStore::destroy() {
	if (name != nullptr) {
		delete[] name;
	}
	if (parts != nullptr) {
		delete[] parts;
	}
}
#pragma endregion