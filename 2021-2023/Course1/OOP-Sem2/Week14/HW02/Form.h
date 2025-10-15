//
// Created by Sybatron on 6/5/2022.
//

#ifndef HW02_FORM_H
#define HW02_FORM_H

#include "Control.h"

#pragma once

class Form {
private:
    char *name;
    Control **controls;
    size_t size;
    size_t capacity;
public:
    Form() = delete;

    Form(const char *name);

    Form(const Form &other);

    Form &operator=(const Form &other);

    virtual ~Form();

    const Control *operator[](size_t) const;

    void addControl(const Control *control);

    void print();

private:
    void resize();

    void copy(const Form &other);

    void destroy();
};


#endif //HW02_FORM_H
