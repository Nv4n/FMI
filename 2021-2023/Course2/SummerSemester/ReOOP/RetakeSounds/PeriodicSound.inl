//
// Created by Sybatron on 8/13/2023.
//

#include "PeriodicSound.h"

template<typename SampleType>
PeriodicSound<SampleType>::PeriodicSound(const SampleType *&sequence, size_t repeatCount) {
    SampleType *tempSequence = sequence;
    size_t sequenceSize = 0;
    while (tempSequence != nullptr) {
        sequenceSize++;
        tempSequence++;
    }
    size_t size = sequenceSize * repeatCount;
    this->samples = new SampleType[size];
    for (size_t i = 0; i < size;) {
        tempSequence = sequence;
        while (tempSequence != nullptr && i < size) {
            this->samples[i++] = *tempSequence;
            tempSequence++;
        }
    }
    this->sampleCount = size;
    this->sampleSize = size;
}