//
// Created by Sybatron on 8/15/2023.
//

#include "Sequence.h"

template<typename SampleType>
Sequence<SampleType>::Sequence(const Sound<SampleType> **sounds) {
    this->sampleSize = 8;
    this->sampleCount = 0;
    this->samples = new SampleType[this->sampleSize];

    Sound<SampleType> **soundsSequence = sounds;
    while (soundsSequence != nullptr) {
        Sound<SampleType> *currSound = *soundsSequence;
        size_t totalSampleCount = currSound->sampleCount + this->sampleCount;
        if (this->sampleSize < totalSampleCount) {
            resizeSamples(totalSampleCount);
        }
        for (size_t seqIndex = this->sampleCount, copyIndex = 0; seqIndex < totalSampleCount; ++seqIndex, ++copyIndex) {
            this->samples[seqIndex] += currSound->samples[copyIndex];
        }
        this->sampleCount = totalSampleCount;
        soundsSequence++;
    }
}

template<typename SampleType>
void Sequence<SampleType>::resizeSamples(size_t totalSampleCount) {
    while (this->sampleSize < totalSampleCount) {
        this->sampleSize = this->sampleCount * 2;
    }

    SampleType *resizedSamples = new SampleType[this->sampleSize];
    for (size_t i = 0; i < this->sampleCount; ++i) {
        resizedSamples[i] = this->samples[i];
    }
    delete[] this->samples;
    this->samples = resizedSamples;
}