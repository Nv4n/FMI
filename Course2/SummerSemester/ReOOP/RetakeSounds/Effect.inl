//
// Created by Sybatron on 8/15/2023.
//

#include "Effect.h"

template<typename SampleType>
Effect<SampleType>::Effect(const Sound<SampleType> *sound, EffectLambdaType transformFunc) {
    this->sampleSize = sound->getSampleSize();
    this->sampleCount = sound->getLength();
    this->samples = new SampleType[this->sampleSize];
    for (size_t i = 0; i < this->sampleCount; ++i) {
        this->samples[i] = transformFunc(sound->operator[](i), i);
    }
}

template<typename SampleType>
Sound<SampleType> *Effect<SampleType>::clone() const {
    return new Effect<double>(*this);
}