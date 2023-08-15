//
// Created by Sybatron on 8/15/2023.
//

#ifndef RETAKE_SOUNDS_SEQUENCE_H
#define RETAKE_SOUNDS_SEQUENCE_H

#include "Sound.h"

template<typename SampleType>
class Sequence : public Sound<SampleType> {
public:
    Sequence(const Sound<SampleType> **sounds);

private:
    void resizeSamples(size_t totalSampleCount);
};

template<typename SampleType>
void Sequence<SampleType>::resizeSamples(size_t totalSampleCount) {
    while (this->sampleSize < totalSampleCount) {
        this->sampleSize *= 2;
    }

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

template<typename SampleType>
Sequence<SampleType>::Sequence(const Sound<SampleType> **sounds) {
    this->sampleSize = 8;
    this->sampleCount = 0;
    this->samples = new SampleType[this->sampleSize];

    Sound<SampleType> **soundsSequence = sounds;
    while (soundsSequence != nullptr) {
        Sound<SampleType> *currSound = *soundsSequence;
        if (this->sampleSize < currSound->sampleSize) {
            resizeSamples(currSound->sampleSize);
        }
        if (this->sampleCount < currSound->sampleCount) {
            this->sampleCount = currSound->sampleCount;
        }
        for (int i = 0; i < currSound->sampleCount; ++i) {
            this->samples[i] += currSound->samples[i];
        }
        soundsSequence++;
    }
}


#include "Sequence.inl"

#endif //RETAKE_SOUNDS_SEQUENCE_H
