//
// Created by Sybatron on 3/3/2024.
//
#include <iostream>
#include <fstream>

struct Student {
    static int studentIndex;
};
int Student::studentIndex = 1;

int main() {
    std::ofstream output("student.txt");

}