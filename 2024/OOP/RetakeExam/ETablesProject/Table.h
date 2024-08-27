//
// Created by Sybatron on 8/26/2024.
//

#ifndef OOP_TABLE_H
#define OOP_TABLE_H

#pragma once

#include <vector>
#include "Optional.h"
#include "Cell.h"

typedef std::vector<Optional<Cell>> Row;
typedef std::vector<Row> TableRows;

class Table {
private:
    TableRows rows;
public:
    Table() = default;

    Table(const Table &other);

    Table &operator=(const Table &other);

    virtual ~Table() = default;

    void addRow(Row row);

    void editCell(size_t row, size_t column, Optional<Cell> cell);

    friend std::ostream &operator<<(std::ostream &os, const Table &tb);

private:
    void copy(const Table &other);

    void destroy();
};


#endif //OOP_TABLE_H
