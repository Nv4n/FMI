#include "Developer.h"

Developer::Developer(const Developer& other){
	Employee::copy(other);
	copy(other);
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
