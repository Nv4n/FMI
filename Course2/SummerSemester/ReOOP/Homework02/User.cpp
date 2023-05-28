//
// Created by Sybatron on 5/26/2023.
//
#include <stdexcept>
#include "User.h"

// Constructors
User::User() = default;

User::~User() = default;

// Getters and Setters
const MinString &User::getName() const {
    return name;
}

// Comparators
bool operator==(const User &lvs, const User &rvs) {
    return lvs.name == rvs.name;
}

bool operator!=(const User &lvs, const User &rvs) {
    return !(lvs == rvs);
}

bool operator>(const User &lvs, const User &rvs) {
    size_t lvsRead = 0;
    for (int i = 0; i < lvs.items.getSize(); ++i) {
        if (lvs.items[i].status == ItemStatus::READ
            || lvs.items[i].status == ItemStatus::REREAD) {
            lvsRead++;
        }
    }

    size_t rvsRead = 0;
    for (int i = 0; i < rvs.items.getSize(); ++i) {
        if (rvs.items[i].status == ItemStatus::READ
            || rvs.items[i].status == ItemStatus::REREAD) {
            rvsRead++;
        }
    }

    return lvsRead > rvsRead;
}

bool operator>=(const User &lvs, const User &rvs) {
    return !(lvs < rvs);
}

bool operator<(const User &lvs, const User &rvs) {
    size_t lvsRead = 0;
    for (int i = 0; i < lvs.items.getSize(); ++i) {
        if (lvs.items[i].status == ItemStatus::READ
            || lvs.items[i].status == ItemStatus::REREAD) {
            lvsRead++;
        }
    }

    size_t rvsRead = 0;
    for (int i = 0; i < rvs.items.getSize(); ++i) {
        if (rvs.items[i].status == ItemStatus::READ
            || rvs.items[i].status == ItemStatus::REREAD) {
            rvsRead++;
        }
    }

    return lvsRead < rvsRead;
}

bool operator<=(const User &lvs, const User &rvs) {
    return !(lvs > rvs);
}

/**
 *
 * @param index
 * @return User's book status
 * @throw out_of_range("Index out of range")
 */
ItemStatus User::operator[](size_t index) const {
    if (index >= items.getSize()) {
        throw std::out_of_range("Index out of range");
    }

    return items[index].status;
}

User &User::operator+=(const size_t libraryId) {
    for (int i = 0; i < items.getSize(); ++i) {
        if (items[i].libraryId == libraryId
            && (items[i].status == ItemStatus::BORROWED
                || items[i].status == ItemStatus::REREAD)) {
            std::cout << "Item is already borrowed" << std::endl;
            return *this;
        }
    }

    UserItem item = {ItemStatus::BORROWED, libraryId};
    items.pushBack(item);
    return *this;
}

User &operator+(const User &lvs, const size_t libraryId) {
    User result(lvs);
    result += libraryId;
    return result;
}

User &User::operator-=(size_t libraryId) {
    for (int i = 0; i < items.getSize(); ++i) {
        if (items[i].libraryId == libraryId
            && (items[i].status == ItemStatus::BORROWED
                || items[i].status == ItemStatus::REREAD)) {
            items[i].status = ItemStatus::READ;
            return *this;
        }
    }

    std::cout << "Item is already returned" << std::endl;
    return *this;
}

User &operator-(const User &lvs, size_t libraryId) {
    User result(lvs);
    result -= libraryId;
    return result;
}
