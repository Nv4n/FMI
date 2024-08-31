//
// Created by Sybatron on 8/26/2024.
//

#ifndef ETABLES_CELL_H
#define ETABLES_CELL_H
#pragma once

#include <string>
#include <stdexcept>
#include "Utility.h"

using CellValues = union Data {
    int integer;
    double fractional;
    std::string text;

    Data() {};

    ~Data() {};
};

enum class CellType {
    NONE,
    INTEGER,
    FRACTIONAL,
    STRING,
    FORMULA,
};

class Cell {
private:
    struct CellData {
        CellType type;
        CellValues vals;
    } cellData;

public:
    Cell();

    Cell(const Cell &other);

    Cell &operator=(const Cell &other);

    virtual ~Cell();

    CellType getType() const;

    template<typename T>
    T get();

    template<typename T>
    void set(T val, CellType type);

    void reset();

    friend std::ofstream &operator<<(std::ofstream &ofs, const Cell &cell);

private:
    void copy(const Cell &other);

    void destroy();
};

/**
* @brief Get active value
 *
 * Gets active value when there is such one
 * and requested type aligns with the active value type
 *
* @tparam T requested type
 *
* @return value active value
 *
* @throws logic_error When the active value type is not same with requested type
 *
 *@throws logic_error When active value is empty
 *
* @throws logic_error When requested type is invalid
*/
template<typename T>
T Cell::get() {
    if constexpr (is_same<T, int>::value) {
        if (cellData.type != CellType::INTEGER) {
            throw std::logic_error("active value is not integer");
        }
        return cellData.vals.integer;
    }
    if constexpr (is_same<T, double>::value) {
        if (cellData.type != CellType::FRACTIONAL) {
            throw std::logic_error("active value is not fractional");
        }
        return cellData.vals.fractional;
    }
    if constexpr (is_same<T, std::string>::value) {
        if (cellData.type != CellType::STRING && cellData.type != CellType::FORMULA) {
            throw std::logic_error("active value is not string or formula");
        }
        return cellData.vals.text;
    }
    if (cellData.type == CellType::NONE) {
        throw std::logic_error("active value is empty");
    }

    throw std::logic_error("invalid return type");
}

/**
 *@brief Setter for new active value in Cell
 *
 * @tparam T the type of the new value
 * @param val new value
 * @param type Cell type of the value
 *
 * @throws logic_error When requested type doesn't match the given CellType
 * @throws logic_error When there is no matching type
 */
template<typename T>
void Cell::set(T val, CellType type) {
    if constexpr (is_same<T, int>::value) {
        if (type != CellType::INTEGER) {
            throw std::logic_error("can't save integer as non-CellType::INTEGER");
        }
        destroy();
        cellData.type = type;
        cellData.vals.integer = val;
        return;
    }

    if constexpr (is_same<T, double>::value) {
        if (type != CellType::FRACTIONAL) {
            throw std::logic_error("can't save fractional as non-CellType::FRACTIONAL");
        }
        destroy();
        cellData.type = type;
        cellData.vals.fractional = val;
        return;
    }

    if constexpr (is_same<T, std::string>::value) {
        if (type != CellType::STRING && type != CellType::FORMULA) {
            throw std::logic_error("can't save text as non-CellType::STRING or CellType::FORMULA");
        }

        destroy();
        cellData.type = type;
        new(&cellData.vals.text)std::string(val);
        return;
    }

    throw std::logic_error("invalid new value type");
}

#endif //ETABLES_CELL_H
