//
// Created by Sybatron on 5/30/2022.
//
#include <iostream>
#include <fstream>
#include "Image.h"

int main() {
    uint8_t size;
    uint8_t start;
    uint8_t columns;
    uint8_t rows;

    char filename[200];
    std::cin >> filename;
    std::ifstream is(filename, std::ios::binary);
    if (is.is_open()) {

        is.read(reinterpret_cast< char *>(&size), sizeof(size));
        is.read(reinterpret_cast< char *>(&start), sizeof(start));
        is.read(reinterpret_cast< char *>(&columns), sizeof(columns));
        is.read(reinterpret_cast< char *>(&rows), sizeof(rows));
        is.close();
        Image img(rows, columns);
    }
    return 0;
}