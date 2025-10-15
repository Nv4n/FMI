//
// Created by Sybatron on 8/26/2024.
//

#ifndef OOP_TABLE_H
#define OOP_TABLE_H

#pragma once

#include <vector>
#include <fstream>

#include "Cell.h"
#include "Types.h"
#include "CellValueInterpreter.h"

/**
 * @brief Table class that consists and manage
 * the table cell matrix.
 * It's only storage class, validation and processing of the data
 * is done by client or data/input Interpreters
 */
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

    void editCell(Coordinates coords, const Cell &cell);

    Cell getCell(Coordinates coords) const;

    friend std::ostream &operator<<(std::ostream &osWriter, const Table &table);

    friend std::ofstream &operator<<(std::ofstream &ofsWriter, const Table &table);

    std::string calculateFormula(const std::string &formula) const;

    size_t getRowCount() const;

    size_t getColCount() const;

    void reset();

private:
    void copy(const Table &other);

    void destroy();

    Coordinates getCellCoordinates(std::string rawCellCoordinates) const;

    std::vector<std::vector<std::string>> getTableAsStringMatrix() const;

    std::string unescapeString(const std::string &cellValue) const;
};


#endif //OOP_TABLE_H
