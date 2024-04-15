//
// Created by Sybatron on 4/15/2024.
//

#ifndef OOPSTRUCTURES_МULTISET_H
#define OOPSTRUCTURES_МULTISET_H
#pragma once

#include <iostream>
#include <fstream>

class MultiSet {
private:
    unsigned int maxValue;
    unsigned char valueCountBitSize;
    unsigned int *data;
    unsigned char *dataCount;
    size_t length;
    size_t capacity;
public:
    MultiSet(unsigned int maxValue, unsigned char valueCountBitSize);

    MultiSet(const MultiSet &other);

    MultiSet &operator=(const MultiSet &other);

    virtual ~MultiSet();

    friend std::ofstream &operator<<(std::ofstream &writer, const MultiSet &set);

    friend std::ifstream &operator>>(std::ifstream &reader, const MultiSet &set);


private:
    void copy(const MultiSet &other);

    void destroy();

    void resize();
};


#endif //OOPSTRUCTURES_МULTISET_H
