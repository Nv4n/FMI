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
    set2.add(5);
    set2.add(15);

    MultiSet set4 = set2.intersect(set3);
    set4.printAllNumbers();
    set2.printAllNumbers();
    set3.printAllNumbers();
    set4 = set3.except(set2);
    set4.printAllNumbers();
    MultiSet set5 = set4.addition();
    set5.printAllNumbers();
    std::cout << (int) set3.frequencyOf(5) << " " << (int) set1.frequencyOf(5) << std::endl;

    std::ofstream writer("test.dat", std::ios::binary);
    if (!writer.is_open()) {
        std::cout << "error" << std::endl;
        return 1;
    }
    writer << set3;
    writer.close();
    std::ifstream reader("test.dat", std::ios::binary);
    if (!reader.is_open()) {
        std::cout << "cant read" << std::endl;
        return 1;
    }
    set3.printAllNumbers();
    MultiSet set6(1000, 5);
    reader >> set6;
    set6.printAllNumbers();
    reader.close();
    return 0;
};