//
// Created by Sybatron on 8/27/2024.
//

#include "CellValueInterpreter.h"

bool CellValueInterpreter::isInteger(const std::string &cellInput) {
    if (cellInput.empty()) {
        return false;
    }
    size_t index = 0;
    if (cellInput[0] == '+' || cellInput[0] == '-') {
        index = 1;
    }
    for (; index < cellInput.size(); ++index) {
        if (cellInput[index] < '0' || cellInput[index] > '9') {
            return false;
        }
    }
    return true;
}

bool CellValueInterpreter::isFractional(const std::string &cellInput) {
    size_t dotCount = 0;
    if (cellInput.empty()) {
        return false;
    }
    size_t index = 0;
    if (cellInput[0] == '+' || cellInput[0] == '-') {
        if (cellInput.size() == 1) {
            return false;
        }
    }
    if (cellInput[1] == '.') {
        return false;
    }
    for (; index < cellInput.size(); ++index) {
        if (cellInput[index] == '.') {
            dotCount++;
            if (index + 1 == cellInput.size()) {
                return false;
            }
        }
        if (dotCount > 1) {
            return false;
        }
        if (cellInput[index] != '.'
            && (cellInput[index] < '0' || cellInput[index] > '9')) {
            return false;
        }
    }
    return true;
}

std::string CellValueInterpreter::trim(const std::string &cellInput) {
    size_t start = cellInput.find_first_not_of(" \t");
    if (start == std::string::npos) {
        return "";
    }
    size_t end = cellInput.find_last_not_of(" \t");
    return cellInput.substr(start, end - start + 1);

}

Cell CellValueInterpreter::convertToCell(const std::string &cellInput) {
    std::string trimmed = trim(cellInput);

    if (isInteger(trimmed)) {
        int result = std::stoi(trimmed);
    }
    if (isFractional(trimmed)) {
        int result = std::stod(trimmed);
    }
    return Cell();
}
