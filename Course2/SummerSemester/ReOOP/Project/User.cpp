//
// Created by Sybatron on 5/10/2023.
//

#include <string>
#include "User.h"

Set<size_t> User::modIds = Set<size_t>();
size_t User::userId = 1;

User::User(const std::string &fname, const std::string &lname, const std::string &username,
           const std::string &password) {
    setFName(fname);
    setLName(lname);
    setUsername(username);
    setPassword(password);
    setPoints(0);
    uid = userId++;

    if (uid == 1) {
        modIds.insert(uid);
    }
}

User::~User() = default;

const std::string &User::getFName() const {
    return fname;
}

void User::setFName(const std::string &_fname) {
    fname = _fname;
}

const std::string &User::LName() const {
    return lname;
}

void User::setLName(const std::string &_lname) {
    lname = _lname;
}

const std::string &User::getUsername() const {
    return username;
}

void User::setUsername(const std::string &_username) {
    username = _username;
}

const std::string &User::getPassword() const {
    return password;
}

void User::setPassword(const std::string &_password) {
    password = _password;
}

size_t User::getUid() const {
    return uid;
}

unsigned int User::getPoints() const {
    return points;
}

void User::setPoints(unsigned int _points) {
    points = _points;
}

bool User::operator==(const User &rvs) const {
    return username == rvs.username;
}

bool User::operator!=(const User &rvs) const {
    return !(*this == rvs);
}

bool User::operator==(const std::string &rvs) const {
    return username == rvs;
}

bool User::operator!=(const std::string &rvs) const {
    return !(*this == rvs);
}
