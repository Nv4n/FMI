//
// Created by Sybatron on 8/26/2024.
//

#include "Cell.h"

Cell::Cell() {
    cell.type = CellType::NONE;
}

Cell::~Cell() {
    destroy();
}

Cell::Cell(const Cell &other) {
    copy(other);
}

Cell &Cell::operator=(const Cell &other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

/**
 *
 * @return CellType Type for the cell value interpreter
 */
CellType Cell::getType() const {
    return cell.type;
}

/**
 * @brief Reset Cell to default values
 */
void Cell::reset() {
    destroy();
    cell.type = CellType::NONE;
}

/**
 * @brief Copy the data from Cell other with
 * allocating memory for std::string
 *
 * @param other The Cell that should be coppied
 */
void Cell::copy(const Cell &other) {
    cell.type = other.cell.type;
    if (cell.type == CellType::FORMULA || cell.type == CellType::STRING) {
        new(&cell.vals.text)std::string(other.cell.vals.text);
        return;
    }
    if (cell.type == CellType::INTEGER) {
        cell.vals.integer = other.cell.vals.integer;
        return;
    }
    if (cell.type == CellType::FRACTIONAL) {
        cell.vals.fractional = other.cell.vals.fractional;
    }
}

void Cell::destroy() {
    if (cell.type == CellType::STRING || cell.type == CellType::FORMULA) {
        cell.vals.text.~basic_string<char>();
    }
}
