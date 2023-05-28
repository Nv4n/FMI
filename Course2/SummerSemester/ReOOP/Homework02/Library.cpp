//
// Created by Sybatron on 5/26/2023.
//

#include <stdexcept>
#include "Library.h"

// Add and Remove
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
        std::cout << "#" << i + 1 << " " << items[i] << std::endl;
    }
}

void Library::printOverdueItems() {
    items.sort(getSortFunc());
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
        users[ind] -= libraryId;

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
        users[ind] += libraryId;

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
 * @throws invalid_argument When either username or libraryId doesn't exist
 */
size_t Library::hasUserAndItem(const MinString &username, size_t libraryId) {
    size_t userIndex = 0;
    for (; userIndex < users.getSize(); ++userIndex) {
        if (users[userIndex].getName() == username) {
            break;
        }
    }
    if (userIndex == users.getSize()) {
        throw std::invalid_argument("User doesn't exist");
    }

    size_t i = 0;
    for (; i < items.getSize(); ++i) {
        if (items[i]->getLibraryId() == libraryId) {
            break;
        }
    }
    if (i == items.getSize()) {
        throw std::invalid_argument("Item doesn't exist");
    }
    return userIndex;
}


SortLambdaType Library::getSortFunc() {
    return [](Item *&lvs, Item *&rvs) -> int {
        int yearComparison = lvs->getPublishYear() - rvs->getPublishYear();
        if (yearComparison != 0) {
            return yearComparison > 0 ? 1 : -1;
        }

        ItemType lvsType = lvs->getType();
        ItemType rvsType = rvs->getType();

        if (!((lvsType == ItemType::COMIC || lvsType == ItemType::PERIODIC_PUBLICATION)
              && (rvsType == ItemType::COMIC || rvsType == ItemType::PERIODIC_PUBLICATION))) {

            if (lvs->getTitle() > rvs->getTitle()) {
                return 1;
            }
            return -1;
        }

        PeriodicPublication *lvsPeriodic = dynamic_cast<PeriodicPublication *>(lvs);
        PeriodicPublication *rvsPeriodic = dynamic_cast<PeriodicPublication *>(rvs);
        if (!(lvsPeriodic != nullptr && rvsPeriodic != nullptr)) {
            return -1;
        }

        if (lvsPeriodic->getTitle() > rvsPeriodic->getTitle()) {
            return 1;
        }
        if (lvsPeriodic->getTitle() < rvsPeriodic->getTitle()) {
            return -1;
        }

        long countComparison = lvsPeriodic->getCount() - rvsPeriodic->getCount();
        if (countComparison != 0) {
            return countComparison > 0 ? 1 : -1;
        }
        return 0;
    };
}

