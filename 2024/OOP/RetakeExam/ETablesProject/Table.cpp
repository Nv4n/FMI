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

/**
 * @brief operator<< For printing on the console
 * @param osWriter Expected std::cout
 * @param table Table to be written on the terminal
 * @return osWriter
 */
std::ostream &operator<<(std::ostream &osWriter, const Table &table) {
    //TODO Print std::cout
    return osWriter;
}

/**
 * @brief operator<< For writing in text file
 * @param ofsWriter Expected std::ofstream to text file
 * @param table Table to be written in file
 * @return ofsWriter
 */
std::ofstream &operator<<(std::ofstream &ofsWriter, const Table &table) {
    for (size_t row = 0; row < table.getRowCount(); ++row) {
        for (int col = 0; col < table.getColCount(); ++col) {
            try {
                ofsWriter << table.rows[row][col] << ",";
            } catch (std::exception &e) {
                ofsWriter << ",";
            }
        }
        ofsWriter << "\n";
    }
    return ofsWriter;
}

/**
 *
 * @param coords Structure consisting of Row and Col
 * @param cell The new cell value
 * @throws invalid_argumen When either row or col coordinate is out of range
 */
void Table::editCell(Coordinates coords, const Cell &cell) {
    if (rows.size() < coords.row) {
        throw std::invalid_argument("Row is out of range");
    }

    if (colCount < coords.col) {
        throw std::invalid_argument("Col is out of range");
    }
    if (rows[coords.row - 1].size() < colCount) {
        for (size_t i = rows[coords.row - 1].size(); i <= colCount; ++i) {
            rows[coords.row - 1].emplace_back();
        }
    }
    rows[coords.row - 1][coords.col - 1] = cell;
}

/**
 * @brief Method to add new row in the end of the table
 * @param row Vector of Table Cells
 */
void Table::addRow(const Row &row) {
    if (row.size() > colCount) {
        colCount = row.size();
    }
    rows.push_back(row);
}

/**
 * @brief Resets table to default state
 */
void Table::reset() {
    destroy();
    colCount = 0;
}

/**
 *
 * @return Rows count of the table
 */
size_t Table::getRowCount() const {
    return rows.size();
}

/**
 *
 * @return Columns count of the table
 */
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


