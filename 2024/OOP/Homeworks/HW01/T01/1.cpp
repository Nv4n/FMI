//
// Created by Sybatron on 4/15/2024.
//

#include "1.h"

MultiSet::MultiSet(unsigned int maxValue, unsigned char valueCountBitSize) :
        maxValue(maxValue), valueCountBitSize(valueCountBitSize) {
    length = 0;
    capacity = 8;
    data = new unsigned int[capacity];
    dataCount = new unsigned char[dataCount];
}

MultiSet::MultiSet(const MultiSet &other) {
    copy(other);
}

MultiSet &MultiSet::operator=(const MultiSet &other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

MultiSet::~MultiSet() {
    destroy();
}

void MultiSet::copy(const MultiSet &other) {
    valueCountBitSize = other.valueCountBitSize;
    maxValue = other.maxValue;

    capacity = other.capacity;
    length = other.length;
    data = new unsigned int[capacity];
    for (size_t i = 0; i < length; ++i) {
        data[i] = other.data[i];
    }
}

void MultiSet::destroy() {
    delete[] data;
    data = nullptr;
}

void MultiSet::resize() {
    capacity *= 2;
    unsigned int *temp = new unsigned int[capacity];
    for (size_t i = 0; i < length; ++i) {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
}

std::ifstream &operator>>(std::ifstream &reader, const MultiSet &set) {

    return reader;
}

std::ofstream &operator<<(std::ofstream &writer, const MultiSet &set) {
    writer.write(reinterpret_cast<const char *>(set.maxValue), sizeof(set.maxValue));
    writer.write(reinterpret_cast<const char *>(set.valueCountBitSize), sizeof(set.maxValue));
    writer.write(reinterpret_cast<const char *>(set.maxValue), sizeof(set.maxValue));
    writer.write(reinterpret_cast<const char *>(set.maxValue), sizeof(set.maxValue));
    writer.write(reinterpret_cast<const char *>(set.maxValue), sizeof(set.maxValue));

    return writer;
}

