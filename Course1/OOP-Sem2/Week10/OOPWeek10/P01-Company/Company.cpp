#include <iostream>
#include <cstring>
#include "Company.h"

Company::Company() {
	capacity = 12;
	size = 0;
	employees = new Employee * [capacity];
}

Company::Company(const Company& other) {
	copy(other);
}

Company& Company::operator=(const Company& other) {
	if (this != &other) {
		destroy();
		copy(other);
	}
	return *this;
}

Company::~Company() {
	destroy();
}

void Company::addEmployee(Employee* const emp) {
	if (size + 1 > capacity) {
		resize();
	}

	employees[size] = emp->clone();
	size++;
}

void Company::resize() {
	capacity *= 2;
	Employee** emplsTemp = new Employee * [capacity];
	for (size_t i = 0; i < size; i++) {
		emplsTemp[i] = employees[i];
	}
	delete[] employees;

	employees = new Employee * [capacity];
	for (size_t i = 0; i < size; i++) {
		employees[i] = emplsTemp[i];
	}
	delete[] emplsTemp;
}

void Company::destroy() {
	for (size_t i = 0; i < size; i++) {
		delete[] employees[i];
	}

	delete[] employees;
}

void Company::copy(const Company& other) {
	size = other.size;
	capacity = other.capacity;
	employees = new Employee * [capacity];

	for (size_t i = 0; i < size; i++) {
		employees[i] = other.employees[i];
	}
}
