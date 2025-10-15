//
// Created by Sybatron on 5/30/2022.
//

#ifndef IMAGEEDITOR_PIXEL_H
#define IMAGEEDITOR_PIXEL_H

#include <iostream>

class Pixel {
private:
    uint8_t red;
    uint8_t green;
    uint8_t blue;
public:
    Pixel();

    Pixel(uint8_t value) : red(value), green(value), blue(value) {};
};

#endif //IMAGEEDITOR_PIXEL_H
