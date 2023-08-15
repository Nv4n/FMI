//
// Created by Sybatron on 8/15/2023.
//

#ifndef RETAKE_SOUNDS_MIX_H
#define RETAKE_SOUNDS_MIX_H
#pragma once

#include "Sound.h"

template<typename SampleType>
class Mix : public Sound<SampleType> {
public:
    Mix(const Sound<SampleType> **sounds);

    Sound<SampleType> *clone() const override;

private:
    void resizeSamples(size_t newSize);
};


#include "Mix.inl"

#endif //RETAKE_SOUNDS_MIX_H
