//
// Created by Sybatron on 6/5/2022.
//

#ifndef HW02_LISTBOX_H
#define HW02_LISTBOX_H


#include "InputControl.h"

#pragma once

class ListBox : public InputControl {
public:
    ListBox(const char *text, const size_t positionX, const size_t positionY, const size_t optionIndex);

    Control *clone() const override;

    Control *input() override;

};


#endif //HW02_LISTBOX_H
