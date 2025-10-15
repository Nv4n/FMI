//
// Created by Sybatron on 8/31/2024.
//

#ifndef ETABLES_TYPES_H
#define ETABLES_TYPES_H
#pragma

#include <vector>
#include "Cell.h"

using Row = std::vector<Cell>;
using TableRows = std::vector<Row>;

/**
 * @brief Structure consisting of row and column coordinates
 */
struct Coordinates {
    size_t row;
    size_t col;
};

/**
 * @brief Structure representing the processed cell data as string value
 */
struct CellAsString {
    CellType type;
    std::string value;
};

#endif //ETABLES_TYPES_H
