#include <iostream>
#include <cstdlib>
#include "DefaultDataSource.h"
#include "FileDataSource.h"
#include "ArrayDataSource.h"
#include "GeneratorDataSource.h"
#include "AlternateDataSource.h"
#include "StatelessGenerator.h"
#include "PrimeNumberGenerator.h"


int *fibonacciNumbersSample();

char *getDirectory();

void saveSequence(int *sequence, int size, const char *directory);

void copyFileToTxt(const char *fromDir, const char *toDir);

void task1();

void task2();

int main() {
    task1();

    task2();
    return 0;
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

    Generator<char *> *gen = new StatelessGenerator<char *>(getRandomText);
    GeneratorDataSource<char *> textGeneratorDataSource(gen);
    delete gen;
    for (int i = 0; i < 25; ++i) {
        char *text;
        text = textGeneratorDataSource.get();
        std::cout << "#" << i + 1 << ": " << text << std::endl;
        delete[] text;
    }
}

void task2() {
    Generator<int> *gen = new PrimeNumberGenerator<int>();
    GeneratorDataSource<int> primesGenDataSource(gen);
    delete gen;

    bool seed;
    std::srand((size_t) &seed);
    int (*getNumber)() =[]() -> int {
        return std::rand();
    };

    gen = new StatelessGenerator<int>(getNumber);
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
    std::cout << "Enter binary file directory" << std::endl;
    char *binaryDir = getDirectory();
    std::cout << "Enter txt file directory" << std::endl;
    char *txtDir = getDirectory();
    saveSequence(sequence, 1000, binaryDir);
    copyFileToTxt(binaryDir, txtDir);
    delete[] binaryDir;
    delete[]sequence;

    std::cout << std::endl << std::endl;
    FileDataSource<int> fileDataSource(txtDir);
    delete[] txtDir;

    for (size_t i = 0; i < 1000; ++i) {
        try {
            std::cout << fileDataSource.get() << " ";
        }
        catch (std::runtime_error &e) {
            std::cerr << std::endl << e.what() << std::endl;
            break;
        }
    }
    std::cout << std::endl;

};

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


char *getDirectory() {
    unsigned int buffer = 256;
    char *dir = new char[buffer];
    std::cin.clear();
    std::cin.getline(dir, buffer);
    return dir;
}

void saveSequence(int *sequence, int size, const char *directory) {
    std::ofstream writer(directory,
                         std::ios::binary);
    if (!writer.is_open()) {
        throw std::invalid_argument("Can't open binary file");
    }

    writer.write(reinterpret_cast< const char *>(&size), sizeof(size));
    writer.write(reinterpret_cast< const char *>(sequence), size * sizeof(int));
    writer.close();
}

void copyFileToTxt(const char *fromDir, const char *toDir) {
    std::ifstream reader(fromDir, std::ios::binary);
    if (!reader.is_open()) {
        throw std::invalid_argument("Can't open fromDir file");
    }
    int size = 0;
    reader.read(reinterpret_cast<char *>(&size), sizeof(size));

    int *sequence = new int[size + 1];
    reader.read(reinterpret_cast<char *>(sequence), size * sizeof(int));
    reader.close();

    std::ofstream writer(toDir);
    if (!writer.is_open()) {
        delete[] sequence;
        throw std::invalid_argument("Can't open toDir file");
    }

    for (size_t i = 0; i < size; ++i) {

        writer << sequence[i];
        if (i < size - 1) {
            writer << "\n";
        }
    }
    writer.close();
    delete[] sequence;
}