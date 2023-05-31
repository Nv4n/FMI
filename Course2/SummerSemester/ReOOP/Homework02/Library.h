//
// Created by Sybatron on 5/26/2023.
//

#ifndef HW02_LIBRARY_LIBRARY_H
#define HW02_LIBRARY_LIBRARY_H

#include <ostream>
#include "MinVector.h"
#include "User.h"
#include "Item.h"
#include "PeriodicPublication.h"
#include "MinDate.h"

#pragma once
struct LibraryItem {
    Item *item;
    size_t copiesCount;
    size_t borrowedCopiesCount;
};

using SortLambdaType = int (*)(LibraryItem &, LibraryItem &);

class Library {
private:
    MinDate currentDate;
    MinVector<User> users;
    MinVector<LibraryItem> items;

    //TODO READ AND WRITE LIBRARY in binary format
public:
    Library();

    ~Library();

    void addItem(Item *&item, size_t count);

    void removeItem(size_t libraryID);

    void addUser(User &user);

    void removeUser(MinString &username);

    void printItems();

    void printOverdueItems();

    void printUsersByBorrowedId();

    void printUsers();

    void borrowItem(const MinString &username, size_t libraryId);

    void returnItem(const MinString &username, size_t libraryId);

private:
    SortLambdaType getSortFunc();

    size_t hasUserAndItem(const MinString &username, size_t libraryId);
};


#endif //HW02_LIBRARY_LIBRARY_H
