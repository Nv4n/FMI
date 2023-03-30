//
// Created by Sybatron on 3/28/2023.
//

#ifndef WEEK05_OOPCOIN_HOMEWORK01_USEROBJ_H
#define WEEK05_OOPCOIN_HOMEWORK01_USEROBJ_H
#pragma once

class UserObj {
private:
    static unsigned Id;
    struct User {
        unsigned id;
        char name[128];
    } user;
public:
    UserObj(const char name[128], const double levs);
};

unsigned UserObj::Id = 1;

#endif //WEEK05_OOPCOIN_HOMEWORK01_USEROBJ_H
