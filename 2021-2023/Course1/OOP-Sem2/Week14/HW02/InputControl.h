//
// Created by Sybatron on 6/5/2022.
//

#ifndef HW02_INPUTCONTROL_H
#define HW02_INPUTCONTROL_H


#include "Control.h"

#pragma once

class InputControl : virtual public Control {
public:
    virtual Control *input() = 0;
};


#endif //HW02_INPUTCONTROL_H
