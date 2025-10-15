#include "Dictionary.h"
#include <iostream>

void Dictionary::copy(const Dictionary& other) {
	size = other.size;
	records = new Record[other.capacity];
	capacity = other.capacity;

	for (int i = 0; i < size; i++) {
		records[i] = other.records[i];
	}
}

void Dictionary::resize() {
	if (capacity * 2 > 500)
	{
		std::cout << "Maximum limit of records!" << std::endl;
	}
	else
	{
		capacity *= 2;
		Record* temp = new Record[this->capacity];

		for (int i = 0; i < size; i++)
		{
			temp[i] = this->records[i];
		}

		delete[] records;
		records = temp;
	}
}
void Dictionary::destroy()
{
	delete[] records;
}

Dictionary::Dictionary()
{
	records = new Record[3];
	size = 0;
	capacity = 0;
}

Dictionary::Dictionary(const Dictionary& other)
{
	copy(other);
}

Dictionary::Dictionary(const int capacity)
{
	this->capacity = capacity;
	this->records = new Record[capacity];
}

Dictionary& Dictionary::operator=(const Dictionary& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}

	return *this;
}

Dictionary::~Dictionary()
{
	destroy();
}

void Dictionary::addRecord(const char* word, const char* meaning)
{
	if (records == nullptr) {
		records = new Record[8];
		capacity = 8;
	}
	if (size + 1 == capacity) {
		resize();
	}

	Record newRecord(word, meaning);
	this->records[this->size++] = newRecord;
}

void Dictionary::print() {
	for (int i = 0; i < this->size; i++) {
		this->records[i].printWord();
	}
}

int Dictionary::getSize() const {
	return this->size;
}

int Dictionary::getCapacity() const {
	return this->capacity;
}

const Record& Dictionary::find(const char* wordToFind) const {
	for (int i = 0; i < this->size; i++) {
		if (strcmp(this->records[i].getWord(), wordToFind) == 0) {
			return this->records[i];
		}
	}
}