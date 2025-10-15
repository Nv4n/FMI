//
// Created by Sybatron on 6/5/2022.
//

#ifndef HW02_CHECKBOX_H
#define HW02_CHECKBOX_H

#include "InputControl.h"

#pragma once

class Checkbox : virtual public InputControl {
private:
    bool isChecked;

    Checkbox(const char *text, const size_t positionX, const size_t positionY, const bool isChecked);

public:
    Checkbox(const Checkbox &other);

    Checkbox &operator=(const Checkbox &other);


    Control *clone() const override;

    Control *input() override;


private:
    void copy(const Checkbox &other);
};


#endif //HW02_CHECKBOX_H
