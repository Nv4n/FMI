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
    Silence(size_t size);

    Sound<SampleType> *clone() const override;
};


#include "Silence.inl"

#endif //RETAKE_SOUNDS_SILENCE_H
