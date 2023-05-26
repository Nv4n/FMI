//
// Created by Sybatron on 5/26/2023.
//

#ifndef HW02_LIBRARY_LIBRARY_H
#define HW02_LIBRARY_LIBRARY_H


#include <ostream>
#include "User.h"
#include "MinVector.h"
#include "Item.h"

class Library {
private:
    MinVector<User> users;
    MinVector<Item *> items;

    //TODO READ AND WRITE LIBRARY in binary format
public:
    void addItem(Item *&item);

    void removeItem(size_t libraryID);

    friend std::ostream &operator<<(std::ostream &os, const Library &library);

};


#endif //HW02_LIBRARY_LIBRARY_H
