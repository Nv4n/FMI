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

#pragma once
using SortLambdaType = int (*)(Item *&, Item *&);

class Library {
private:

    MinVector<User> users;
    MinVector<Item *> items;

    //TODO READ AND WRITE LIBRARY in binary format
public:
    void addItem(Item *&item);

    void removeItem(size_t libraryID);

    void addUser(User &user);

    void removeUser(MinString &username);

    void printItems();

    void printOverdueItems();

    void printUsersByBorrowedId();

    void printUsers();

    //TODO
    void borrowItem(size_t libraryId);

    void returnItem(size_t libraryId);

private:
    SortLambdaType getSortFunc();
};


#endif //HW02_LIBRARY_LIBRARY_H
