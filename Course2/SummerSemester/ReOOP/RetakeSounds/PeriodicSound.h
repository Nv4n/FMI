//
// Created by Sybatron on 8/13/2023.
//

#ifndef P_SOUNDS_PERIODICSOUND_H
#define P_SOUNDS_PERIODICSOUND_H

#pragma once

#include "Sound.h"

template<typename SampleType>
class PeriodicSound : public Sound<SampleType> {
public:
    PeriodicSound(const SampleType *&sequence, size_t repeatCount);
};


#include "PeriodicSound.inl"

#endif //P_SOUNDS_PERIODICSOUND_H
