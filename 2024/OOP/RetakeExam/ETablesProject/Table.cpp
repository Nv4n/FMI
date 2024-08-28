//
// Created by Sybatron on 8/26/2024.
//

#include "Table.h"

Table::Table(const Table &other) {
    copy(other);
}

Table &Table::operator=(const Table &other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Table &table) {
    //TODO print in right way
    return os;
}

std::ofstream &operator<<(std::ofstream &ofs, const Table &table) {
    return ofs;
}

/**
 *
 * @param coords Structure consisting of Row and Col
 * @param cell The new cell value
 * @throws invalid_argumen When either row or col coordinate is out of range
 */
void Table::editCell(Coordinates coords, const Optional<Cell> &cell) {
//TODO check the task what i should do with out of range coords
    if (rows.size() < coords.row) {
        throw std::invalid_argument("Row is out of range");
    }

    if (colCount < coords.col) {
        throw std::invalid_argument("Col is out of range");
    }
    rows[coords.row - 1][coords.col - 1] = cell;
}

void Table::addRow(const Row &row) {
    if (row.size() > colCount) {
        colCount = row.size();
    }
    rows.push_back(row);
}

size_t Table::getRowCount() const {
    return rows.size();
}

size_t Table::getColCount() const {
    return colCount;
}


void Table::copy(const Table &other) {
    colCount = other.colCount;
    for (size_t i = 0; i < other.rows.size(); ++i) {
        Row row = other.rows[i];
        rows.push_back(row);
    }
}

void Table::destroy() {
    rows.clear();
}



