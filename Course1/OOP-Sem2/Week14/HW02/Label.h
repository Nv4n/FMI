//
// Created by Sybatron on 6/5/2022.
//

#ifndef HW02_LABEL_H
#define HW02_LABEL_H


#include "OutputControl.h"

#pragma once

class Label : public OutputControl {
public:
    Label(const char *text, const size_t positionX, const size_t positionY);

    Control *clone() const override;
};


#endif //HW02_LABEL_H
