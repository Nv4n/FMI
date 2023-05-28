//
// Created by Sybatron on 5/26/2023.
//

#include "Book.h"

Book::~Book() = default;

const MinString &Book::getAuthor() const {
    return author;
}

void Book::setAuthor(const MinString &_author) {
    author = _author;
}

const MinString &Book::getPublisher() const {
    return publisher;
}

void Book::setPublisher(const MinString &_publisher) {
    publisher = _publisher;
}

const Genre &Book::getGenre() const {
    return genre;
}

void Book::setGenre(const Genre &_genre) {
    Book::genre = _genre;
}
