//
// Created by Sybatron on 4/15/2024.
//

#include "2.h"

ModifiableIntegerFunction::ModifiableIntegerFunction(INTEGER_FUNCTION &func) {
    this->func = func;
    length = 0;
    capacity = 8;
    changedVals = new ChangedValueRes[capacity];
}

ModifiableIntegerFunction::ModifiableIntegerFunction(const ModifiableIntegerFunction &other) {
    copy(other);
}

ModifiableIntegerFunction &ModifiableIntegerFunction::operator=(const ModifiableIntegerFunction &other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

ModifiableIntegerFunction::~ModifiableIntegerFunction() {
    destroy();
}

int16_t ModifiableIntegerFunction::apply(int16_t input) {
    for (int i = 0; i < length; ++i) {
        if (changedVals[i].inputValue != input) {
            continue;
        }
        if (changedVals[i].isExcluded) {
            throw std::out_of_range("Function is not defined for this input");
        }
        return changedVals[i].outputValue;
    }
    return func(input);
}

void ModifiableIntegerFunction::specifyResult(int16_t input, int16_t result) {
    for (int i = 0; i < length; ++i) {
        if (changedVals[i].inputValue != input) {
            continue;
        }
        changedVals[i].outputValue = result;
        changedVals[i].isExcluded = false;
        return;
    }
    if (length >= capacity) {
        resize();
    }
    changedVals[length].inputValue = input;
    changedVals[length].outputValue = result;
    changedVals[length].isExcluded = false;
    length++;
}

void ModifiableIntegerFunction::excludeInput(int16_t input) {
    for (int i = 0; i < length; ++i) {
        if (changedVals[i].inputValue != input) {
            continue;
        }
        changedVals[i].isExcluded = true;
        return;
    }
    if (length >= capacity) {
        resize();
    }
    changedVals[length].inputValue = input;
    changedVals[length].isExcluded = true;
    length++;
}

ModifiableIntegerFunction ModifiableIntegerFunction::operator^(unsigned int power) {
    ModifiableIntegerFunction result(*this);
    INTEGER_FUNCTION savedFunc = func;
    result.func = [power, savedFunc](int16_t x) -> int16_t {
        int16_t res = x;
        for (int i = 0; i < power; ++i) {
            res = savedFunc(res);
        }
        return res;
    };
    return result;
}

//TODO  add specific values from other in + and - and compose
ModifiableIntegerFunction ModifiableIntegerFunction::operator+(const ModifiableIntegerFunction &other) {
    ModifiableIntegerFunction result(*this);
    INTEGER_FUNCTION savedThisFunc = func;
    INTEGER_FUNCTION savedOtherFunc = other.func;
    result.func = [savedThisFunc, savedOtherFunc](int16_t x) -> int16_t {
        return static_cast<int16_t>(savedThisFunc(x) + savedOtherFunc(x));
    };
    for (int i = 0; i < ; ++i) {
        
    }
    return result;
}

ModifiableIntegerFunction ModifiableIntegerFunction::operator-(const ModifiableIntegerFunction &other) {
    ModifiableIntegerFunction result(*this);
    INTEGER_FUNCTION savedThisFunc = func;
    INTEGER_FUNCTION savedOtherFunc = other.func;
    result.func = [savedThisFunc, savedOtherFunc](int16_t x) -> int16_t {
        return static_cast<int16_t>(savedThisFunc(x) - savedOtherFunc(x));
    };
    return result;
}

ModifiableIntegerFunction ModifiableIntegerFunction::compose(const ModifiableIntegerFunction &other) {
    ModifiableIntegerFunction result(*this);
    INTEGER_FUNCTION savedThisFunc = func;
    INTEGER_FUNCTION savedOtherFunc = other.func;
    result.func = [savedThisFunc, savedOtherFunc](int16_t x) -> int16_t {
        return savedThisFunc(savedOtherFunc(x));
    };
    return result;
}

void ModifiableIntegerFunction::destroy() {
    delete[]changedVals;
}

void ModifiableIntegerFunction::copy(const ModifiableIntegerFunction &other) {
    func = other.func;
    length = other.length;
    capacity = other.capacity;
    changedVals = new ChangedValueRes[capacity];
    for (size_t i = 0; i < length; ++i) {
        changedVals[i].inputValue = other.changedVals[i].inputValue;
        changedVals[i].outputValue = other.changedVals[i].outputValue;
        changedVals[i].isExcluded = other.changedVals[i].isExcluded;
    }
}

void ModifiableIntegerFunction::resize() {
    capacity *= 2;
    ChangedValueRes *temp = new ChangedValueRes[capacity];
    for (int i = 0; i < length; ++i) {
        temp[i].inputValue = changedVals[i].inputValue;
        temp[i].outputValue = changedVals[i].outputValue;
        temp[i].isExcluded = changedVals[i].isExcluded;
    }
    delete[] changedVals;
    changedVals = temp;
}

void ModifiableIntegerFunction::insert(int16_t input, int16_t value, bool isExcluded, size_t index) {
    if (length >= capacity) {
        return;
    }
    for (size_t i = length; i > index; --i) {
        changedVals[i].inputValue = changedVals[i - 1].inputValue;
        changedVals[i].outputValue = changedVals[i - 1].outputValue;
        changedVals[i].isExcluded = changedVals[i - 1].isExcluded;
    }
    changedVals[index].inputValue = input;
    changedVals[index].outputValue = value;
    changedVals[index].isExcluded = isExcluded;
}







