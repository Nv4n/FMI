//
// Created by Sybatron on 5/26/2023.
//
#include "User.h"

// Constructors
User::User() = default;

User::~User() = default;

// Copy
User::User(const User &other) {
    copy(other);
}

User &User::operator=(const User &other) {
    if (this != &other) {
        items.erase();
        copy(other);
    }
    return *this;
}

// Getters and Setters
const MinString &User::getName() const {
    return name;
}

unsigned short User::getBorrowedCount() const {
    return borrowedCount;
}


bool User::isOverDue(size_t libraryId, const MinDate &dateCompare) {
    for (int i = 0; i < items.getSize(); ++i) {
        if (items[i].libraryId != libraryId) {
            continue;
        }
        if (items[i].status == ItemStatus::BORROWED
            || items[i].status == ItemStatus::REREAD) {
            return items[i].dueDate < dateCompare;
        }
    }
    return false;
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
ItemStatus User::operator[](size_t libraryId) const {
    for (int i = 0; i < items.getSize(); ++i) {
        if (items[i].libraryId == libraryId) {
            return items[i].status;
        }
    }

    return ItemStatus::NOT_BORROWED;
}

User &User::operator+=(const size_t libraryId) {
    size_t i = 0;
    if (borrowedCount >= 5) {
        std::cout << "Reached maxed borrowed books" << std::endl;
        return *this;
    }

    for (; i < items.getSize(); ++i) {
        if (items[i].libraryId != libraryId) {
            continue;
        }
        if (items[i].status == ItemStatus::BORROWED
            || items[i].status == ItemStatus::REREAD) {
            borrowedCount++;
            std::cout << "Item is already borrowed" << std::endl;
            return *this;
        }

        if (items[i].status == ItemStatus::READ) {
            borrowedCount++;
            items[i].status = ItemStatus::REREAD;
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
        if (items[i].libraryId != libraryId) {
            continue;
        }
        if (items[i].status == ItemStatus::BORROWED
            || items[i].status == ItemStatus::REREAD) {
            items[i].status = ItemStatus::READ;
            borrowedCount--;
            return *this;
        }
        if (items[i].status == ItemStatus::READ) {
            std::cout << "Item is already returned" << std::endl;
            return *this;
        }
    }

    std::cout << "Item is not borrowed" << std::endl;
    return *this;
}

User &operator-(const User &lvs, size_t libraryId) {
    User result(lvs);
    result -= libraryId;
    return result;
}

// Private

void User::copy(const User &other) {
    name = other.name;
    for (int i = 0; i < other.items.getSize(); ++i) {
        ItemStatus _status = other.items[i].status;
        size_t _libraryId = other.items[i].libraryId;
        MinDate _borrowDate = other.items[i].borrowDate;
        MinDate _dueDate = other.items[i].dueDate;
        items.pushBack({_status,
                        _libraryId,
                        _borrowDate,
                        _dueDate});
    }
}

const MinVector<size_t> &User::getOverDueIds(const MinDate &dateCompare) {
    MinVector<size_t> overDueIds;
    for (int i = 0; i < items.getSize(); ++i) {
        if (items[i].status == ItemStatus::BORROWED
            || items[i].status == ItemStatus::REREAD) {
            return items[i].dueDate < dateCompare;
        }
    }
    return overDueIds;
}
