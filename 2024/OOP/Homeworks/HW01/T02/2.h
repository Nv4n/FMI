//
// Created by Sybatron on 4/15/2024.
//

#ifndef OOPSTRUCTURES_MODIFIABLEINTEGERFUNCTION_H
#define OOPSTRUCTURES_MODIFIABLEINTEGERFUNCTION_H

#pragma once

#include <iostream>

using INTEGER_FUNCTION = short (*)(short);
struct SpecificValuePair {
    short inputValue;
    short outputValue;
};

class ModifiableIntegerFunction {
private:
    INTEGER_FUNCTION func;
    SpecificValuePair *specificVals;
    short *excludedVals;
    size_t specificValsLength;
    size_t specificValsCapacity;
    size_t excludedValsLength;
    size_t excludedValsCapacity;
public:
    ModifiableIntegerFunction(INTEGER_FUNCTION func);

    ModifiableIntegerFunction(const ModifiableIntegerFunction &other);

    ModifiableIntegerFunction operator=(const ModifiableIntegerFunction &other);

    virtual ~ModifiableIntegerFunction();

    short apply(short input);

ModifiableIntegerFunction 
private:
    void destroy();

    void copy(const ModifiableIntegerFunction &other); //TODO
};


#endif //OOPSTRUCTURES_MODIFIABLEINTEGERFUNCTION_H
