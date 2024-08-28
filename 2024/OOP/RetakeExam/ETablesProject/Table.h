//
// Created by Sybatron on 8/26/2024.
//

#ifndef OOP_TABLE_H
#define OOP_TABLE_H

#pragma once

#include <vector>
#include <fstream>

#include "Optional.h"
#include "Cell.h"

using Row = std::vector<Optional<Cell>>;
using TableRows = std::vector<Row>;

struct Coordinates {
    size_t row;
    size_t col;
};

class Table {
private:
    size_t colCount{};
    TableRows rows;
public:
    Table() = default;

    Table(const Table &other);

    Table &operator=(const Table &other);

    virtual ~Table() = default;

    void addRow(const Row &row);

    void editCell(Coordinates coords, const Optional<Cell> &cell);

    friend std::ostream &operator<<(std::ostream &os, const Table &table);

    friend std::ofstream &operator<<(std::ofstream &os, const Table &table);

    size_t getRowCount() const;

    size_t getColCount() const;

private:
    void copy(const Table &other);

    void destroy();
};


#endif //OOP_TABLE_H
