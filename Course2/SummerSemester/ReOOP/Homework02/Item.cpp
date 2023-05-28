//
// Created by Sybatron on 5/26/2023.
//
#include <iostream>
#include "Item.h"

// Constructors
Item::~Item() = default;

Item::Item() = default;

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

