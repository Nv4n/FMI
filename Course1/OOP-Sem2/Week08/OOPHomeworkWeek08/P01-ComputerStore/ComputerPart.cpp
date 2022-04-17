#include <iostream>
#include <stdexcept>
#include <cstring>
#include "ComputerPart.h"

//Contructors
#pragma region Ctors
ComputerPart::ComputerPart() :type(PartType::UNKNOWN),
warranty(0),
price(0),
brand(nullptr),
model(nullptr) {}

#pragma region Ctors
ComputerPart::ComputerPart(ComputerPart& other) {
	copy(other);
}
ComputerPart::ComputerPart(PartType type, short warranty, double price, char* brand, char* model) {
	setType(type);
	setWarranty(warranty);
	setPrice(price);
	setBrand(brand);
	setModel(model);
}
ComputerPart& ComputerPart::operator=(const ComputerPart& other) {
	if (this != &other) {
		destroy();
		copy(other);
	}

	return *this;
}
ComputerPart::~ComputerPart() {
	destroy();
}
#pragma endregion

#pragma region Setters/Getters
void ComputerPart::setPrice(const double price) {
	if (price < 0) {
		throw new std::invalid_argument("Invalid price value!");
	}
	this->price = price;
}

PartType ComputerPart::getType()const {
	return type;
}
short ComputerPart::getWarranty()const {
	return warranty;
}
double ComputerPart::getPrice()const {
	return price;
}
const char* ComputerPart::getBrand()const {
	return brand;
}
const char* ComputerPart::getModel()const {
	return model;
}
#pragma endregion

#pragma region PrivateMethods
void ComputerPart::setType(const PartType type) {
	switch (type) {
	case PartType::CAMERA:
	case PartType::COMPUTER:
	case PartType::HEADPHONES:
	case PartType::KEYBOARD:
	case PartType::LAPTOP:
	case PartType::MONITOR:
	case PartType::MOUSE:
		this->type = type;
		break;
	default:
		throw new std::invalid_argument("Invalid part type value!");
		break;
	}
}
void ComputerPart::setWarranty(const short warranty) {
	this->warranty = warranty;
}
void ComputerPart::setBrand(const char* brand) {
	if (&(this->brand) != &brand) {
		if (this->brand != nullptr) {
			delete[] this->brand;
		}
		size_t size = std::strlen(brand) + 1;
		this->brand = new char[size];
		strcpy_s(this->brand, size, brand);
	}
}
void ComputerPart::setModel(const char* model) {
	if (&(this->model) != &model) {
		if (this->model != nullptr) {
			delete[] this->model;
		}
		size_t size = std::strlen(model) + 1;
		this->model = new char[size];
		strcpy_s(this->model, size, model);
	}
}

void ComputerPart::copy(const ComputerPart& other) {
	type = other.type;
	warranty = other.warranty;
	price = other.price;

	size_t size = std::strlen(other.brand) + 1;
	brand = new char[size];
	strcpy_s(brand, size, other.brand);

	size = std::strlen(other.model) + 1;
	model = new char[size];
	strcpy_s(model, size, other.model);
}

void ComputerPart::destroy() {
	if (brand != nullptr) {
		delete[] brand;
	}
	if (model != nullptr) {
		delete[] model;
	}
}
#pragma endregion