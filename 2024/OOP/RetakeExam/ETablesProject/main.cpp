//
// Created by Sybatron on 8/26/2024.
//
#include <iostream>
#include "Optional.h"
#include "Cell.h"

int main() {
    std::cout << "HI" << std::endl;
    Cell test;
    auto x = test.get<int>();
    std::cout << x;
}
