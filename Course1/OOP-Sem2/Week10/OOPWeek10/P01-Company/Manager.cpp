#include <iostream>
#include "Manager.h"

Manager::Manager(const Manager& other) {
	copy(other);
}

Manager& Manager::operator=(const Manager& other) {
	if (this != &other) {
		Employee::destroy();
		copy(other);
	}
	return *this;
}

void Manager::setMngdEmployeesCount(size_t mngdEmplsCount) {
	this->mngdEmplsCount = mngdEmplsCount;
}

size_t Manager::getMngdEmployeesCount() {
	return mngdEmplsCount;
}

void Manager::copy(const Manager& other) {
	Employee::copy(other);
	mngdEmplsCount = other.mngdEmplsCount;
}

Employee* Manager::clone() const {
	return new Manager(*this);
}
