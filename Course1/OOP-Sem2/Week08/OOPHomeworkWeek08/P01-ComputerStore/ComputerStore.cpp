#include<iostream>
#include<cstring>
#include "ComputerStore.h"
#pragma region PartStorage

ComputerPart computerParts;
void copy(const PartStorage& other);
void PartStorage::destroy() {
}
public:
	PartStorage();
	PartStorage(const PartStorage& other);
	PartStorage& operator=(const PartStorage& other);
	~PartStorage();
#pragma endregion
	ComputerStore::ComputerStore() :name(nullptr),
		capacity(0) {}
	ComputerStore::ComputerStore(const ComputerStore& other) {

	}
	ComputerStore& ComputerStore::operator=(const ComputerStore& other) {
		if (this != &other) {
			destroy();
			copy(other);
		}
	}
	ComputerStore::~ComputerStore() {
		destroy();
	}

	void ComputerStore::copy(const ComputerStore& other) {
		name = new char(std::strlen(other.name));
		std::strcpy(name, other.name);
		std::strcpy(workTime, other.workTime);
		capacity = other.capacity;
	}

	void ComputerStore::destroy() {
		delete[] name;
	}