//
// Created by Sybatron on 5/26/2023.
//

#ifndef HW02_LIBRARY_USER_H
#define HW02_LIBRARY_USER_H

#include "MinString.h"
#include "MinVector.h"
#include "MinDate.h"
#include "Item.h"

#pragma once
enum class ItemStatus {
    READ,
    BORROWED,
    REREAD,
    NOT_BORROWED
};

struct UserItem {
    ItemStatus status;
    size_t libraryId;
    MinDate borrowDate;
    MinDate dueDate;
};

class User {
private:
    MinString name;
    MinVector<UserItem> items;
    unsigned short borrowedCount;
public:
    User();

    ~User();

    User(const User &other);

    User &operator=(const User &other);

    const MinString &getName() const;

    unsigned short getBorrowedCount() const;

    bool isOverDue(size_t libraryId, const MinDate &dateCompare);

    const MinVector<size_t> &getOverDueIds(const MinDate &dateCompare);

    friend bool operator==(const User &lvs, const User &rvs);

    friend bool operator!=(const User &lvs, const User &rvs);

    friend bool operator>(const User &lvs, const User &rvs);

    friend bool operator>=(const User &lvs, const User &rvs);

    friend bool operator<(const User &lvs, const User &rvs);

    friend bool operator<=(const User &lvs, const User &rvs);

    ItemStatus operator[](size_t libraryId) const;

    User &operator+=(size_t libraryId);

    friend User &operator+(const User &lvs, size_t libraryId);

    User &operator-=(size_t libraryId);

    friend User &operator-(const User &lvs, size_t libraryId);

private:
    void copy(const User &other);
};


#endif //HW02_LIBRARY_USER_H
