//
// Created by Sybatron on 6/5/2022.
//
#include <iostream>
#include <cstring>
#include "Checkbox.h"

Checkbox::Checkbox(const Checkbox &other) {
    copy(other);
}

Checkbox &Checkbox::operator=(const Checkbox &other) {
    if (this != &other) {
        copy(other);
    }

    return *this;
}


Checkbox::Checkbox(const char *text, const size_t positionX, const size_t positionY, const bool isChecked) {
    setControlId();
    setPosition(positionX, positionY);

    size_t size = std::strlen(text);
    description = new char[size + 1];
    std::strcpy(description, text);

    this->text = new char[size + 5];
    for (int i = 4, j = 0; i < size + 4; ++i, ++j) {
        this->text[i] = description[j];
    }
    this->text[0] = '|';
    this->text[2] = '|';
    this->text[3] = ' ';
    if (isChecked) {
        this->text[1] = 'X';
    } else {
        this->text[1] = ' ';
    }

    setSize(size + 4, 1);

    this->isChecked = isChecked;
}

void Checkbox::copy(const Checkbox &other) {
    isChecked = other.isChecked;
}

Control *Checkbox::clone() const {
    return new Checkbox(*this);
}

Control *Checkbox::input() {
    char text[256];
    std::cin.ignore();
    std::cin.getline(text, 255);

    size_t positionX;
    std::cin >> positionX;
    size_t positionY;
    std::cin >> positionY;
    bool isChecked;
    std::cin >> isChecked;

    return new Checkbox(text, positionX, positionY, isChecked);
}
