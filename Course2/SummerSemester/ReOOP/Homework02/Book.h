//
// Created by Sybatron on 5/26/2023.
//

#ifndef HW02_LIBRARY_BOOK_H
#define HW02_LIBRARY_BOOK_H

#include "Item.h"
#include "Genre.h"

#pragma once

class Book : public virtual Item {
protected:
    MinString author;
    //TODO Genre
    MinString publisher;
    Genre genre;
public:
    virtual ~Book() override;
};


#endif //HW02_LIBRARY_BOOK_H
