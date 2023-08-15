//
// Created by Sybatron on 8/15/2023.
//

#ifndef RETAKE_SOUNDS_EFFECT_H
#define RETAKE_SOUNDS_EFFECT_H

#pragma once

#include "Sound.h"

template<typename SampleType>
class Effect : public Sound<SampleType> {
public:
    using EffectLambdaType = SampleType(*)(SampleType sample, size_t index);

    Effect(const Sound<SampleType> *sound, EffectLambdaType transformFunc);

    Sound<SampleType> *clone() const override;
};


#include "Effect.inl"

#endif //RETAKE_SOUNDS_EFFECT_H
