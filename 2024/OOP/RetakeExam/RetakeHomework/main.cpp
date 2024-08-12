#include <iostream>
#include <cstdlib>
#include "DataSources/DefaultDataSource.h"
#include "DataSources/FileDataSource.h"
#include "DataSources/ArrayDataSource.h"
#include "DataSources/GeneratorDataSource.h"
#include "DataSources/AlternateDataSource.h"
#include "Generators/StatelessGenerator.h"
#include "Generators/PrimeNumberGenerator.h"

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

    PrimeNumberGenerator<int> primeGen;
    Generator<int> *gen = primeGen.clone();
    GeneratorDataSource<int> primeDataSourceGen(gen);
    delete gen;

    bool seed;
    std::srand((size_t) &seed);
    int (*getNumber)() =[]() -> int {
        return std::rand();
    };

    StatelessGenerator<int> integerGen(getNumber);
    gen = integerGen.clone();
    GeneratorDataSource<int> genDataSource(gen);
    delete gen;
//    std::cout << genDataSource.get() << std::endl;
    return 0;
}