//
// Created by Sybatron on 4/15/2024.
//

#include "2.h"

ModifiableIntegerFunction::ModifiableIntegerFunction(INTEGER_FUNCTION func) : func(func) {}

ModifiableIntegerFunction::~ModifiableIntegerFunction() {
    destroy();
}

ModifiableIntegerFunction::ModifiableIntegerFunction(const ModifiableIntegerFunction &other) {
    copy(other);
}

ModifiableIntegerFunction ModifiableIntegerFunction::operator=(const ModifiableIntegerFunction &other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

void ModifiableIntegerFunction::destroy() {
    delete[] excludedVals;
    delete[]specificVals;
    excludedVals = nullptr;
    specificVals = nullptr;
}

void ModifiableIntegerFunction::copy(const ModifiableIntegerFunction &other) {
    excludedValsLength = other.excludedValsLength;
    excludedValsCapacity = other.excludedValsCapacity;
    specificValsLength = other.specificValsLength;
    specificValsCapacity = other.specificValsCapacity;

    func = other.func;
}

short ModifiableIntegerFunction::apply(short input) {
    return func(input);
}
