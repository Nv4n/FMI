//
// Created by Sybatron on 6/5/2022.
//

#include <cstring>
#include "Form.h"

Form::~Form() {
    destroy();
}

void Form::destroy() {

    delete[] controls;
    delete[] name;
}
