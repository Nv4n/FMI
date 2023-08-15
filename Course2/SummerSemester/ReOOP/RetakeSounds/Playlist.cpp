//
// Created by Sybatron on 8/15/2023.
//

#include <iostream>
#include "Playlist.h"
#include "Sound.h"
#include "FileSound.h"
#include "Silence.h"
#include "Effect.h"

template<typename Tret, typename T>
Tret lambda_ptr_exec(T *v) {
    return (Tret) (*v)();
}

template<typename Tret = void, typename Tfp = Tret(*)(void *), typename T>
Tfp lambda_ptr(T &v) {
    return (Tfp) lambda_ptr_exec<Tret, T>;
}

void Playlist::initSong(const char *filename, double volumeCoefficient) {
    Sound<double> *fileInput = new FileSound<double>(filename);
//    auto effectFunc = [&volumeCoefficient]
    Sound<double> *song = new Effect<double>(fileInput, [](double sample, size_t index) -> double {
        return sample * 2;
    });
}

void Playlist::initPause(size_t pauseLength) {
    Sound<double> *pause = new Silence<double>(pauseLength);
}
