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
    Genre genre{};
public:
    Book();

    Book(const MinString &_title, const MinString &_shortDescr, size_t _libraryId, unsigned short _publishYear,
         const MinString &_author, const MinString &_publisher, const Genre &_genre);

    virtual ~Book() override;

    Book(const Book &other);

    Book &operator=(const Book &other);

    Item *clone() const override;

    const MinString &getAuthor() const;

    void setAuthor(const MinString &_author);

    const MinString &getPublisher() const;

    void setPublisher(const MinString &_publisher);

    const Genre &getGenre() const;

    void setGenre(const Genre &_genre);

    friend std::istream &operator>>(std::istream &is, Book &book);

protected:
    void copy(const Book &other);

    std::ostream &out(std::ostream &) const override;

};


#endif //HW02_LIBRARY_BOOK_H
