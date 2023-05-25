//
// Created by Sybatron on 5/25/2023.
//
#include <iostream>
#include <cstring>
#include <sstream>
#include "MinString.h"

MinString::MinString() {
    length = 0;
    size = 8;
    data = new char[size];

}

MinString::MinString(const char *_data) {
    length = strlen(_data);
    size = length + 1;
    data = new char[size];
    std::strcpy(data, _data);
}

bool operator==(const MinString &lhs, const MinString &rhs) {
    return std::strcmp(lhs.data, rhs.data) == 0;
}

std::istream &operator>>(std::istream &is, MinString &str) {
    const int bufferSize = 1024;
    char buffer[bufferSize];
    int i = 0;

    while (i < bufferSize - 1) {
        int ch = is.get();
        if (ch == '\n' || ch == '\0')
            break;
        buffer[i++] = ch;
    }

    buffer[i] = '\0';

    delete[] str.data;
    str.length = i;
    str.size = str.length + 1;
    str.data = new char[str.size];
    std::strcpy(str.data, buffer);

    return is;
}

std::ostream &operator<<(std::ostream &os, const MinString &str) {
    os << str.data;
    return os;
}

const char *MinString::getData() const {
    return data;
}

MinString::MinString(const MinString &other) {
    length = other.length;
    data = new char[length + 1];
    strcpy(data, other.data);
}
