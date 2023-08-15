//
// Created by Sybatron on 8/15/2023.
//

#ifndef RETAKE_SOUNDS_PLAYLIST_H
#define RETAKE_SOUNDS_PLAYLIST_H

#pragma once

class Playlist {
public:
    Playlist(const char *filename);

private:
    void initSong(const char *filename, double volumeCoefficient);

    void initPause(size_t pauseLength);

    void initFadeInSong(const char *filename, size_t fadeInLength, double finalVolumeCoeff);

    void initOverflow(size_t fadeOutLength, size_t fadeInLength, double fadeVolume);
};


#endif //RETAKE_SOUNDS_PLAYLIST_H
