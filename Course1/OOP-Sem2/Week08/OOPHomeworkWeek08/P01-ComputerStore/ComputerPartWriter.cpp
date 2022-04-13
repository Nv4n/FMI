#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include "ComputerPartWriter.h"


ComputerPartWriter::ComputerPartWriter(const char* filename, const ComputerPart& compPart) {
	this->filename = new char[std::strlen(filename) + 1];
	std::strcpy(this->filename, filename);
	this->compPart = compPart;
}

ComputerPartWriter::~ComputerPartWriter() {
	if (os.is_open()) {
		close();
	}
	destroy();
}

void ComputerPartWriter::save() {
	os.open(filename);
	if (!os.is_open()) {
		throw new std::exception("Failed write stream opening!");
		return;
	}
	//{<тип> | <марка> | <модел> | <гаранция> | <цена>}
	os << "{" << compPart.getType() << "|"
		<< compPart.getBrand() << "|"
		<< compPart.getModel() << "|"
		<< compPart.getWarranty() << "|"
		<< compPart.getPrice() << '}';
}

void ComputerPartWriter::close() {
	os.close();
}
void ComputerPartWriter::destroy() {
	delete[] filename;
}
