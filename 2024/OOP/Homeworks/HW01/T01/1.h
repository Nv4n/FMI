//
// Created by Sybatron on 4/15/2024.
//

#ifndef OOPSTRUCTURES_MULTISET_H
#define OOPSTRUCTURES_MULTISET_H
#pragma once

#include <iostream>
#include <fstream>
#include <exception>
#include <stdexcept>


class MultiSet {
private:
    struct DataFrequency {
        unsigned int number;
        unsigned char frequency;
    };
    unsigned int maxNumber{};
    unsigned char maxFrequency{};
    DataFrequency *data{};
    size_t length{};
    size_t capacity{};

    MultiSet();

public:
    MultiSet(unsigned int maxNumber, unsigned char frequencyBits);

    MultiSet(const MultiSet &other);

    MultiSet &operator=(const MultiSet &other);

    virtual ~MultiSet();

    void add(unsigned int number);

    unsigned char frequencyOf(unsigned int number);

    void printAllNumbers();

    void printMemoryRepresentation();

    MultiSet intersect(const MultiSet &other);

    MultiSet except(const MultiSet &other);

    friend std::ofstream &operator<<(std::ofstream &writer, const MultiSet &set);

    friend std::ifstream &operator>>(std::ifstream &reader, const MultiSet &set);

    MultiSet addition();

private:
    void copy(const MultiSet &other);

    void destroy();

    void resize();

    void insertNumber(unsigned int number, unsigned char frequency, size_t index);

    unsigned char frequencyBits();

    void add(unsigned int number, unsigned char frequency);
};


#endif //OOPSTRUCTURES_MULTISET_H
