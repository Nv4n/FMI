//
// Created by Sybatron on 8/1/2023.
//
#include <iostream>
#include "Silence.h"

template<typename SampleType>
Silence<SampleType>::Silence(size_t size) {
    this->sampleSize = size;
    this->samples = new SampleType[size];
    for (int i = 0; i < this->sampleSize; ++i) {
        this->samples[i] = 0;
    }
}