//
// Created by Sybatron on 8/15/2023.
//

#ifndef RETAKE_SOUNDS_SEQUENCE_H
#define RETAKE_SOUNDS_SEQUENCE_H

#pragma once

#include "Sound.h"

template<typename SampleType>
class Sequence : public Sound<SampleType> {
public:
    Sequence(const Sound<SampleType> **sounds);

private:
    void resizeSamples(size_t totalSampleCount);
};


#include "Sequence.inl"

#endif //RETAKE_SOUNDS_SEQUENCE_H
