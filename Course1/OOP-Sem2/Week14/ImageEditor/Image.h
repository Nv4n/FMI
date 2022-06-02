//
// Created by Sybatron on 5/30/2022.
//

#ifndef IMAGEEDITOR_IMAGE_H
#define IMAGEEDITOR_IMAGE_H

#include <iostream>
#include "Pixel.h"

class Image {
private:
    Pixel **pixels;
    uint8_t rows;
    uint8_t colums;
public:
    Image(uint8_t rows, uint8_t columns) : rows(rows), colums(columns) {
        pixels = new Pixel *[rows];
        for (int i = 0; i < rows; ++i) {
            pixels[i] = new Pixel[columns];
        }
    }

    ~Image() {
        for (int i = 0; i < rows; ++i) {
            delete[] pixels[i];
        }
        delete[] pixels;
    }

};

#endif //IMAGEEDITOR_IMAGE_H
