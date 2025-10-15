//
// Created by Sybatron on 8/15/2023.
//

#include "Mix.h"

template<typename SampleType>
Mix<SampleType>::Mix(const Sound<SampleType> **sounds) {
    this->sampleSize = 8;
    this->sampleCount = 0;
    this->samples = new SampleType[this->sampleSize];
    for (int i = 0; i < this->sampleCount; ++i) {
        this->samples[i] = 0;
    }

    Sound<SampleType> **soundsSequence = sounds;
    while (soundsSequence != nullptr) {
        Sound<SampleType> *currSound = *soundsSequence;
        if (this->sampleSize < currSound->sampleSize) {
            resizeSamples(currSound->sampleSize);
        }
        if (this->sampleCount < currSound->sampleCount) {
            this->sampleCount = currSound->sampleCount;
        }
        for (size_t i = 0; i < currSound->sampleCount; ++i) {
            this->samples[i] += currSound->samples[i];
        }
        soundsSequence++;
    }
}

template<typename SampleType>
Sound<SampleType> *Mix<SampleType>::clone() const {
    return new Mix<SampleType>(*this);
}

template<typename SampleType>
void Mix<SampleType>::resizeSamples(size_t newSize) {
    this->sampleSize = newSize;
    SampleType *resizedSamples = new SampleType[this->sampleSize];
    for (size_t i = 0; i < this->sampleCount; ++i) {
        resizedSamples[i] = this->samples[i];
    }
    for (size_t i = this->sampleCount; i < this->sampleSize; ++i) {
        resizedSamples[i] = 0;
    }
    delete[] this->samples;
    this->samples = resizedSamples;
}