#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstring>
#include "ComputerStoreWriter.h"
#include "ComputerPartWriter.h"

ComputerStoreWriter::ComputerStoreWriter(std::ofstream& os, const ComputerStore& compStore) {
	this->compStore = compStore;
	write(os);
}

//ComputerStoreWriter::ComputerStoreWriter(const char* filename, const ComputerStore& compPart) {
//	size_t size = std::strlen(filename) + 1;
//	this->filename = new char[size];
//	strcpy_s(this->filename, size, filename);
//
//	this->compStore = compStore;
//}

//ComputerStoreWriter::~ComputerStoreWriter() {
//	destroy();
//}
void ComputerStoreWriter::write(std::ofstream& os) {
	//Format
	/*
	<име на магазин>
		<работно време>
		<брой артикули>
		[
	{<тип> | <марка> | <модел> | <гаранция> | <цена>} <наличност>
	…
		]
	<оборот на магазина>*/

	size_t size = std::strlen(compStore.getName());
	os << size << compStore.getName() << std::endl;

	os << compStore.getWorkTime() << std::endl;
	os << compStore.getPartsCount() << std::endl;
	os << "[" << std::endl;

	for (size_t i = 0; i < compStore.getPartsCount(); i++) {
		os << " ";
		ComputerPartWriter(os, compStore.getParts()[i].computerPart);
		os << " " << compStore.getParts()[i].quantity << std::endl;
	}

	os << "]" << std::endl;
	os << compStore.getTurnover();
}

//void ComputerStoreWriter::destroy() {
//	if (filename != nullptr) {
//		delete[] filename;
//	}
//}
