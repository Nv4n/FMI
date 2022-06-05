//
// Created by Sybatron on 6/5/2022.
//

#ifndef HW02_CONTROL_H
#define HW02_CONTROL_H

#include <cstring>
#include <iostream>


struct Coordinates {
    size_t x;
    size_t y;
};
struct Size {
    size_t width;
    size_t height;
};
static size_t Id = 0;
#pragma once

class Control {
protected:

    size_t controlId;
    Coordinates position;
    Size size;
    char *text;
    char *description;

    Control() = default;

public:
    Control(const Control &other);

    Control &operator=(const Control &other);

    virtual ~Control();

    size_t getControlId() const;

    const Coordinates &getPosition() const;

    const Size &getSize() const;

    const char *getText() const;

protected:
    void setPosition(size_t X, size_t Y);

    void setSize(size_t width, size_t height);

    void setControlId();
    
private:

    void destroy();

    void copy(const Control &other);
};

#endif //HW02_CONTROL_H
