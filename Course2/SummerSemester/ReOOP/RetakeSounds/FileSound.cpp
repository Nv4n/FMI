//
// Created by Sybatron on 8/1/2023.
//

#include "FileSound.h"
#include <fstream>
#include <stdexcept>

template<typename SampleType>
FileSound<SampleType>::FileSound(const char *fileName) {
    std::ifstream reader(fileName, std::ios::binary);
    if (!reader.is_open()) {
        throw std::runtime_error("File failed to open");
    }

    SampleType sample =
            reader.close();
}