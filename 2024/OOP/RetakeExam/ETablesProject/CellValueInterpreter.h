//
// Created by Sybatron on 8/27/2024.
//

#ifndef ETABLES_CELLVALUEINTERPRETER_H
#define ETABLES_CELLVALUEINTERPRETER_H

#pragma once

#include "Cell.h"

class CellValueInterpreter {
public:
    static Cell convertToCell(const std::string &cellInput);

private:
    static bool isInteger(const std::string &trimmed);

    static bool isFractional(const std::string &trimmed);

    static bool isString(const std::string &trimmed);

    static bool isFormula(const std::string &trimmed);

    static bool isCellCoordinates(const std::string &trimmed);

    static bool isOperator(const std::string &trimmed);

    static std::string trim(const std::string &cellInput);
};


#endif //ETABLES_CELLVALUEINTERPRETER_H
