//
// Created by Sybatron on 5/26/2023.
//
#include <iostream>
#include <fstream>
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

// Read and Write
std::ostream &operator<<(std::ostream &os, const Item &item) {
    
}
