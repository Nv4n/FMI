//
// Created by Sybatron on 5/26/2023.
//
#include <iostream>
#include "Item.h"

// Constructors
Item::~Item() = default;

Item::Item() = default;

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

Item::Item(Item &&other) noexcept {
    move(other);
}

Item &Item::operator=(Item &&other) noexcept {
    if (this != &other) {
        move(other);
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
std::ostream &operator<<(std::ostream &os, const Item &item) {
//  заглавие, тип, кратко описание, библиотечен номер.
    os << "Title: " << item.title
       << " Type: " << item.getTypeText()
       << " Short description: " << item.shortDescr
       << " ID: " << item.libraryID;
    return os;
}


// Private
void Item::copy(const Item &other) {
    title = other.title;
    shortDescr = other.shortDescr;
    libraryID = other.libraryID;
    publishYear = other.publishYear;
    type = other.type;
}

void Item::move(Item &other) {
    title = other.title;
    shortDescr = other.shortDescr;
    libraryID = other.libraryID;
    publishYear = other.publishYear;
    type = other.type;
    other.title.erase();
    other.libraryID = 0;
    other.shortDescr.erase();
    other.publishYear = 1900;
}

