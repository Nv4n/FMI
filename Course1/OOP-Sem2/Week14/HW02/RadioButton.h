//
// Created by Sybatron on 6/5/2022.
//

#ifndef HW02_RADIOBUTTON_H
#define HW02_RADIOBUTTON_H


#include "InputControl.h"

#pragma once

class RadioButton : public InputControl {
public:
    RadioButton() {};

    RadioButton(const char *text, const size_t positionX, const size_t positionY, size_t optionIndex);

    Control *clone() const override;

    Control *input() override;

    const char *print() override;

};


#endif //HW02_RADIOBUTTON_H
