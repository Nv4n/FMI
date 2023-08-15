//
// Created by Sybatron on 8/1/2023.
//

#ifndef RETAKE_SOUNDS_SOUND_H
#define RETAKE_SOUNDS_SOUND_H
#pragma once

#include "iostream"

enum class SoundType {
    SILENCE,
    FILE_SOUND,
    PERIODIC_SOUND,
    MIX,
    SEQUENCE,
    EFFECT,
};

template<typename SampleType>
class Sound {
protected:
    size_t sampleSize{};
    size_t sampleCount{};
    SampleType *samples;
    SoundType soundType;

public:
    SampleType operator[](size_t index);

    virtual ~Sound();

//TODO FIX POLYMORPHIC COPY
    Sound(const Sound<SampleType> &other);

    Sound<SampleType> &operator=(const Sound<SampleType> &other);

    //TODO POLYMORPHIC CLONE
    virtual Sound<SampleType> *clone() const = 0;

private:
    void copy(const Sound<SampleType> &other);

    void destroy();
};

#include "Sound.inl"

#endif //RETAKE_SOUNDS_SOUND_H
