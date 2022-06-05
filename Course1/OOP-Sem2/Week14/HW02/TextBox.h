//
// Created by Sybatron on 6/5/2022.
//

#ifndef HW02_TEXTBOX_H
#define HW02_TEXTBOX_H


#include "IOControl.h"

#pragma once

class TextBox : virtual public IOControl {
public:
    TextBox(const char *text, const size_t positionX, const size_t positionY, const size_t width, const size_t height);
};


#endif //HW02_TEXTBOX_H
