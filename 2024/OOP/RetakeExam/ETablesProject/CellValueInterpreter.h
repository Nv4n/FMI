//
// Created by Sybatron on 8/27/2024.
//

#ifndef ETABLES_CELLVALUEINTERPRETER_H
#define ETABLES_CELLVALUEINTERPRETER_H

#pragma once

#include "Cell.h"

class CellValueInterpreter {
public:
    Cell convertToCell(const std::string &cellInput);

private:
    bool isInteger(const std::string &trimmed);

    bool isFractional(const std::string &trimmed);

    bool isString(const std::string &trimmed);

    bool isFormula(const std::string &trimmed);

    bool isCellCoordinates(const std::string &trimmed);

    bool isOperator(const std::string &trimmed);

    std::string trim(const std::string &cellInput);
};


#endif //ETABLES_CELLVALUEINTERPRETER_H
