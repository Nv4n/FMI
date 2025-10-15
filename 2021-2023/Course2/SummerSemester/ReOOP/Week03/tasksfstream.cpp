//
// Created by Sybatron on 3/16/2023.
//
#include <iostream>
#include <fstream>

int main() {
    int size;
    std::cin >> size;
    char *arr = new char[size + 1];
    std::cin.ignore();
    std::cin.getline(arr, size + 1);
    std::cout << arr << std::endl;
    std::cout << sizeof(arr) << std::endl;
    std::ofstream writer("output.txt");
    if (!writer.is_open()) {
        return 1;
    }
    writer << size << arr;
    writer.close();
    delete[] arr;

    std::ifstream reader("output.txt");
    if (!reader.is_open()) {
        return 1;
    }
    reader >> size;
    std::cout << size << std::endl;
    arr = new char[size + 1];
    std::cout << sizeof(arr) << std::endl;
    reader.read(arr, sizeof(arr));
    reader.close();
    std::cout << arr << std::endl;

    writer.open("evenOutput.txt");
    if (!writer.is_open()) {
        return 1;
    }
    for (int i = 0; i < size; i += 2) {
        writer << arr[i];
    }
    writer.close();
}
