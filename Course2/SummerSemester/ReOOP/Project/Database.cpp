//
// Created by Sybatron on 6/15/2023.
//
#include <vector>
#include <string>
#include "Database.h"

Database::Database() = default;

Database::~Database() = default;

bool Database::hasUser(const std::string &username) {
    for (size_t i = 0; i < users.size(); ++i) {
        if (users[i] == username) {
            return true;
        }
    }
    return false;
}

bool Database::didLogin(const std::string &username, const std::string &password) {
    for (size_t i = 0; i < users.size(); ++i) {
        if (users[i] != username) {
            continue;
        }

        if (users[i].getPassword() == password) {
            return true;
        }
        return false;

    }
    return false;
}

void Database::addUser(User &user) {
    users.push_back(user);
}
