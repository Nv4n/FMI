//
// Created by Sybatron on 6/15/2023.
//

#ifndef HW02_LIBRARY_DATABASE_H
#define HW02_LIBRARY_DATABASE_H

#include "User.h"
#include "Question.h"

#pragma once

class Database {
private:
    std::vector<User> users;
    std::vector<Question> questions;
public:
    Database();

    virtual ~Database();

    bool hasUser(const std::string &username);

    bool didLogin(const std::string &username, const std::string &password);

    void addUser(User &user);
};


#endif //HW02_LIBRARY_DATABASE_H
