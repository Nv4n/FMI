//
// Created by Sybatron on 5/10/2023.
//

#include <iostream>
#include <string>
#include "User.h"

User::User(const std::string &fname, const std::string &lname, const std::string &username, const std::string &password,
           size_t id, unsigned int points) : fname(fname), lname(lname), username(username), password(password), id(id),
                                             points(points) {

}

User::~User() {

}

const std::string &User::getFName() const {
    return fname;
}

void User::setFName(const std::string &fname) {
    User::fname = fname;
}

const std::string &User::LName() const {
    return lname;
}

void User::setLName(const std::string &lname) {
    User::lname = lname;
}

const std::string &User::getUsername() const {
    return username;
}

void User::setUsername(const std::string &username) {
    User::username = username;
}

const std::string &User::getPassword() const {
    return password;
}

void User::setPassword(const std::string &password) {
    User::password = password;
}

size_t User::getId() const {
    return id;
}

void User::setId(size_t id) {
    User::id = id;
}

unsigned int User::getPoints() const {
    return points;
}

void User::setPoints(unsigned int points) {
    User::points = points;
}


