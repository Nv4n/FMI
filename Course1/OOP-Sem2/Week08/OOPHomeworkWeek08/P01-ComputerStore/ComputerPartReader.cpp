#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include "ComputerPartReader.h"

ComputerPartReader::ComputerPartReader(std::ifstream& is, ComputerPart& compPart) {
	read_(is,compPart);
}

ComputerPartReader::ComputerPartReader(const char* filename) {
	size_t size = std::strlen(filename) + 1;

	this->filename = new char[size];
	strcpy_s(this->filename, size, filename);
}
ComputerPartReader::~ComputerPartReader() {
	close();
	destroy();
}

ComputerPart& ComputerPartReader::read() {
	is.open(filename);
	if (!is.is_open()) {
		throw new std::exception("Failed read stream opening!");
	}
	ComputerPart temp;
	read_(is, temp);

	return temp;
}
void ComputerPartReader::read_(std::ifstream& is, ComputerPart& compPart) {
	//Format {<тип> | <марка> | <модел> | <гаранция> | <цена>}
	char ignore;
	PartType type;
	short warranty;
	double price;

	is >> ignore;
	is.read(reinterpret_cast<char*>(&type), sizeof(type));

	size_t size;
	is >> ignore >> size;
	char* brand = new char[size + 1];
	is.read(brand, sizeof(size));

	is >> ignore >> size;
	char* model = new char[size + 1];
	is.read(model, sizeof(size));

	is >> ignore >> warranty >> ignore >> price >> ignore;

	ComputerPart temp(type, warranty, price, brand, model);
}

void ComputerPartReader::close() {
	is.close();
}

void ComputerPartReader::destroy() {
	if (filename != nullptr) {
		delete[] filename;
	}
}