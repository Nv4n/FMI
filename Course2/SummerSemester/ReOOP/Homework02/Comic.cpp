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

