#include<iostream>
#include<cstring>
#include <stdexcept>
#include "ComputerStore.h"

#pragma region Ctors
ComputerStore::ComputerStore() :name(nullptr),
turnover(0),
workTime("HH:MM-HH:MM"),
size(0),
capacity(8) {
	parts = new Storage[capacity];
}

ComputerStore::ComputerStore(const char* name, char workTime[12], const double turnover, const Storage* parts, const size_t size, const size_t capacity) {
	setName(name);
	setWorkTime(workTime);
	setTurnover(turnover);

	this->size = size;
	if (capacity > size) {
		this->capacity = capacity;
	}
	else {
		this->capacity = size * 2 + 1;
	}

	setParts(parts);
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

#pragma region Setters
void ComputerStore::setName(const char* name) {
	if (&(this->name) != &name) {
		delete[] this->name;
		size_t size = std::strlen(name) + 1;
		this->name = new char[size];
		strcpy_s(this->name, size, name);
	}
}
void ComputerStore::setWorkTime(const char workTime[12]) {
	//TODO Validation for worktime
	for (size_t i = 0; i < 12; i++) {
		this->workTime[i] = workTime[i];
	}
}
void ComputerStore::setTurnover(const double turnover) {
	if (turnover < 0) {
		throw new std::invalid_argument("Invalid turnover value!");
	}
	this->turnover = turnover;
}
void ComputerStore::setParts(const Storage* parts) {
	if (parts != nullptr && &(this->parts) != &parts) {
		delete[] this->parts;
		this->parts = new Storage[capacity];

		for (size_t i = 0; i < size; i++) {
			this->parts[i].computerPart = parts[i].computerPart;
			this->parts[i].quantity = parts[i].quantity;
		}
	}
	else {
		this->parts = new Storage[capacity];
	}
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
double ComputerStore::getTurnover() {
	double temp = 0;
	for (size_t i = 0; i < size; i++) {
		temp += parts[i].computerPart.getPrice() * parts[i].quantity;
	}
	turnover = temp;
	return turnover;
}
const Storage* ComputerStore::getParts() const {
	return parts;
}
const size_t ComputerStore::getPartsCount() {
	return size;
}
#pragma endregion

#pragma region StoreMethods
void ComputerStore::addPart(ComputerPart& part, size_t quantity) {
	if (size + 1 > capacity) {
		resize();
	}
	parts[size].computerPart = part;
	parts[size].quantity = quantity;
	size++;
}
void ComputerStore::removePart(ComputerPart& part) {
	for (size_t i = 0; i < size; i++) {
		if (&(parts[i].computerPart) == &part) {
			delete& parts[i];
		}
	}
}
const ComputerPart& ComputerStore::findPart(PartType type, char* brand) {
	for (size_t i = 0; i < size; i++) {
		if (parts[i].computerPart.getType() == type
			&& std::strcmp(parts[i].computerPart.getBrand(), brand) == 0) {
			return parts[i].computerPart;
		}
	}
	return ComputerPart();
}
#pragma endregion

#pragma region PrivateMethods
void ComputerStore::resize() {
	capacity *= 2;
	Storage* temp = new Storage[capacity];
	for (size_t i = 0; i < size; i++) {
		temp[i].computerPart = parts[i].computerPart;
		temp[i].quantity = parts[i].quantity;
	}

	delete[] parts;
	parts = new Storage[capacity];

	for (size_t i = 0; i < size; i++) {
		parts[i].computerPart = temp[i].computerPart;
		parts[i].quantity = temp[i].quantity;
	}
}

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