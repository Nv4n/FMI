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

unsigned short User::getReadCount() const {
    return readCount;
}


MinVector<size_t> &User::getOverDueIds(const MinDate &dateCompare) {
    MinVector<size_t> overDueIds;
    for (size_t i = 0; i < items.getSize(); ++i) {
        if (!(items[i].status == ItemStatus::BORROWED
              || items[i].status == ItemStatus::REREAD)) {
            continue;
        }
        if (items[i].dueDate < dateCompare) {
            overDueIds.pushBack(items[i].libraryId);
        }
    }
    return overDueIds;
}


bool User::isOverDue(size_t libraryId, const MinDate &dateCompare) {
    for (size_t i = 0; i < items.getSize(); ++i) {
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
    return lvs.readCount > rvs.readCount;
}

bool operator>=(const User &lvs, const User &rvs) {
    return !(lvs < rvs);
}

bool operator<(const User &lvs, const User &rvs) {
    return lvs.readCount < rvs.readCount;
}

bool operator<=(const User &lvs, const User &rvs) {
    return !(lvs > rvs);
}

/**
 *
 * @param index
 * @return User's book status
 */
ItemStatus User::operator[](size_t libraryId) const {
    if (borrowedCount == 0) {
        return ItemStatus::NOT_BORROWED;
    }
    for (size_t i = 0; i < items.getSize(); ++i) {
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
            MinDate currDate;
            MinDate dueDate;
            dueDate.advanceMonth();
            items[i].borrowDate = currDate;
            items[i].dueDate = dueDate;
            return *this;
        }
    }

    borrowedCount++;
    MinDate currDate;
    MinDate dueDate = currDate;
    dueDate.advanceMonth();
    UserItem item = {ItemStatus::BORROWED, libraryId, currDate, dueDate};
    items.pushBack(item);
    return *this;
}

User &operator+(const User &lvs, const size_t libraryId) {
    User result(lvs);
    result += libraryId;
    return result;
}

User &User::operator-=(size_t libraryId) {
    for (size_t i = 0; i < items.getSize(); ++i) {
        if (items[i].libraryId != libraryId) {
            continue;
        }
        if (items[i].status == ItemStatus::BORROWED
            || items[i].status == ItemStatus::REREAD) {

            if (items[i].status == ItemStatus::BORROWED) {
                readCount++;
            }
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
    borrowedCount = other.borrowedCount;
    readCount = other.borrowedCount;
    for (size_t i = 0; i < other.items.getSize(); ++i) {
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

std::ostream &operator<<(std::ostream &os, const User &user) {
    os << user.name << '\n';
    os << user.borrowedCount << '\n';
    os << user.readCount << '\n';
    os << user.items.getSize() << '\n';
    for (size_t i = 0; i < user.items.getSize(); ++i) {
        os << static_cast<int>(user.items[i].status) << '\n';
        os << user.items[i].libraryId << '\n';
        os << user.items[i].borrowDate << '\n';
        os << user.items[i].dueDate << '\n';
    }
    return os;
}

std::istream &operator>>(std::istream &is, User &user) {
    if (is.eof()) {
        return is;
    }
    char endline;
    is >> user.name >> endline;
    is >> user.borrowedCount >> endline;
    is >> user.readCount >> endline;
    size_t size;
    is >> size >> endline;
    user.items.erase();
    for (size_t i = 0; i < size; ++i) {
        int status;
        size_t libraryId;
        MinDate borrowDate;
        MinDate dueDate;
        is >> status >> endline;
        is >> libraryId >> endline;
        is >> borrowDate >> endline;
        is >> dueDate >> endline;
        ItemStatus itemStatus = static_cast<ItemStatus>(status);

        user.items.pushBack({itemStatus, libraryId, borrowDate, dueDate});
    }
    return is;
}

