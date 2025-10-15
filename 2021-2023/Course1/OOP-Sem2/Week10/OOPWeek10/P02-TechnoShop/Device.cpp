#include <iostream>
#include <fstream>
#include "Device.h"

Device::Device(const Device& other) {
	copy(other);
}

Device& Device::operator=(const Device& other) {
	if (this != &other) {
		destroy();
		copy(other);
	}

	return *this;
}

Device::~Device() {
	destroy();
}

const char* Device::getModel() const {
	return _model;
}

const char* Device::getBrand() const {
	return _brand;
}

void Device::copy(const Device& other) {
	size_t size = std::strlen(other._model) + 1;
	_model = new char[size];
	std::strcpy(_model, other._model);

	size = std::strlen(other._brand) + 1;
	_brand = new char[size];
	std::strcpy(_brand, other._brand);

	price = other.price;
}

void Device::destroy() {
	if (_model != nullptr) {
		delete[] _model;
	}

	if (_brand != nullptr) {
		delete[] _brand;
	}
}
