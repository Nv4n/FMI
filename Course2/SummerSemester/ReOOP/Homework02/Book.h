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
    MinString publisher;
    Genre genre;
public:
    virtual ~Book() override;

    const MinString &getAuthor() const;

    void setAuthor(const MinString &_author);

    const MinString &getPublisher() const;

    void setPublisher(const MinString &_publisher);

    const Genre &getGenre() const;

    void setGenre(const Genre &_genre);
};


#endif //HW02_LIBRARY_BOOK_H
