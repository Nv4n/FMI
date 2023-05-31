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
using SortLambdaType = int (*)(Item *&, Item *&);

struct LibraryItem {
//    item:
};

class Library {
private:
// TODO USE CHRONO OR TIME FOR THE DATETIME
    MinDate currentDate;
    MinVector<User> users;
    MinVector<Item *> items;

    //TODO READ AND WRITE LIBRARY in binary format
public:
    Library();

    ~Library();

    void addItem(Item *&item);

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
