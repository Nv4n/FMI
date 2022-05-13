#include <iostream>
#include <cstring>
#include "Vehicle.h"


Vehicle::Vehicle() {
	_color = Color::UNKNOWN;
	_brand = nullptr;
	_prodYear = 0;
	_seatsCount = 0;
	_maxSpeed = 0;
}

Vehicle::Vehicle(const Vehicle& other) {
	copy(other);
}

Vehicle& Vehicle::operator=(const Vehicle& other) {
	if (this != &other) {
		destroy();
		copy(other);
	}

	return *this;
}

Vehicle::~Vehicle() {
	destroy();
}

void Vehicle::setColor(const Color color) {
	if (color > Color::UNKNOWN && color < Color::COUNT) {
		_color = color;
	}
	else {
		_color = Color::UNKNOWN;
	}
}

void Vehicle::setBrand(const char* brand) {
	if (_brand != nullptr && &_brand != &brand) {
		delete[] _brand;
		size_t size = std::strlen(brand) + 1;
		_brand = new char[size];
		std::strcpy(_brand, brand);
	}

}

Color Vehicle::getColor()
{
	return _color;
}

const char* Vehicle::getBrand() const
{
	return _brand;
}

size_t Vehicle::getProdYear()
{
	return _prodYear;
}

size_t Vehicle::getSeatsCount()
{
	return _seatsCount;
}

size_t Vehicle::getMaxSpeed()
{
	return _maxSpeed;
}

void Vehicle::destroy() {
	if (_brand != nullptr) {
		delete[] _brand;
	}
}

void Vehicle::copy(const Vehicle& other) {
	_color = other._color;

	size_t size = std::strlen(other._brand) + 1;
	_brand = new char[size];
	std::strcpy(_brand, other._brand);

	_prodYear = other._prodYear;
	_seatsCount = other._seatsCount;
	_maxSpeed = other._maxSpeed;
}
