//
// Created by Sybatron on 8/4/2022.
//
#include <iostream>
#include <fstream>
#include <stdexcept>

#include "SetReader.h"

void initializeFiles();

int main() {
    try {
        initializeFiles(); //Comment if the files are created already
    }
    catch (std::runtime_error ex) {
        ex.what();
    }
    size_t intervalStart;
    std::cin >> intervalStart;

    size_t intervalEnd;
    std::cin >> intervalEnd;

    try {
        if (intervalStart > intervalEnd) {
            throw std::invalid_argument("Interval start is bigger from the end");

        }
    }
    catch (std::invalid_argument ex) {
        std::cout << ex.what() << std::endl;
        return 0;
    }

    try {
        SetReader<int> setReader();
        for (int i = intervalStart; i < intervalEnd; ++i) {
            std::cout << i;
        }
    }
    catch (std::runtime_error ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}

void initializeFiles() {
    //For x64 systems, x32 systems will have half the size of the types
    //Input.txt
    std::ofstream writer("Input.txt");
    if (!writer.is_open()) {
        throw std::runtime_error("Unable to open file Input.txt!");
    }

    writer << "first.dat" << std::endl << "second.dat" << std::endl << "set.dat";
    writer.close();

    //first.dat
    std::ofstream binaryWriter("first.txt", std::ios::binary);
    if (!binaryWriter.is_open()) {
        throw std::runtime_error("Unable to open file first.dat!");
    }

    binaryWriter.write(reinterpret_cast<const char *>(5), sizeof(short));
    binaryWriter.write(reinterpret_cast<const char *>(0), sizeof(short));

    binaryWriter.write(reinterpret_cast<const char *>(1), sizeof(int));
    binaryWriter.write(reinterpret_cast<const char *>(3), sizeof(int));
    binaryWriter.write(reinterpret_cast<const char *>(4), sizeof(int));
    binaryWriter.write(reinterpret_cast<const char *>(6), sizeof(int));
    binaryWriter.write(reinterpret_cast<const char *>(2), sizeof(int));
    binaryWriter.close();

    //second.dat
    binaryWriter.open("second.dat", std::ios::binary);
    if (!binaryWriter.is_open()) {
        throw std::runtime_error("Unable to open file second.dat!");
    }
    binaryWriter.write(reinterpret_cast<const char *>(5), sizeof(short));
    binaryWriter.write(reinterpret_cast<const char *>(0), sizeof(short));

    binaryWriter.write(reinterpret_cast<const char *>(1), sizeof(int));
    binaryWriter.write(reinterpret_cast<const char *>(10), sizeof(int));
    binaryWriter.write(reinterpret_cast<const char *>(12), sizeof(int));
    binaryWriter.write(reinterpret_cast<const char *>(16), sizeof(int));
    binaryWriter.write(reinterpret_cast<const char *>(2), sizeof(int));
    binaryWriter.close();

    //set.dat
    binaryWriter.open("set.dat", std::ios::binary);
    if (!binaryWriter.is_open()) {
        throw std::runtime_error("Unable to open file set.dat!");
    }
    binaryWriter.write(reinterpret_cast<const char *>(3), sizeof(short));
    binaryWriter.write(reinterpret_cast<const char *>(10), sizeof(short));

    binaryWriter.write(reinterpret_cast<const char *>(2), sizeof(int));
    binaryWriter.write(reinterpret_cast<const char *>(3), sizeof(int));
    binaryWriter.write(reinterpret_cast<const char *>(5), sizeof(int));
    binaryWriter.close();
}