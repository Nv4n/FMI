//
// Created by Sybatron on 8/15/2023.
//

#ifndef RETAKE_SOUNDS_PLAYLIST_H
#define RETAKE_SOUNDS_PLAYLIST_H

#pragma once

#include "Sound.h"

enum class SongType {
    PAUSE,
    SONG
};

class Playlist {
private:
    struct PlaylistSongs {
        Sound<double> *sound;
        SongType songType;
        size_t index;
        PlaylistSongs *next;
    };

    struct PublicSongInfo {
        Sound<double> *&sound;
        SongType songType;
    };
    size_t songCount;
    PlaylistSongs *songs = nullptr;
public:
    Playlist(const char *filename);

    ~Playlist();

    void playPlaylist();

    PublicSongInfo &operator[](size_t index);

private:
    void destroy();

    void destroyRecursive(PlaylistSongs *&currSong);

    void initSong(const char *filename, double volumeCoefficient);

    void initPause(size_t pauseLength);

    void initFadeInSong(const char *filename, size_t fadeInLength, double finalVolumeCoeff);

    void initOverflow(size_t fadeOutLength, size_t fadeInLength, double fadeVolume);
};


#endif //RETAKE_SOUNDS_PLAYLIST_H
