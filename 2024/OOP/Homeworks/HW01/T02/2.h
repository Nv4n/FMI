//
// Created by Sybatron on 4/15/2024.
//

#ifndef OOPSTRUCTURES_MODIFIABLEINTEGERFUNCTION_H
#define OOPSTRUCTURES_MODIFIABLEINTEGERFUNCTION_H

#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>
#include <functional>
#include <cstdint>
#include <fstream>


using INTEGER_FUNCTION = std::function<int16_t(int16_t)>;
struct ChangedValueRes {
    int16_t inputValue;
    int16_t outputValue;
    bool isExcluded;
};

class ModifiableIntegerFunction {
private:
    INTEGER_FUNCTION func;
    ChangedValueRes *changedVals{};
    size_t length{};
    size_t capacity{};

public:
    ModifiableIntegerFunction(INTEGER_FUNCTION &func);

    ModifiableIntegerFunction(const ModifiableIntegerFunction &other);

    ModifiableIntegerFunction &operator=(const ModifiableIntegerFunction &other);

    virtual ~ModifiableIntegerFunction();

    int16_t apply(int16_t input) const;

    void specifyResult(int16_t input, int16_t result);

    void excludeInput(int16_t input);

    ModifiableIntegerFunction operator+(const ModifiableIntegerFunction &other);

    ModifiableIntegerFunction operator-(const ModifiableIntegerFunction &other);

    ModifiableIntegerFunction operator^(unsigned int power);

    ModifiableIntegerFunction compose(const ModifiableIntegerFunction &other);

    bool operator>(const ModifiableIntegerFunction &other) const;

    bool operator<(const ModifiableIntegerFunction &other) const;

    bool operator==(const ModifiableIntegerFunction &other) const;

    bool operator!=(const ModifiableIntegerFunction &other) const;

    bool operator<=(const ModifiableIntegerFunction &other) const;

    bool operator>=(const ModifiableIntegerFunction &other) const;

    ModifiableIntegerFunction inverse();

    bool isParallelPlot(const ModifiableIntegerFunction &other);

    bool isInjection();

    bool isSurjection();

    bool isBijection();

    void serialize(const char *fileName);

    void deserialize(const char *fileName);

    void plot(int16_t fromX, int16_t toX, int16_t fromY, int16_t toY);

private:
    void destroy();

    void copy(const ModifiableIntegerFunction &other);

    void resize();

//    void insert(int16_t input, int16_t value, bool isExcluded, size_t index);
};

#endif //OOPSTRUCTURES_MODIFIABLEINTEGERFUNCTION_H
