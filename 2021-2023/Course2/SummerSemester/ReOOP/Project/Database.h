//
// Created by Sybatron on 6/15/2023.
//

#ifndef PROJECT_SOCIALMEDIA_DATABASE_H
#define PROJECT_SOCIALMEDIA_DATABASE_H


#pragma once

#include <string>
#include <vector>
#include "User.h"
#include "Question.h"

class Database {
private:
    std::vector<User> users;
    std::vector<Question> questions;
public:
    Database();

    virtual ~Database();

    bool hasUser(const std::string &username);

    size_t didLogin(const std::string &username, const std::string &password);

    void addUser(User &user);
};


#endif //PROJECT_SOCIALMEDIA_DATABASE_H
