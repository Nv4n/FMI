//
// Created by Sybatron on 8/27/2024.
//

#include <vector>
#include "CellValueInterpreter.h"

Cell CellValueInterpreter::convertToCell(const std::string &cellInput) {
    std::string trimmed = trim(cellInput);

    if (isInteger(trimmed)) {
        int result = std::stoi(trimmed);
    }
    if (isFractional(trimmed)) {
        double result = std::stod(trimmed);
    }
    if (isString(trimmed)) {
        //TODO Just use trimmed
    }
//    if()
    return Cell();
}

/**
 *
 * @param trimmed Trimmed cell value as string
 * @return bool
 */
bool CellValueInterpreter::isInteger(const std::string &trimmed) {
    if (trimmed.empty()) {
        return false;
    }
    size_t index = 0;
    if (trimmed[0] == '+' || trimmed[0] == '-') {
        index = 1;
    }
    for (; index < trimmed.size(); ++index) {
        if (trimmed[index] < '0' || trimmed[index] > '9') {
            return false;
        }
    }
    return true;
}

/**
 *
 * @param trimmed Trimmed cell value as string
 * @return bool
 */
bool CellValueInterpreter::isFractional(const std::string &trimmed) {
    size_t dotCount = 0;
    if (trimmed.empty()) {
        return false;
    }
    size_t index = 0;
    if (trimmed[0] == '+' || trimmed[0] == '-') {
        if (trimmed.size() == 1) {
            return false;
        }
        index = 1;
    }
    if (trimmed[1] == '.') {
        return false;
    }
    for (; index < trimmed.size(); ++index) {
        if (trimmed[index] == '.') {
            dotCount++;
            if (index + 1 == trimmed.size()) {
                return false;
            }
            if (dotCount > 1) {
                return false;
            }
            continue;
        }

        if (trimmed[index] < '0' || trimmed[index] > '9') {
            return false;
        }
    }
    return true;
}

/**
 *
 * @param trimmed Trimmed cell value as string
 * @return bool
 */
bool CellValueInterpreter::isString(const std::string &trimmed) {
    if (trimmed.length() < 2) {
        return false;
    }

    if (trimmed.front() != '"' || trimmed.back() != '"') {
        return false;
    }

    for (size_t i = 1; i < trimmed.length() - 1; ++i) {
        if (trimmed[i] != '\\') {
            continue;
        }

        if (i + 1 >= trimmed.length() - 1 || (trimmed[i + 1] != '\\' && trimmed[i + 1] != '"')) {
            return false;
        }
        i++;
    }

    return true;
}

/**
 *
 * @param trimmed
 * @return bool
 */
bool CellValueInterpreter::isFormula(const std::string &trimmed) {
    if (trimmed.empty() || trimmed[0] != '=') {
        return false;
    }

    std::vector<std::string> tokens;
    std::string token;


    if (tokens.size() != 3) {
        return false;
    }
    
    if (!isInteger(tokens[0]) && !isCellCoordinates(tokens[0])) {
        return false;
    }

    if (!isInteger(tokens[2]) && !isCellCoordinates(tokens[2])) {
        return false;
    }

    if (!isOperator(tokens[1])) {
        return false;
    }

    return true;
}


/**
 *
 * @param trimmed
 * @return bool
 */
bool CellValueInterpreter::isOperator(const std::string &trimmed) {
    bool operatorExpr =
            trimmed == "+"
            || trimmed == "-"
            || trimmed == "*"
            || trimmed == "/"
            || trimmed == "=="
            || trimmed == "<="
            || trimmed == ">="
            || trimmed == ">"
            || trimmed == "<"
            || trimmed == "!=";
    return operatorExpr;
}

/**
 *
 * @param trimmed
 * @return
 */
bool CellValueInterpreter::isCellCoordinates(const std::string &trimmed) {
    if (trimmed[0] != 'R') {
        return false;
    }
    if (trimmed.size() < 4) {
        return false;
    }
    bool isStartOfCoord = true;
    bool hasCol = false;
    for (size_t ind = 0; ind < trimmed.size(); ++ind) {
        if (trimmed[ind] == 'C') {
            if (hasCol) {
                return false;
            }
            isStartOfCoord = true;
            hasCol = true;
            if (ind + 1 == trimmed.size()) {
                return false;
            }
            continue;
        }
        if (isStartOfCoord && (trimmed[ind] < '1' || trimmed[ind] > '9')) {
            return false;
        }
        if (!isStartOfCoord && (trimmed[ind] < '0' || trimmed[ind] > '9')) {
            return false;
        }
        isStartOfCoord = false;
    }
    return true;
}

/**
 *
 * @param cellInput
 * @return
 */
std::string CellValueInterpreter::trim(const std::string &cellInput) {
    size_t start = cellInput.find_first_not_of(" \t");
    if (start == std::string::npos) {
        return "";
    }
    size_t end = cellInput.find_last_not_of(" \t");
    return cellInput.substr(start, end - start + 1);

}




