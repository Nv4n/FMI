#include <iostream>
#include <cstdlib>
#include "DataSources/DefaultDataSource.h"
#include "DataSources/FileDataSource.h"
#include "DataSources/ArrayDataSource.h"
#include "DataSources/GeneratorDataSource.h"
#include "DataSources/AlternateDataSource.h"
#include "Generators/StatelessGenerator.h"
#include "Generators/PrimeNumberGenerator.h"


int *fibonacciNumbersSample() {
    size_t sampleSize = 25; //must be at least 2
    int *sample = new int[sampleSize];
    sample[0] = 1;
    sample[1] = 1;
    for (size_t i = 2; i < sampleSize; ++i) {
        sample[i] = sample[i - 1] + sample[i - 2];
    }
    return sample;
}

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

void task2() {
    PrimeNumberGenerator<int> primeGen;
    Generator<int> *gen = primeGen.clone();
    GeneratorDataSource<int> primesGenDataSource(gen);
    delete gen;

    bool seed;
    std::srand((size_t) &seed);
    int (*getNumber)() =[]() -> int {
        return std::rand();
    };

    StatelessGenerator<int> integerGen(getNumber);
    gen = integerGen.clone();
    GeneratorDataSource<int> integerGenDataSource(gen);
    delete gen;

    int *sampleFibonacci = fibonacciNumbersSample();
    ArrayDataSource<int> fibonacciDataSource(sampleFibonacci, 25);
    delete[] sampleFibonacci;

    DataSource<int> **sources = new DataSource<int> *[3];
    sources[0] = primesGenDataSource.clone();
    sources[1] = integerGenDataSource.clone();
    sources[2] = fibonacciDataSource.clone();

    AlternateDataSource<int> alternateDataSource(sources, 3);
    for (int i = 0; i < 3; ++i) {
        delete sources[i];
    }
    delete[] sources;

    int *sequence = alternateDataSource.get(1000);
    for (int i = 0; i < 1000; ++i) {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;
    delete[]sequence;
};

int main() {
//    task1();

    task2();
    return 0;
}