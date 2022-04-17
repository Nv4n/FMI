#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include "ComputerPartReader.h"

ComputerPartReader::ComputerPartReader(const char* filename) {
	this->filename = new char[std::strlen(filename) + 1];
	std::strcpy(this->filename, filename);
}
ComputerPartReader::~ComputerPartReader() {
	close();
	destroy();
}

ComputerPart& ComputerPartReader::read() {
	is.open(filename);
	if (!is.is_open()) {
		throw new std::exception("Failed read stream opening");
		return;
	}
	//{<тип> | <марка> | <модел> | <гаранция> | <цена>}
	char temp;
	PartType type;
	short warranty;
	double price;
	char* brand;
	char* model;

	readChar(temp);
	is.read(reinterpret_cast<char*>(&type), sizeof(type));
	is.read(reinterpret_cast<char*>(&brand), sizeof(brand));
	is.read(reinterpret_cast<char*>(&model), sizeof(model));
	is.read(reinterpret_cast<char*>(&warranty), sizeof(warranty));
	is.read(reinterpret_cast<char*>(&price), sizeof(price));

}


void ComputerPartReader::close() {
	is.close();
}
void ComputerPartReader::destroy() {
	delete[] filename;
}

void ComputerPartReader::readChar(char& chr) {
	if (is.is_open()) {
		is.read(reinterpret_cast<char*>(&chr), sizeof(chr));
	}
}
