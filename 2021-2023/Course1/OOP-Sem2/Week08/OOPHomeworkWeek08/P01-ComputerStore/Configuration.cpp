#include<iostream>
#include<cstring>
#include <stdexcept>
#include "Configuration.h"

#pragma region Ctors
Configuration::Configuration() {
	std::cout << "Enter initial items count: ";
	std::cin >> size;
	capacity = size * 2;
	items = new Item[size];

	for (size_t i = 0; i < size; i++) {
		int type;
		short warranty;
		double price;

		std::cout << "Enter type: MONITOR = 0\nCOMPUTER = 1\nLAPTOP = 2\nMOUSE = 3\nKEYBOARD = 4\nHEADPHONES = 5\nCAMERA = 6";
		std::cin >> type;

		std::cout << "Enter warranty: ";
		std::cin >> warranty;

		std::cout << "Enter price: ";
		std::cin >> price;


		size_t length;
		std::cout << "Enter brand_length: ";
		std::cin >> length;
		char* brand = new char[length + 1];
		std::cout << "Enter brand: ";
		std::cin.ignore();
		std::cin.getline(brand, length);

		std::cout << "Enter model_length: ";
		std::cin >> length;

		char* model = new char[length + 1];
		std::cout << "Enter model: ";
		std::cin.ignore();
		std::cin.getline(model, length);

		std::cout << "Enter item's quantity: ";
		std::cin >> items[i].quantity;

		std::cout << "----------------------" << std::endl;
		ComputerPart temp((PartType)type, warranty, price, brand, model);
		items[i].computerPart = temp;
	}
}
Configuration::Configuration(size_t size, Item* items) {
	this->size = size;
	this->capacity = size * 2;
	this->items = new Item[capacity];
	for (size_t i = 0; i < size; i++) {
		this->items[i].computerPart = items[i].computerPart;
		this->items[i].quantity = items[i].quantity;
	}
}
Configuration::Configuration(const Configuration& other) {
	copy(other);
}

Configuration& Configuration::operator=(const Configuration& other) {
	if (this != &other) {
		destroy();
		copy(other);
	}
	return *this;
}

Configuration::~Configuration() {
	destroy();
}
#pragma endregion

Item& Configuration::operator[](size_t index) {
	if (index >= size) {
		throw new std::out_of_range("Index out of items' range");
	}

	return items[index];
}

#pragma region PrivateMethods

void Configuration::resize() {
	capacity *= 2;
}
void Configuration::copy(const Configuration& other) {
	size = other.size;
	capacity = other.capacity;

	items = new Item[capacity];
	for (size_t i = 0; i < size; i++) {
		items[i].computerPart = other.items[i].computerPart;
		items[i].quantity = other.items[i].quantity;
	}
}
void Configuration::destroy() {
	delete[] items;
}
#pragma endregion