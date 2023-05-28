//
// Created by Sybatron on 5/25/2023.
//

#include <iostream>
#include <stdexcept>
#include <cstring>
#include "MinString.h"

MinString::MinString() {
    length = 0;
    size = 8;
    data = new char[size];

}

MinString::~MinString() {
    destroy();
}

// Copy
MinString::MinString(const char *_data) {
    copy(_data);
}

MinString::MinString(const MinString &other) {
    copy(other);
}

MinString &MinString::operator=(const MinString &other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

MinString &MinString::operator=(const char *_data) {
    if (std::strcmp(data, _data) != 0) {
        destroy();
        copy(_data);
    }
    return *this;
}

// Move
MinString::MinString(MinString &&other) noexcept {
    move(other);
}

MinString &MinString::operator=(MinString &&other) noexcept {
    if (this != &other) {
        destroy();
        move(other);
    }
    return *this;
}

// Getter and setters
size_t MinString::getLength() const {
    return length;
}

/**
 *
 * @param index
 * @return <b>sybmbol on index position</b>
 * @throw out_of_range("Index out of range");
 */
char MinString::operator[](size_t index) {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}


void MinString::erase() {
    delete[] data;
    length = 0;
    size = 8;
    data = new char[size];
}


// Operators
MinString &operator+(const MinString &lvs, const MinString &rvs) {
    MinString result;
    result += lvs;
    result += rvs;
    return result;
}

MinString &MinString::operator+=(const MinString &other) {
    size_t minLength = length + other.length + 1;
    if (minLength < size) {
        scaleUp(minLength);
    }
    std::strcat(data, other.data);
    length += other.length;

    return *this;
}

MinString &operator+(const MinString &lvs, const char *&_data) {
    MinString result;
    result += lvs;
    result += _data;
    return result;
}

MinString &MinString::operator+=(const char *&_data) {
    size_t _dataLength = std::strlen(_data);
    size_t minLength = length + _dataLength + 1;
    if (minLength < size) {
        scaleUp(minLength);
    }
    std::strcat(data, _data);
    length += _dataLength;

    return *this;
}


// Comparators
bool operator==(const MinString &lvs, const MinString &rvs) {
    return std::strcmp(lvs.data, rvs.data) == 0;
}

bool operator!=(const MinString &lvs, const MinString &rvs) {
    return !(lvs == rvs);
}

bool operator>(const MinString &lvs, const MinString &rvs) {
    return std::strcmp(lvs.data, rvs.data) > 0;
}

bool operator>=(const MinString &lvs, const MinString &rvs) {
    return lvs > rvs && lvs == rvs;
}

bool operator<(const MinString &lvs, const MinString &rvs) {
    return !(lvs >= rvs);
}

bool operator<=(const MinString &lvs, const MinString &rvs) {
    return !(lvs > rvs);
}


// Read and write
std::istream &operator>>(std::istream &is, MinString &str) {
    const int bufferSize = 1024;
    char buffer[bufferSize];
    int i = 0;

    while (i < bufferSize - 1) {
        char ch;
        is.get(ch);
        if (ch == '\n' || ch == '\0')
            break;
        buffer[i++] = ch;
    }

    buffer[i] = '\0';
    str = buffer;

    return is;
}

std::ostream &operator<<(std::ostream &os, const MinString &str) {
    os << str.data;
    return os;
}


// Private methods
void MinString::copy(const MinString &other) {
    length = other.length;
    size = other.size;
    data = new char[size];
    std::strcpy(data, other.data);
}

void MinString::copy(const char *_data) {
    length = std::strlen(_data);
    size = length + 1;
    data = new char[size];
    std::strcpy(data, _data);
}


void MinString::move(MinString &other) noexcept {
    length = other.length;
    size = other.size;
    data = other.data;
    other.length = 0;
    other.size = 8;
    other.data = new char[other.size];
}

void MinString::destroy() {
    delete[] data;
}

void MinString::scaleUp(size_t minLength) {
    if (minLength != 0 && size * 2 < minLength) {
        size = minLength * 2;
    } else {
        size *= 2;
    }
    char *tmp = new char[size];
    for (int i = 0; i < length; ++i) {
        tmp[i] = data[i];
    }
    delete[]data;
    data = tmp;
}
