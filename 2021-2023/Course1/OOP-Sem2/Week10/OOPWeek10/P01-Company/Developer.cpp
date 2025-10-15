#include <iostream>
#include "Developer.h"

Developer::Developer(const Developer& other) {
	copy(other);
}

Developer& Developer::operator=(const Developer& other) {
	if (this != &other) {
		Employee::destroy();
		copy(other);
	}
	return *this;
}

Employee* Developer::clone() const {
	return new Developer(*this);
}

void Developer::setCppKnown(bool isCppKnown) {
	this->isCppKnown;
}

void Developer::setCsharpKnown(bool isCsharpKnown) {
	this->isCsharpKnown = isCsharpKnown;
}

bool Developer::getCppKnown() {
	return isCppKnown;
}

bool Developer::getCsharpKnown()
{
	return isCsharpKnown;
}

void Developer::copy(const Developer& other) {
	Employee::copy(other);
	isCppKnown = other.isCppKnown;
	isCsharpKnown = other.isCsharpKnown;
}
