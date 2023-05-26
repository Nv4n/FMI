//
// Created by Sybatron on 5/26/2023.
//

#include "Library.h"

std::ostream &operator<<(std::ostream &os, const Library &library) {
    os << "users: " << library.users << " items: " << library.items;
    return os;
}

void Library::addItem(Item *&item) {
    items.pushBack(item);
}

void Library::removeItem(const size_t libraryID) {

}
