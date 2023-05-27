//
// Created by Sybatron on 5/26/2023.
//

#ifndef HW02_LIBRARY_BOOK_H
#define HW02_LIBRARY_BOOK_H

#include "Item.h"

#pragma once

class Book : public virtual Item {
protected:
    MinString author;
    //TODO Genre
    MinString publisher;
//    жанр - 16 битово цяло число - прочетете по-долу
//            кратко описание;
public:
    virtual ~Book() override;
};


#endif //HW02_LIBRARY_BOOK_H
