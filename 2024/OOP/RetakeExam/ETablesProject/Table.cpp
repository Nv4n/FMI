//
// Created by Sybatron on 8/26/2024.
//

#include <cmath>
#include <iostream>
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
    std::vector<std::vector<std::string>> tableAsStrings = table.getTableAsStringMatrix();
    std::vector<size_t> colMaxWidths(table.getColCount(), 0);

    for (size_t rowInd = 0; rowInd < tableAsStrings.size(); ++rowInd) {
        for (size_t colInd = 0; colInd < colMaxWidths.size(); ++colInd) {
            if (colMaxWidths[colInd] < tableAsStrings[rowInd][colInd].size()) {
                colMaxWidths[colInd] = tableAsStrings[rowInd][colInd].size();
            }
        }
    }

    for (size_t rowInd = 0; rowInd < tableAsStrings.size(); ++rowInd) {
        for (size_t colInd = 0; colInd < tableAsStrings[rowInd].size(); ++colInd) {
            osWriter << " " << tableAsStrings[rowInd][colInd];
            if (tableAsStrings[rowInd][colInd].size() < colMaxWidths[colInd]) {
                size_t width = colMaxWidths[colInd] - tableAsStrings[rowInd][colInd].size();
                osWriter << std::string(width, ' ');
            }
            if (colInd + 1 < tableAsStrings[rowInd].size()) {
                osWriter << " |";
            }
        }
        if (tableAsStrings[rowInd].size() < colMaxWidths.size()) {
            osWriter << " |";
            for (size_t colInd = tableAsStrings[rowInd].size(); colInd < colMaxWidths.size(); ++colInd) {
                osWriter << " ";
                size_t width = colMaxWidths[colInd];
                osWriter << std::string(width, ' ');
                if (colInd + 1 < colMaxWidths.size()) {
                    osWriter << " |";
                }
            }
        }
        osWriter << "\n";
    }


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

/**
 *
 * @param rawCellCoordinates Cell coordinates as Cell Argument
 * @return Coordinates the deciphered cell coordinates
 */
Coordinates Table::getCellCoordinates(std::string rawCellCoordinates) {
    Coordinates coords{};
    std::string token;
    for (size_t ind = 1; ind < rawCellCoordinates.size(); ++ind) {
        if (rawCellCoordinates[ind] == 'C') {
            coords.row = std::stoi(token);
            token = "";
            continue;
        }
        token += rawCellCoordinates[ind];
    }
    coords.col = std::stoi(token);
    return coords;
}

/**
 *
 * @param coords Coordinates row and column
 * @return Cell by given coordinates
 */
Cell Table::getCell(Coordinates coords) const {
    if (rows.size() < coords.row) {
        throw std::invalid_argument("Row is out of range");
    }

    if (colCount < coords.col) {
        throw std::invalid_argument("Col is out of range");
    }
    return rows[coords.row - 1][coords.col - 1];
}

std::vector<std::vector<std::string>> Table::getTableAsStringMatrix() const {
    std::vector<std::vector<std::string>> tblAsStrings(getRowCount());

    for (size_t rowInd = 0; rowInd < getRowCount(); ++rowInd) {
        std::vector<std::string> cellStringRow;
        size_t colInd = 0;

        for (; colInd < rows[rowInd].size(); ++colInd) {
            Cell cell = getCell({rowInd + 1, colInd + 1});
            if (cell.getType() == CellType::INTEGER) {
                cellStringRow.push_back(std::to_string(cell.get<int>()));
            } else if (cell.getType() == CellType::FRACTIONAL) {
                cellStringRow.push_back(std::to_string(cell.get<double>()));
            } else if (rows[rowInd][colInd].getType() == CellType::STRING) {
                cellStringRow.push_back(cell.get<std::string>());
            } else if (rows[rowInd][colInd].getType() == CellType::FORMULA) {
                cellStringRow.push_back(calculateFormula(cell.get<std::string>()));
            } else {
                cellStringRow.emplace_back("");
            }
        }

        tblAsStrings[rowInd] = cellStringRow;
    }
    return tblAsStrings;
}

std::string Table::calculateFormula(const std::string &formula) const {
    //TODO CREATE THE WHOLE METHOD
    return std::string();
}


