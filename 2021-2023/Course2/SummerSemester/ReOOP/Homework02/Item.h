//
// Created by Sybatron on 5/26/2023.
//

#ifndef HW02_LIBRARY_ITEM_H
#define HW02_LIBRARY_ITEM_H

#include "MinString.h"

#pragma once
enum class ItemType {
    BOOK,
    PERIODIC_PUBLICATION,
    COMIC,
    COUNT
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

    Item(const MinString &_title, const MinString &_shortDescr, size_t _libraryId, unsigned short _publishYear
    );

    virtual ~Item();

    Item(const Item &other);

    Item &operator=(const Item &other);

    virtual Item *clone() const = 0;

    size_t getLibraryId() const;

    ItemType getType() const;

    const char *getTypeText() const;

    const MinString &getTitle() const;

    const MinString &getShortDescr() const;

    unsigned short getPublishYear() const;

    void setTitle(const MinString &_title);

    void setShortDescr(const MinString &_shortDescr);

    void setLibraryId(size_t libraryId);

    void setPublishYear(unsigned short _publishYear);

    friend std::ostream &operator<<(std::ostream &os, const Item *&item);


protected:
    virtual void copy(const Item &other);

    virtual std::ostream &out(std::ostream &) const = 0;
};


#endif //HW02_LIBRARY_ITEM_H
