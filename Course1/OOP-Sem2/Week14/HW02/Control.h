//
// Created by Sybatron on 6/5/2022.
//

#ifndef HW02_CONTROL_H
#define HW02_CONTROL_H

struct Coordinates {
    size_t x;
    size_t y;
};

class Control {
protected:
    static size_t Id;
    size_t controlId;
    Coordinates position;
    size_t size;
    char *text;
};

size_t Control::Id = 0;

#endif //HW02_CONTROL_H
