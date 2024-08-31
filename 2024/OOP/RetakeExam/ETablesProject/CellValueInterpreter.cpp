//
// Created by Sybatron on 8/27/2024.
//

#include <vector>
#include "CellValueInterpreter.h"

/**
 * @brief Converting string value to CellValue
 * @param cellInput Initial cell value as string
 * @return Processed string value as Cell
 * @throws invalid_argument When it was given invalid cell value
 */
Cell CellValueInterpreter::convertToCell(const std::string &cellInput) {
    std::string trimmed = trim(cellInput);
    Cell cell;
    if (trimmed.empty()) {
        return cell;
    }

    if (isInteger(trimmed)) {
        int val = std::stoi(trimmed);
        cell.set<int>(val, CellType::INTEGER);
    } else if (isFractional(trimmed)) {
        double val = std::stod(trimmed);
        cell.set<double>(val, CellType::FRACTIONAL);
    } else if (isString(trimmed)) {
        //Trim 2 "
        cell.set<std::string>(trimmed.substr(1, trimmed.size() - 2), CellType::STRING);
    } else if (isFormula(trimmed)) {
        cell.set<std::string>(trimmed, CellType::FORMULA);
    } else {
        throw std::invalid_argument("Invalid cell value");
    }
    return cell;
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
        if (trimmed.size() <= 1) {
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

        if (i + 2 >= trimmed.length()) {
            return false;
        }
        if (trimmed[i + 1] != '\\' && trimmed[i + 1] != '"') {
            return false;
        }
        i++;
    }

    return true;
}

/**
 *
 * @param trimmed Trimmed cell value as string
 * @return bool
 */
bool CellValueInterpreter::isFormula(const std::string &trimmed) {
    if (trimmed.empty() || trimmed[0] != '=') {
        return false;
    }

    std::vector<std::string> tokens = splitStringBySpace(trimmed);


    if (tokens.size() != 4) {
        return false;
    }

    const short VALUE1_INDEX = 1;
    const short VALUE2_INDEX = 3;
    const short OPERATOR_INDEX = 2;
    //=, VAL1, Operator, VAL2
    if (!isFractional(tokens[VALUE1_INDEX])
        && !isInteger(tokens[VALUE1_INDEX])
        && !isCellCoordinates(tokens[VALUE1_INDEX])) {
        return false;
    }

    if (!isFractional(tokens[VALUE2_INDEX])
        && !isInteger(tokens[VALUE2_INDEX])
        && !isCellCoordinates(tokens[VALUE2_INDEX])) {
        return false;
    }

    if (!isOperator(tokens[OPERATOR_INDEX])) {
        return false;
    }

    return true;
}

std::vector<std::string> CellValueInterpreter::splitStringBySpace(const std::string &trimmed) {
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = 0;

    while ((end = trimmed.find(' ', start)) != std::string::npos) {
        tokens.push_back(trimmed.substr(start, end - start));
        start = end + 1;
    }

    // Add the last word
    tokens.push_back(trimmed.substr(start));

    return tokens;
}

/**
 *
 * @param trimmed Trimmed cell value as string
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
 * @param trimmed Trimmed cell value as string
 * @return bool
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
    for (size_t ind = 1; ind < trimmed.size(); ++ind) {
        if (trimmed[ind] == 'R') {
            return false;
        }
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
 * @param cellInput Not trimmed cell input
 * @return string Trimmed cellInput
 */
std::string CellValueInterpreter::trim(const std::string &cellInput) {
    size_t start = cellInput.find_first_not_of(" \t");
    if (start == std::string::npos) {
        return "";
    }
    size_t end = cellInput.find_last_not_of(" \t");
    return cellInput.substr(start, end - start + 1);

}




