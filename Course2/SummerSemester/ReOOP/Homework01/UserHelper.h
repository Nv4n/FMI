//
// Created by Sybatron on 3/28/2023.
//

#ifndef WEEK05_OOPCOIN_HOMEWORK01_USERHELPER_H
#define WEEK05_OOPCOIN_HOMEWORK01_USERHELPER_H


#pragma once

class UserHelper {
private:
    static unsigned UserId;

public:
    struct User {
        unsigned id;
        char name[128];
    };

    static void createUser(const char name[128], double levs);

    static void removeUser(const char name[128]);

    static void calibrateId();

    static bool hasReceiverSender(unsigned receiver, unsigned sender);

private:
    UserHelper() {};

    static unsigned getNextId();

};


#endif //WEEK05_OOPCOIN_HOMEWORK01_USERHELPER_H
