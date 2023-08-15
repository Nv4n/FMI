//
// Created by Sybatron on 8/1/2023.
//

#ifndef RETAKE_SOUNDS_FILESOUND_H
#define RETAKE_SOUNDS_FILESOUND_H

#pragma once

#include "Sound.h"

template<typename SampleType>
class FileSound : public Sound<SampleType> {
public:
    FileSound(const char *&fileName);

private:
    void resizeSamples();

};

#include "FileSound.inl"

#endif //RETAKE_SOUNDS_FILESOUND_H
