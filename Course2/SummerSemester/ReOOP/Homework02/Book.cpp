//
// Created by Sybatron on 5/26/2023.
//
#include <iostream>
#include "Book.h"


Book::Book() = default;

Book::~Book() = default;


Book::Book(const MinString &_title, const MinString &_shortDescr, size_t _libraryId, unsigned short _publishYear,
           const MinString &_author, const MinString &_publisher, const Genre &_genre)
        : Item(_title,
               _shortDescr,
               _libraryId,
               _publishYear) {
    setAuthor(_author);
    setPublisher(_publisher);
    setGenre(_genre);
    type = ItemType::BOOK;
}

// Copy

Book &Book::operator=(const Book &other) {
    if (this != &other) {
        Item::operator=(other);
        copy(other);
    }

    return *this;
}

Book::Book(const Book &other) : Item(other) {
    copy(other);
}

Item *Book::clone() const {
    return new Book(*this);
}

// Getters and Setters
const MinString &Book::getAuthor() const {
    return author;
}

/**
 *
 * @param _author
 * @throws invalid_argument("Author can't be empty")
 */
void Book::setAuthor(const MinString &_author) {
    if (_author.getLength() == 0) {
        throw std::invalid_argument("Author can't be empty");
    }
    author = _author;
}

const MinString &Book::getPublisher() const {
    return publisher;
}

/**
 *
 * @param _publisher
 * @throws invalid_argument("Publisher can't be empty")
 */
void Book::setPublisher(const MinString &_publisher) {
    if (_publisher.getLength() == 0) {
        throw std::invalid_argument("Publisher can't be empty");
    }
    publisher = _publisher;
}

const Genre &Book::getGenre() const {
    return genre;
}

void Book::setGenre(const Genre &_genre) {
    Book::genre = _genre;
}

// Write and Read
std::ostream &Book::out(std::ostream &os) const {
    os << static_cast<int>(type) << '\n';
    os << libraryID << '\n';
    os << publishYear << '\n';
    os << title << '\n';
    os << shortDescr << '\n';
    os << genre << '\n';
    os << author << '\n';
    os << publisher << '\n';

    return os;
}

std::istream &operator>>(std::istream &is, Book &book) {
    size_t libraryID;
    unsigned short publishYear;
    MinString title;
    MinString shortDescr;
    Genre genre{};
    MinString author;
    MinString publisher;
    is >> libraryID;
    is >> publishYear;
    is >> title;
    is >> shortDescr;
    is >> genre;
    is >> author;
    is >> publisher;
    book.type = ItemType::BOOK;
    book.title = title;
    book.shortDescr = shortDescr;
    book.libraryID = libraryID;
    book.publishYear = publishYear;
    book.author = author;
    book.publisher = publisher;
    book.genre = genre;

    return is;
}

// Private
void Book::copy(const Book &other) {
    author = other.author;
    publisher = other.publisher;
    genre = other.genre;
}

