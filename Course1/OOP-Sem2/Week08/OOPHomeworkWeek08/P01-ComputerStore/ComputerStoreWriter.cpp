#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstring>
#include "ComputerStoreWriter.h"

ComputerStoreWriter::ComputerStoreWriter(const char* filename, const ComputerStore& compPart) {
	size_t size = std::strlen(filename) + 1;
	this->filename = new char[size];
	strcpy_s(this->filename, size, filename);

	this->compStore = compStore;
}

ComputerStoreWriter::~ComputerStoreWriter() {
	if (os.is_open()) {
		close();
	}
	destroy();
}

void ComputerStoreWriter::save() {
	os.open(filename);
	if (!os.is_open()) {
		throw new std::exception("Failed write stream opening!");
		return;
	}
	//TODO!
	/*Format
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
		//compStore.getParts()->computerPart;
	}

	os << "]" << std::endl;
}

void ComputerStoreWriter::close() {
	os.close();
}
void ComputerStoreWriter::destroy() {
	if (filename != nullptr) {
		delete[] filename;
	}
}
