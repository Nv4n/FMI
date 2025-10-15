#include <iostream>
#include <cstring>
#include <fstream>
#include <stdexcept>
#include "String.h"


String::String() :_data(nullptr), _size(0), _capacity(0)
{
}

String::String(const String& other) {
	copy(other);
}

String& String::operator=(const String& other) {
	if (this != &other) {
		destroy();
		copy(other);
	}
	return *this;
}

String::~String() {
	destroy();
}

void String::append(const String& other) {
	append(other._data);
}

void String::append(const char* other) {
	size_t size = std::strlen(other);
	if (_size + size > _capacity) {
		_capacity += (_size + size);
		resize();
	}

	for (size_t dataIndex = _size, copyIndex = 0; dataIndex < _size + size; dataIndex++, copyIndex++) {
		_data[dataIndex] = other[copyIndex];
	}
	_size += size;
}

void String::append(char other) {
	if (_size + 1 > _capacity) {
		_capacity += (_size + 1);
		resize();
	}

	_data[_size] = other;
	_size++;
}

const char& String::operator[](size_t index) const
{
	if (index >= _size) {
		throw std::invalid_argument("Index is out of range");
	}
	return _data[index];
}

char& String::operator[](size_t index) {
	if (index >= _size) {
		throw std::invalid_argument("Index is out of range");
	}
	return _data[index];
}

size_t String::length()
{
	return _size;
}

void String::resize() {
	_capacity *= 2;
	char* resizeArr = new char[_capacity];
	for (size_t i = 0; i < _size; i++) {
		resizeArr[i] = _data[i];
	}
	delete[] _data;
	_data = resizeArr;
}

void String::copy(const String& other) {
	_size = other._size;
	_capacity = other._capacity;
	_data = new char[_capacity];
	std::strcpy(_data, other._data);
}

void String::destroy() {
	if (_data != nullptr) {
		delete[] _data;
	}
}

bool operator==(const String& lvalue, const String& rvalue) {

	return std::strcmp(lvalue._data, rvalue._data);
}

bool operator!=(const String& lvalue, const String& rvalue) {
	return !(lvalue == rvalue);
}

void operator<<(std::ostream& os, const String& str) {
	os << str;
}

void operator>>(std::istream& is, String& str) {
	is >> str._data;
	str._size;
}
//TODO