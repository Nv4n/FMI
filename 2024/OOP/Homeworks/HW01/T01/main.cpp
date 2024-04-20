//
// Created by Sybatron on 4/20/2024.
//
#include <iostream>
#include "1.h"

int main() {
    MultiSet set1(5000, 3);
    MultiSet set2(2000, 2);
    MultiSet set3 = set1;
    set3.add(5);
    set3.add(0);
    set3.add(1000);
    set3.add(5);
    set3.add(5);
    set3.add(13);
    set3.add(5);
    set3.add(10);
    set3.add(10);

    set2.add(14);
    set2.add(1000);
    set2.add(5);
    set2.add(5);
    set2.add(3);
    set2.add(0);
    set2.add(15);

    set2.printAllNumbers();
//    set3.printMemoryRepresentation();
    return 0;
};