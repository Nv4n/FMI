#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include "ComputerPartWriter.h"


ComputerPartWriter::ComputerPartWriter(const char* filename, const ComputerPart& compPart) {
	size_t size = std::strlen(filename) + 1;
	this->filename = new char[size];
	strcpy_s(this->filename, size, filename);

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
	//Format {<тип> | <марка> | <модел> | <гаранция> | <цена>}
	os << "{";
	os.write(reinterpret_cast<const char*> (compPart.getType()), sizeof(compPart.getType()));
	os << "|";

	size_t size = std::strlen(compPart.getBrand());
	os << size << compPart.getBrand() << "|";

	size = std::strlen(compPart.getModel());
	os << size << compPart.getModel() << "|"
		<< compPart.getWarranty() << "|"
		<< compPart.getPrice() << '}';
}

void ComputerPartWriter::close() {
	os.close();
}
void ComputerPartWriter::destroy() {
	if (filename != nullptr) {
		delete[] filename;
	}
}
