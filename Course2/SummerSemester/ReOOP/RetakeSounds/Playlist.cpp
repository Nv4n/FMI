//
// Created by Sybatron on 8/15/2023.
//

#include <iostream>
#include <fstream>
#include "Playlist.h"
#include "FileSound.h"
#include "Silence.h"
#include "Effect.h"

class SongFunctor : public Functor<double> {
private:
    double captureVolumeCoeff;

public:
    virtual ~SongFunctor() = default;

    SongFunctor(double volumeCoefficient) : captureVolumeCoeff(volumeCoefficient) {}

    double operator()(double sample, size_t index) const override {
        return sample * captureVolumeCoeff;
    }
};

class FadeInFunctor : public Functor<double> {
private:
    size_t captureLength;
    double captureFinalVolCoeff;

public:
    virtual ~FadeInFunctor() = default;

    FadeInFunctor(size_t fadeInLength, double finalVolumeCoeff)
            : captureLength(fadeInLength),
              captureFinalVolCoeff(finalVolumeCoeff) {}

    double operator()(double sample, size_t index) const override {
        double step = captureFinalVolCoeff / captureLength;
        if (index < captureLength) {
            return index * step;
        }
        return sample;
    }
};

void Playlist::initSong(const char *filename, double volumeCoefficient) {
    Sound<double> *fileInput = new FileSound<double>(filename);
    SongFunctor songFunctor(volumeCoefficient);
    TransformFunc<double, Functor<double> *> songEffect(&songFunctor);

    Sound<double> *songSound = new Effect<double>(fileInput, songEffect);
    if (!songs) {
        songs = new PlaylistSongs{songSound, SongType::SONG, 0, nullptr};
    } else {
        PlaylistSongs *curr = songs;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new PlaylistSongs{songSound, SongType::SONG, curr->index + 1, nullptr};
    }
}

void Playlist::initPause(size_t pauseLength) {
    Sound<double> *pause = new Silence<double>(pauseLength);

    if (!songs) {
        songs = new PlaylistSongs{pause, SongType::PAUSE, 0, nullptr};
    } else {
        PlaylistSongs *curr = songs;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new PlaylistSongs{pause, SongType::PAUSE, curr->index + 1, nullptr};
    }
}

void Playlist::initFadeInSong(const char *filename, size_t fadeInLength, double finalVolumeCoeff) {
    Sound<double> *fileInput = new FileSound<double>(filename);
    FadeInFunctor fadeInFunctor(fadeInLength, finalVolumeCoeff);
    TransformFunc<double, Functor<double> *> fadeInEffect(&fadeInFunctor);

    Sound<double> *fadeInSound = new Effect<double>(fileInput, fadeInEffect);
    if (!songs) {
        songs = new PlaylistSongs{fadeInSound, SongType::SONG, 0, nullptr};
    } else {
        PlaylistSongs *curr = songs;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new PlaylistSongs{fadeInSound, SongType::SONG, curr->index + 1, nullptr};
    }
}

void Playlist::initOverflow(size_t fadeOutLength, size_t fadeInLength, double fadeVolume) {

}

Playlist::Playlist(const char *filename) {
    try {
        std::ifstream reader(filename);
        if (!reader.is_open()) {
            reader.close();
            throw std::runtime_error("Playlist couldn't be opened");
        }
        while (!reader.eof()) {
            const size_t MAX_CHARACTER_PER_LINE = 1001;
            char line[MAX_CHARACTER_PER_LINE];
            //READ LINE BY LINE
        }
        reader.close();
    }
    catch (std::runtime_error &err) {
        std::cout << err.what() << std::endl;
    }
}

Playlist::~Playlist() {
    destroy();
}

void Playlist::playPlaylist() {
    std::ofstream writer("outputPlaylist.bin", std::ios::binary);
    if (!writer.is_open()) {
        throw std::runtime_error("outputPlaylist.bin couldn't be opened");
    }
    PlaylistSongs *currSong = songs;
    while (currSong != nullptr) {

        writer << currSong->sound;
        currSong = currSong->next;
    }
    writer.close();
}

void Playlist::destroy() {
    destroyRecursive(songs);
}

void Playlist::destroyRecursive(Playlist::PlaylistSongs *&currSong) {
    if (currSong == nullptr) {
        return;
    }
    destroyRecursive(currSong->next);
    delete currSong->sound;
    delete currSong;
    currSong = nullptr;
}

Playlist::PublicSongInfo &Playlist::operator[](size_t index) {
    PlaylistSongs *curr = songs;
    while (curr != nullptr) {
        if (curr->index == index) {
            PublicSongInfo songInfo{curr->sound, curr->songType};
            return songInfo;
        }
        curr = curr->next;
    }

    throw std::out_of_range("Index out of range");
}
