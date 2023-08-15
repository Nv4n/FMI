//
// Created by Sybatron on 8/1/2023.
//

#ifndef RETAKE_SOUNDS_SILENCE_H
#define RETAKE_SOUNDS_SILENCE_H

#pragma once

#include "Sound.h"

template<typename SampleType>
class Silence : public Sound<SampleType> {
public:
    //TODO
    //  No specific Silence constructor
    Silence(size_t size);
};

#include "Silence.inl"

#endif //RETAKE_SOUNDS_SILENCE_H
