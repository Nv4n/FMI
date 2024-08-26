//
// Created by Sybatron on 8/26/2024.
//

#ifndef ETABLES_CELL_H
#define ETABLES_CELL_H

#include <string>
#include "Utility.h"
#include <stdexcept>

typedef union Data {
    int integer;
    double fractional;
    std::string text;

    Data() {};

    ~Data() {};
} CellValues;

enum class CellType {
    INTEGER,
    FRACTIONAL,
    STRING,
    FORMULA,
    NONE
};


class Cell {
private:
    struct CellData {
        CellType type;
        CellValues vals;
    } cell;
public:
    Cell();

    Cell(const Cell &other);

    Cell &operator=(const Cell &other);

    ~Cell();

    template<typename T>
    T get();

    template<typename T>
    void set(T val);

    void empty();

private:
    void copy(const Cell &other);

    void destroy();
};

template<typename T>
T Cell::get() {
    if (!is_same<T, int>()) {
        throw std::logic_error("can't do this");
    }
    T dada{};
    return dada;
}

template<typename T>
void Cell::set(T val) {

}

#endif //ETABLES_CELL_H
