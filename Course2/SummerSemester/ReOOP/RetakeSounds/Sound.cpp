//
// Created by Sybatron on 8/1/2023.
//
#include <stdexcept>
#include "Sound.h"

template<typename SampleType>
SampleType Sound<SampleType>::operator[](size_t index) {
    if (index >= sampleSize) {
        throw std::out_of_range("Index is out of range");
    }
    return samples[sampleSize];
}

template<typename SampleType>
Sound<SampleType> &Sound<SampleType>::operator=(const Sound<SampleType> &other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

template<typename SampleType>
Sound<SampleType>::Sound(const Sound<SampleType> &other) {
    copy(other);
}

template<typename SampleType>
void Sound<SampleType>::copy(const Sound<SampleType> &other) {
    sampleSize = other.sampleSize;
    samples = new SampleType[sampleSize];
    for (size_t i = 0; i < other.sampleSize; ++i) {
        samples[i] = other.samples[i];
    }
}

template<typename SampleType>
void Sound<SampleType>::destroy() {
    delete[] samples;
}