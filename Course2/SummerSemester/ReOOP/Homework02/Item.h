//
// Created by Sybatron on 5/26/2023.
//

#ifndef HW02_LIBRARY_ITEM_H
#define HW02_LIBRARY_ITEM_H

#include "MinString.h"

#pragma once
enum class ItemType {
    UNKNOWN = -1,
    BOOK,
    PERIODIC_PUBLICATION,
    COMIC,
};

class Item {
protected:
    MinString title;
    MinString shortDescr;
    size_t libraryID{};
    unsigned short publishYear{};
    ItemType type{};

public:
    Item();

    virtual ~Item();

    Item(const Item &other);

    Item &operator=(const Item &other);

    Item(Item &&other) noexcept;

    Item &operator=(Item &&other) noexcept;

    size_t getLibraryId() const;

    ItemType getType() const;

    const char *getTypeText() const;

    const MinString &getTitle() const;

    const MinString &getShortDescr() const;

    unsigned short getPublishYear() const;

    friend std::ostream &operator<<(std::ostream &os, const Item &item);

protected:
    virtual void copy(const Item &other);

    virtual void move(Item &other);
};


#endif //HW02_LIBRARY_ITEM_H
