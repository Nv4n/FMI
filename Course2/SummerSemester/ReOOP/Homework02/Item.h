//
// Created by Sybatron on 5/26/2023.
//

#ifndef HW02_LIBRARY_ITEM_H
#define HW02_LIBRARY_ITEM_H

#include <iostream>
#include "MinString.h"

#pragma once

class Item {
protected:
    MinString title;
    MinString shortDescr;
    size_t libraryID;
    unsigned int publishYear;

public:
    virtual ~Item();
};


#endif //HW02_LIBRARY_ITEM_H
