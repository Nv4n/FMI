//
// Created by Sybatron on 5/10/2023.
//

#ifndef WEEK05_OOPCOIN_HOMEWORK01_USER_H
#define WEEK05_OOPCOIN_HOMEWORK01_USER_H

#pragma once

class User {
//    Всеки потребител се характеризира с:
//    ● собствено име;
//    ●фамилно име;
//    ●потребителско име (уникално за системата);
//    ●парола;
//    ●уникален идентификатор (неотрицателно число), който се генерира при създаването на потребителския акаунт;
//    ●точки.
private:
    std::string fname;
    std::string lname;
    std::string username;
    std::string password;
    const static std::size_t id;
    unsigned int points;
public:
    User(const std::string &fname, const std::string &lname, const std::string &username, const std::string &password,
         size_t id, unsigned int points);

    virtual ~User();

    const std::string &getFName() const;

    void setFName(const std::string &fname);

    const std::string &LName() const;

    void setLName(const std::string &lname);

    const std::string &getUsername() const;

    void setUsername(const std::string &username);

    const std::string &getPassword() const;

    void setPassword(const std::string &password);

    size_t getId() const;

    void setId(size_t id);

    unsigned int getPoints() const;

    void setPoints(unsigned int points);
};


#endif //WEEK05_OOPCOIN_HOMEWORK01_USER_H
