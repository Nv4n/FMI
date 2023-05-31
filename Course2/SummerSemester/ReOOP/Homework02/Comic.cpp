//
// Created by Sybatron on 5/26/2023.
//

#include "Comic.h"

Comic::Comic() = default;

Comic::~Comic() = default;

Comic::Comic(const MinString &_title, const MinString &_shortDescr, size_t _libraryId, unsigned short _publishYear,
             const MinString &_author, const MinString &_publisher, const Genre &_genre, PeriodicPeriod _period,
             unsigned int _issue)
        : Book(_title, _shortDescr, _libraryId, _publishYear, _author, _publisher, _genre),
          PeriodicPublication(_title, _shortDescr, _libraryId, _publishYear, _period,
                              _issue) {}

Comic::Comic(const Comic &other) : Item(other), Book(other), PeriodicPublication(other) {}

Comic &Comic::operator=(const Comic &other) {
    if (this != &other) {
        Book::operator=(other);
        PeriodicPublication::operator=(other);
    }
    return *this;
}

Item *Comic::clone() const {
    return new Comic(*this);
}

std::ostream &Comic::out(std::ostream &os) const {
    os << static_cast<int>(type);
    os << libraryID;
    os << publishYear;
    os << title;
    os << shortDescr;
    os << genre;
    os << author;
    os << publisher;
    os << static_cast<int>(period);
    os << issue;

    return os;
}

std::istream &operator>>(std::istream &is, Comic &comic) {
    size_t libraryID;
    unsigned short publishYear;
    MinString title;
    MinString shortDescr;
    Genre genre{};
    MinString author;
    MinString publisher;
    int period;
    unsigned int issue;
    is >> libraryID;
    is >> publishYear;
    is >> title;
    is >> shortDescr;
    is >> genre;
    is >> author;
    is >> publisher;
    is >> period;
    is >> issue;
    comic.type = ItemType::COMIC;
    comic.title = title;
    comic.shortDescr = shortDescr;
    comic.libraryID = libraryID;
    comic.publishYear = publishYear;
    comic.author = author;
    comic.publisher = publisher;
    comic.genre = genre;
    comic.period = static_cast<PeriodicPeriod>(period);
    comic.issue = issue;

    return is;
}

