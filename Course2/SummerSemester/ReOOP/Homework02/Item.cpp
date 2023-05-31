//
// Created by Sybatron on 5/26/2023.
//
#include <iostream>
#include "Item.h"

// Constructors
Item::~Item() = default;

Item::Item() = default;

Item::Item(const MinString &_title, const MinString &_shortDescr, size_t _libraryId, unsigned short _publishYear) {
    setTitle(_title);
    setShortDescr(_shortDescr);
    setLibraryId(_libraryId);
    setPublishYear(_publishYear);
}

// Copy and Move

Item::Item(const Item &other) {
    copy(other);
}

Item &Item::operator=(const Item &other) {
    if (this != &other) {
        copy(other);
    }
    return *this;
}

// Getters and Setters
size_t Item::getLibraryId() const {
    return libraryID;
}

ItemType Item::getType() const {
    return type;
}

const MinString &Item::getTitle() const {
    return title;
}

const MinString &Item::getShortDescr() const {
    return shortDescr;
}

unsigned short Item::getPublishYear() const {
    return publishYear;
}

const char *Item::getTypeText() const {
    switch (type) {
        case ItemType::BOOK:
            return "BOOK";
        case ItemType::PERIODIC_PUBLICATION:
            return "PERIODIC_PUBLICATION";
        case ItemType::COMIC:
            return "COMIC";
        default:
            return "UNKNOWN";
    }
}

// Read and Write
std::ostream &operator<<(std::ostream &os, const Item *&item) {
    return item->out(os);
}

// Private
void Item::copy(const Item &other) {
    title = other.title;
    shortDescr = other.shortDescr;
    libraryID = other.libraryID;
    publishYear = other.publishYear;
    type = other.type;
}

/**
 *
 * @param _title
 * @throws invalid_argument("Title can't be empty")
 */
void Item::setTitle(const MinString &_title) {
    if (_title.getLength() == 0) {
        throw std::invalid_argument("Title can't be empty");
    }
    title = _title;
}

/**
 *
 * @param _shortDescr
 * @throws invalid_argument("Short description can't be empty")
 */
void Item::setShortDescr(const MinString &_shortDescr) {
    if (_shortDescr.getLength() == 0) {
        throw std::invalid_argument("Short description can't be empty");
    }
    shortDescr = _shortDescr;
}

void Item::setLibraryId(size_t libraryId) {
    libraryID = libraryId;
}

/**
 *
 * @param _publishYear
 * @throws invalid_argument("Publish year is out of range")
 */
void Item::setPublishYear(unsigned short _publishYear) {
    if (_publishYear < 1000 || _publishYear > 2023) {
        throw std::invalid_argument("Publish year is out of range");
    }
    Item::publishYear = _publishYear;
}

