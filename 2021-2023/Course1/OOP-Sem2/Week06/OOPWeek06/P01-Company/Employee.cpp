#include "Employee.h"
#include <cstring>

Employee::~Employee() {
	delete[] this->name;
}

Employee::Employee(const char* name, const unsigned int age, const unsigned int wage) {
	this->name = new char[std::strlen(name)];
	std::strcpy(this->name, name);
	this->age = age;
	this->wage = wage;
}

Employee Employee::operator=(Employee const& empl) {
	return Employee(empl);
}

char* Employee::getName() {
	return this->name;
}

unsigned int Employee::getAge() {
	return this->age;
}

unsigned int Employee::getWage() {
	return this->wage;
}

void Employee::setName(const char* name) {
	delete[] this->name;
	this->name = new char(std::strlen(name));
	std::strcpy(this->name, name);
}

void Employee::setAge(const unsigned int age) {
	this->age = age;
}

void Employee::setWage(const unsigned int wage) {
	this->wage = wage;
}