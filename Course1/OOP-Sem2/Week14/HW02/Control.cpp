//
// Created by Sybatron on 6/5/2022.
//

#include "Control.h"

Control::Control(const Control &other) {
    copy(other);
}

Control &Control::operator=(const Control &other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

Control::~Control() {
    destroy();
}

void Control::copy(const Control &other) {
    size_t size = std::strlen(other.text);
    text = new char[size + 1];
    std::strcpy(text, other.text);

    size = std::strlen(other.description);
    description = new char[size + 1];
    std::strcpy(description, other.description);

    controlId = other.controlId;
    position = other.position;
    this->size = other.size;
}


void Control::destroy() {
    if (text != nullptr) {
        delete[] text;
    }
    if (description != nullptr) {
        delete[] description;
    }
}

size_t Control::getControlId() const {
    return controlId;
}

const Coordinates &Control::getPosition() const {
    return position;
}

const Size &Control::getSize() const {
    return size;
}

const char *Control::getText() const {
    return text;
}

void Control::setPosition(size_t X, size_t Y) {
    position.x = X;
    position.y = Y;
}

void Control::setSize(size_t width, size_t height) {
    size.width = width;
    size.height = height;
}

void Control::setControlId() {
    controlId = Id++;
}