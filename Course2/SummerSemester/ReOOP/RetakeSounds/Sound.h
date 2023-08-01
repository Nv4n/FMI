//
// Created by Sybatron on 8/1/2023.
//

#ifndef RETAKE_SOUNDS_SOUND_H
#define RETAKE_SOUNDS_SOUND_H
#pragma once

template<typename SampleType>
class Sound {
protected:
    size_t sampleSize{};
    SampleType *samples;
public:
    SampleType operator[](size_t index);

    virtual ~Sound() {
        destroy();
    }

    Sound(const Sound<SampleType> &other);

    Sound<SampleType> &operator=(const Sound<SampleType> &other);

private:
    void copy(const Sound<SampleType> &other);

    void destroy();
};


#endif //RETAKE_SOUNDS_SOUND_H
