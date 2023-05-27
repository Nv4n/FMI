//
// Created by Sybatron on 5/26/2023.
//

#ifndef HW02_LIBRARY_USER_H
#define HW02_LIBRARY_USER_H

#include "MinString.h"
#include "MinVector.h"
#include "Item.h"

#pragma once
enum class ItemStatus {
    UNKNOWN = -1,
    READ,
    BORROWED,
    REREAD,
    NOT_BORROWED
};

struct UserItem {
    ItemStatus status;
    size_t libraryId;
};

class User {
private:
    MinString name;
    MinVector<UserItem> items;
public:
    //TODO
    //  ADD MOVE, COPY CONSTRUCTORS
    User();

    ~User();

    const MinString &getName() const;

    friend bool operator==(const User &lvs, const User &rvs);

    friend bool operator!=(const User &lvs, const User &rvs);

    friend bool operator>(const User &lvs, const User &rvs);

    friend bool operator>=(const User &lvs, const User &rvs);

    friend bool operator<(const User &lvs, const User &rvs);

    friend bool operator<=(const User &lvs, const User &rvs);

    ItemStatus operator[](size_t index) const;

    User &operator+=(size_t libraryId);

    friend User &operator+(const User &lvs, size_t libraryId);

    User &operator-=(size_t libraryId);

    friend User &operator-(const User &lvs, size_t libraryId);
};


#endif //HW02_LIBRARY_USER_H
