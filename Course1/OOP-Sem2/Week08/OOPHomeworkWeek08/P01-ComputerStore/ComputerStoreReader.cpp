#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include "ComputerStoreReader.h"
#include "ComputerPartReader.h"

#pragma region
ComputerStoreReader::ComputerStoreReader(std::ifstream& is) {
	read_(is);
}

ComputerStoreReader::ComputerStoreReader(const char* filename) {
	size_t size = std::strlen(filename) + 1;

	this->filename = new char[size];
	strcpy_s(this->filename, size, filename);
}
ComputerStoreReader::~ComputerStoreReader() {
	close();
	destroy();
}
#pragma endregion

ComputerStore& ComputerStoreReader::read() {
	is.open(filename);
	if (!is.is_open()) {
		throw new std::exception("Failed read stream opening!");
	}

	read_(is);
}
ComputerStore& ComputerStoreReader::read_(std::ifstream& is) {
	/*<име на магазин>
		<работно време>
		<брой артикули>
		[
	{<тип> | <марка> | <модел> | <гаранция> | <цена>} <наличност>
	…
		]
	<оборот на магазина>*/

	char ignore;
	double turnover;
	size_t size;
	size_t capacity;

	size_t size_;
	is >> size_;

	char* name = new char[size_ + 1];
	is.read(reinterpret_cast<char*>(name), sizeof(size_));
	is >> ignore;

	char workTime[12];
	is.read(reinterpret_cast<char*>(workTime), 11);
	is >> ignore;

	is >> size >> ignore >> ignore >> ignore;
	capacity = size * 2;
	Storage* parts = new Storage[capacity];
	for (size_t i = 0; i < size; i++) {
		is >> ignore;
		ComputerPartReader(is, parts[i].computerPart);
		is >> ignore >> parts[i].quantity >> ignore;
	}

	is >> ignore >> ignore;
	is >> turnover;
	ComputerStore temp(name, workTime, turnover, parts, size, capacity);
	return temp;
}
void ComputerStoreReader::close() {
	is.close();
}

void ComputerStoreReader::destroy() {
	if (filename != nullptr) {
		delete[] filename;
	}
}