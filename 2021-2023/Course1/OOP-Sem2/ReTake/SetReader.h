//
// Created by Sybatron on 8/6/2022.
//

#ifndef RETAKEHW_SETREADER_H
#define RETAKEHW_SETREADER_H

#include <fstream>
#include <stdexcept>

#include "Set.h"
#include "FiniteSet.h"
#include "CriteriaSet.h"

template<typename T = int>
class SetReader {
private:
    Set<T> *resultSet;
public:
    SetReader(std::ifstream &reader);

    ~SetReader();

    size_t getEqualElementsCount(const T *data, size_t size);

private:
    void readSet(std::ifstream &reader, const bool isItFirst);

    void calculateResult(const T *data, const short operationType, const short numCount, const bool isItFirst);
};


#include "SetReader.inl"

#endif //RETAKEHW_SETREADER_H
