//
// Created by Sybatron on 8/26/2024.
//

#include "Cell.h"
#include <fstream>

Cell::Cell() {
    cellData.type = CellType::NONE;
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
    return cellData.type;
}

/**
 * @brief Reset Cell to default values
 */
void Cell::reset() {
    destroy();
    cellData.type = CellType::NONE;
}

std::ofstream &operator<<(std::ofstream &ofs, const Cell &cell) {
    if (cell.getType() == CellType::INTEGER) {
        ofs << cell.cellData.vals.integer;
    } else if (cell.getType() == CellType::FRACTIONAL) {
        ofs << cell.cellData.vals.fractional;
    } else if (cell.getType() == CellType::STRING) {
        ofs << '"' << cell.cellData.vals.text << '"';
    } else if (cell.getType() == CellType::FORMULA) {
        ofs << cell.cellData.vals.text;
    }
    return ofs;
}


/**
 * @brief Copy the data from Cell other with
 * allocating memory for std::string
 *
 * @param other The Cell that should be coppied
 */
void Cell::copy(const Cell &other) {
    cellData.type = other.cellData.type;
    if (cellData.type == CellType::FORMULA || cellData.type == CellType::STRING) {
        new(&cellData.vals.text)std::string(other.cellData.vals.text);
        return;
    }
    if (cellData.type == CellType::INTEGER) {
        cellData.vals.integer = other.cellData.vals.integer;
        return;
    }
    if (cellData.type == CellType::FRACTIONAL) {
        cellData.vals.fractional = other.cellData.vals.fractional;
    }
}

void Cell::destroy() {
    if (cellData.type == CellType::STRING || cellData.type == CellType::FORMULA) {
        cellData.vals.text.~basic_string<char>();
    }
}

