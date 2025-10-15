//
// Created by Sybatron on 6/5/2022.
//

#include <cstring>
#include "Form.h"

Form::~Form() {
    destroy();
}

void Form::destroy() {

    delete[] controls;
    delete[] name;
}

Form::Form(const char *name) {
    size_t size = std::strlen(name);
    this->name = new char[size + 1];
    std::strcpy(this->name, name);

    capacity = 16;
    this->size = 0;
    controls = new Control *[capacity];
}

Form::Form(const Form &other) {
    copy(other);
}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

const Control *Form::operator[](size_t ind) const {
    if (ind < size) {
        return controls[ind];
    }
    return nullptr;
}

void Form::copy(const Form &other) {
    size_t size = std::strlen(other.name);
    name = new char[size + 1];
    std::strcpy(name, other.name);

    capacity = other.capacity;
    size = other.size;
    controls = new Control *[capacity];
    for (int i = 0; i < size; ++i) {
        controls[i] = other.controls[i];
    }
}

void Form::addControl(const Control *control) {
    if (control != nullptr) {
        if (size + 1 == capacity) {
            resize();
        }

        controls[size] = control->clone();
        size++;
    }

}

void Form::resize() {
    capacity *= 2;
    Control **tempControls = new Control *[capacity];
    for (int i = 0; i < size; ++i) {
        tempControls[i] = controls[i];
    }
    delete[]controls;
    controls = tempControls;
}

void Form::print() {
    for (int i = 0; i < size; ++i) {
        std::cout << controls[i]->print() << std::endl;
    }
}
