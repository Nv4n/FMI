//
// Created by Sybatron on 5/26/2023.
//

#ifndef HW02_LIBRARY_USER_H
#define HW02_LIBRARY_USER_H


#include "MinString.h"
#include "Item.h"
#include "MinVector.h"

class User {
private:
    MinString name;
    MinVector<Item *> books;
public:
    User();

    ~User();

    const MinString &getName() const;
};


#endif //HW02_LIBRARY_USER_H
