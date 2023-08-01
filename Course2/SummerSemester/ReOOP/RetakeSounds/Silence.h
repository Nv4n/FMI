//
// Created by Sybatron on 8/1/2023.
//

#ifndef RETAKE_SOUNDS_SILENCE_H
#define RETAKE_SOUNDS_SILENCE_H


#include "Sound.h"

template<typename SampleType>
class Silence : public Sound<SampleType> {
public:
    Silence(size_t size);
};


#endif //RETAKE_SOUNDS_SILENCE_H
