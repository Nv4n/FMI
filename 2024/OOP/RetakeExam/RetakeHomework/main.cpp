#include <iostream>
#include <cstdlib>
#include "DataSources/DefaultDataSource.h"
#include "DataSources/FileDataSource.h"
#include "DataSources/ArrayDataSource.h"
#include "DataSources/GeneratorDataSource.h"
#include "DataSources/AlternateDataSource.h"
#include "Generators/StatelessGenerator.h"

void task1() {
    bool seed;
    std::srand((size_t) &seed);

    char *(*getRandomText)() = []() -> char * {

        char *elements = new char[11];
        for (int i = 0; i < 10; ++i) {
            elements[i] = static_cast<char>(static_cast<int>('a') + std::rand() % 26);
        }
        elements[10] = '\0';
        return elements;
    };
    StatelessGenerator<char *> charSequenceGen(getRandomText);
    for (int i = 0; i < 25; ++i) {
        char *text = charSequenceGen.get();
        std::cout << "#" << i + 1 << ": " << text << std::endl;
        delete[] text;
    }
}

int main() {
//    task1();
    bool seed;
    std::srand((size_t) &seed);
    int (*getNumber)() =[]() -> int {
        std::rand();
    };
    StatelessGenerator<int> generator(getNumber);
    Generator<int> *gen = &generator;
    GeneratorDataSource<int> genDataSource(gen);
    std::cout << genDataSource.get() << std::endl;
    return 0;
}