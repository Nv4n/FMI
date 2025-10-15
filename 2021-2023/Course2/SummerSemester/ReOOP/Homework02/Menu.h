//
// Created by Sybatron on 5/31/2023.
//

#ifndef HW02_LIBRARY_MENU_H
#define HW02_LIBRARY_MENU_H

#include "Library.h"

#pragma once

enum class MenuOptions {
    ADD_ITEM = 0,
    REMOVE_ITEM = 1,

    COUNT
};

class Menu {
private:
    Library library;
public:
    Menu();

    ~Menu();

    void getUserInput();

private:
    void saveState();

    void readState();
};


#endif //HW02_LIBRARY_MENU_H
