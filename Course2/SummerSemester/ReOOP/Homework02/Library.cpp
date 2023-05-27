//
// Created by Sybatron on 5/26/2023.
//

#include "Library.h"

void Library::addItem(Item *&item) {
    items.pushBack(item);
}

void Library::removeItem(const size_t libraryID) {
    for (int i = 0; i < items.getSize(); ++i) {
        if (libraryID == items[i]->getLibraryId()) {
            items.remove(i);
            break;
        }
    }
}

void Library::printItems() {

    items.sort([](Item *&lvs, Item *&rvs) -> int {
        int yearComparison = lvs->getPublishYear() - rvs->getPublishYear();
        if (yearComparison == 0) {
            if (lvs->getTitle() > rvs->getTitle()) {
                return 1;
            }
            return -1;
        }
        return yearComparison > 0 ? 1 : -1;
    });

    for (int i = 0; i < items.getSize(); ++i) {

    }
}
