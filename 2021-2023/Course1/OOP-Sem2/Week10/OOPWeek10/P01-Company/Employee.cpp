#include <iostream>
#include <cstring>
#include "Employee.h"

#pragma region Ctors
Employee::Employee() {
	name = nullptr;
	experience = 0;
}
Employee::Employee(const char* name, const size_t experience) {
	setName(name);
	setExperience(experience);
}
Employee::Employee(const Employee& other) {
	copy(other);
}
Employee& Employee::operator=(const Employee& other) {
	if (this != &other) {
		destroy();
		copy(other);
	}
	return *this;
}
Employee::~Employee() {
	destroy();
}
#pragma endregion

#pragma region Setters/Getters
void Employee::setName(const char* name) {
	if (&this->name != &name) {
		delete[] this->name;
		size_t size = std::strlen(name) + 1;
		this->name = new char[size];
		strcpy(this->name, name);
	}
}

void Employee::setExperience(const size_t experience) {
	this->experience = experience;
}

const char* Employee::getName() const {
	return name;
}

size_t Employee::getExperinece() {
	return experience;
}
#pragma endregion

void Employee::copy(const Employee& other) {
	size_t size = std::strlen(other.name) + 1;
	name = new char[size];
	std::strcpy(name, other.name);

	experience = other.experience;
}

void Employee::destroy() {
	if (name != nullptr) {
		delete[] name;
	}
}
