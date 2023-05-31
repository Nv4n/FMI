//
// Created by Sybatron on 5/26/2023.
//

#ifndef HW02_LIBRARY_LIBRARY_H
#define HW02_LIBRARY_LIBRARY_H

#include <ostream>
#include "MinVector.h"
#include "MinDate.h"
#include "User.h"
#include "Item.h"
#include "Book.h"
#include "PeriodicPublication.h"
#include "Comic.h"

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
public:
    Library();

    ~Library();

    void addItem(const Item *&item, size_t count);

    void removeItem(size_t libraryID);

    void addUser(const User &user);

    void removeUser(const MinString &username);

    void printItems();

    void printOverdueItems();

    void printUsersByBorrowedId(size_t libraryId);

    void printUsers();

    void borrowItem(const MinString &username, size_t libraryId);

    void returnItem(const MinString &username, size_t libraryId);

    friend std::ostream &operator<<(std::ostream &os, const Library &library);

    friend std::istream &operator>>(std::istream &is, Library &library);

private:
    SortLambdaType getSortFunc();

    size_t hasUserAndItem(const MinString &username, size_t libraryId);
};


#endif //HW02_LIBRARY_LIBRARY_H
