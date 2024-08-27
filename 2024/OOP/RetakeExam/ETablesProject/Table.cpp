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

void Table::editCell(Coordinates coords, const Optional<Cell> &cell) {
//TODO check the task what i should do with out of range coords
    if (rows.size() < coords.row) {
        return;
    }
    if (rows[coords.row - 1].size() < coords.col) {
        return;
    }
    rows[coords.row - 1][coords.col - 1] = cell;
}

void Table::addRow(const Row &row) {
    rows.push_back(row);
}


void Table::copy(const Table &other) {
    for (size_t i = 0; i < other.rows.size(); ++i) {
        Row row = other.rows[i];
        rows.push_back(row);
    }
}

void Table::destroy() {
    rows.clear();
}
