//
// Created by Sybatron on 6/15/2023.
//
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

size_t Database::didLogin(const std::string &username, const std::string &password) {
    for (size_t i = 0; i < users.size(); ++i) {
        if (users[i] != username) {
            continue;
        }

        if (users[i].getPassword() == password) {
            return users[i].getUid();
        }
        return 0;

    }
    return 0;
}

void Database::addUser(User &user) {
    users.push_back(user);
}
