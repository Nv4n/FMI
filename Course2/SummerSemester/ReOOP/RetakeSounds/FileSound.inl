//
// Created by Sybatron on 8/1/2023.
//

#include "FileSound.h"
#include <fstream>
#include <stdexcept>

template<typename SampleType>
FileSound<SampleType>::FileSound(const char *&fileName) {
    std::ifstream reader(fileName, std::ios::binary);
    if (!reader.is_open()) {
        throw std::runtime_error("File failed to open");
    }
    this->sampleSize = 8;
    this->sampleCount = 0;
    this->samples = new SampleType[this->sampleSize];
    while (!reader.eof()) {
        SampleType sample;
        reader.read(reinterpret_cast<char *>(sample), sizeof(sample));
        if (this->sampleCount == this->sampleSize) {
            resizeSamples();
        }
        this->samples[this->sampleCount++] = sample;
    }

    reader.close();
    this->soundType = SoundType::FILE_SOUND;
}

template<typename SampleType>
void FileSound<SampleType>::resizeSamples() {
    this->sampleSize *= 2;
    SampleType *resizedSamples = new SampleType[this->sampleSize];
    for (size_t i = 0; i < this->sampleCount; ++i) {
        resizedSamples[i] = this->samples[i];
    }
    delete[] this->samples;
    this->samples = resizedSamples;
}