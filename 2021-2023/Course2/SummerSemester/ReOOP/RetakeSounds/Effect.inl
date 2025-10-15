//
// Created by Sybatron on 8/15/2023.
//

#include "Effect.h"

template<typename SampleType, typename EffectFunctor>
Effect<SampleType, EffectFunctor>::Effect(const Sound<SampleType> *sound,
                                          TransformFunc<SampleType,
                                                  EffectFunctor *> transformFunc, unsigned int boundary) {
    this->sampleSize = sound->getSampleSize();
    this->sampleCount = sound->getLength();
    this->samples = new SampleType[this->sampleSize];
    for (size_t i = 0; i < this->sampleCount; ++i) {
        this->samples[i] = transformFunc(sound->operator[](i), i);
    }
    for (int i = 0; i < this->sampleCount; ++i) {
        if (this->samples[i] > boundary) {
            this->samples[i] = boundary;
        } else if (this->samples[i] < (boundary * (-1))) {
            this->samples[i] = boundary * (-1);
        }
    }
}

template<typename SampleType, typename EffectFunctor>
Sound<SampleType> *Effect<SampleType, EffectFunctor>::clone() const {
    return new Effect<double>(*this);
}