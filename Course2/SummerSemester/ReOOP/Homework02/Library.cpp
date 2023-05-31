//
// Created by Sybatron on 5/26/2023.
//
#include <stdexcept>
#include "Library.h"

Library::Library() = default;

Library::~Library() = default;

// Add and Remove
void Library::addItem(Item *&item, size_t count) {
    items.pushBack({item, count, 0});
}

void Library::removeItem(const size_t libraryID) {
    for (int i = 0; i < items.getSize(); ++i) {
        if (libraryID == items[i].item->getLibraryId()) {
            items.remove(i);
            break;
        }
    }
}

void Library::addUser(User &user) {
    users.pushBack(user);
}

void Library::removeUser(MinString &username) {
    for (int i = 0; i < users.getSize(); ++i) {
        if (username == users[i].getName()) {
            users.remove(i);
            break;
        }
    }
}

// Print
void Library::printItems() {
    items.sort(getSortFunc());

    for (int i = 0; i < items.getSize(); ++i) {
        std::cout << "#" << i + 1 << " " << items[i].item << std::endl;
    }
}

void Library::printOverdueItems() {
    items.sort(getSortFunc());
    for (int i = 0; i < users.getSize(); ++i) {

    }
// TODO ALGORITHM OVERDUE ITEMS
//  Go trough users
//  Get books with STATUS = OVERDUE
//  Remove duplicates ids
//  Get all books with these ids
//  Sort
//  Print
}

void Library::printUsersByBorrowedId() {
// TODO ALGORITHM BORROWED ID ITEMS
//  Go trough users
//  Get books with STATUS = BORROWED
//  Remove duplicates ids
//  Get all books with these ids
//  Sort
//  Print
}

void Library::printUsers() {
// TODO ALGORITHM PRINT USERS
//  Go trough users
//  Count books with STATUS = READ
//  Sort
//  Print
}

// Borrow and Return books
/**
 *
 * @param username
 * @param libraryId
 * @throws invalid_argument When either username or libraryId doesn't exist
 */
void Library::borrowItem(const MinString &username, size_t libraryId) {
    try {
        size_t ind = hasUserAndItem(username, libraryId);

        users[ind] += libraryId;

    } catch (std::invalid_argument &e) {
        throw std::invalid_argument(e.what());
    }
}

/**
 *
 * @param username
 * @param libraryId
 * @throws invalid_argument When either username or libraryId doesn't exist
 */
void Library::returnItem(const MinString &username, size_t libraryId) {
    try {
        size_t ind = hasUserAndItem(username, libraryId);
        users[ind] -= libraryId;

    } catch (std::invalid_argument &e) {
        throw std::invalid_argument(e.what());
    }
}

// Private

/**
 *
 * @param username
 * @param libraryId
 * @return <b>userIndex</b>
 * @throws invalid_argument("Item is out of available copies")
 * @throws invalid_argument("Item doesn't exist")
 * @throws invalid_argument("User doesn't exist")
 */
size_t Library::hasUserAndItem(const MinString &username, size_t libraryId) {
    size_t itemIndex = 0;
    for (; itemIndex < items.getSize(); ++itemIndex) {
        if (items[itemIndex].item->getLibraryId() != libraryId) {
            continue;
        }
        if (items[itemIndex].copiesCount <= items[itemIndex].borrowedCopiesCount) {
            throw std::invalid_argument("Item is out of available copies");
        }
        break;

    }
    if (itemIndex == items.getSize()) {
        throw std::invalid_argument("Item doesn't exist");
    }

    size_t userIndex = 0;
    for (; userIndex < users.getSize(); ++userIndex) {
        if (users[userIndex].getName() == username) {
            break;
        }
    }
    if (userIndex == users.getSize()) {
        throw std::invalid_argument("User doesn't exist");
    }
    return userIndex;
}


SortLambdaType Library::getSortFunc() {
    return [](LibraryItem &lvs, LibraryItem &rvs) -> int {
        int yearComparison = lvs.item->getPublishYear() - rvs.item->getPublishYear();
        if (yearComparison != 0) {
            return yearComparison > 0 ? 1 : -1;
        }

        ItemType lvsType = lvs.item->getType();
        ItemType rvsType = rvs.item->getType();

        if (!((lvsType == ItemType::COMIC || lvsType == ItemType::PERIODIC_PUBLICATION)
              && (rvsType == ItemType::COMIC || rvsType == ItemType::PERIODIC_PUBLICATION))) {

            if (lvs.item->getTitle() > rvs.item->getTitle()) {
                return 1;
            }
            return -1;
        }

        PeriodicPublication *lvsPeriodic = dynamic_cast<PeriodicPublication *>(lvs.item);
        PeriodicPublication *rvsPeriodic = dynamic_cast<PeriodicPublication *>(rvs.item);
        if (!(lvsPeriodic != nullptr && rvsPeriodic != nullptr)) {
            return -1;
        }

        if (lvsPeriodic->getTitle() > rvsPeriodic->getTitle()) {
            return 1;
        }
        if (lvsPeriodic->getTitle() < rvsPeriodic->getTitle()) {
            return -1;
        }

        long countComparison = lvsPeriodic->getIssue() - rvsPeriodic->getIssue();
        if (countComparison != 0) {
            return countComparison > 0 ? 1 : -1;
        }
        return 0;
    };
}



