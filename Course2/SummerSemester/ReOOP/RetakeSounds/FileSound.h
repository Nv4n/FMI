//
// Created by Sybatron on 8/1/2023.
//

#ifndef RETAKE_SOUNDS_FILESOUND_H
#define RETAKE_SOUNDS_FILESOUND_H


#include "Sound.h"

template<typename SampleType>
class FileSound : public Sound<SampleType> {
public:
    FileSound(const char *fileName);
};


#endif //RETAKE_SOUNDS_FILESOUND_H
