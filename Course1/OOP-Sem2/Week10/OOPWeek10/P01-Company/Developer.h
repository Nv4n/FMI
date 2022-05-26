#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "Employee.h"

#pragma once

class Developer : public Employee {
private:
    bool isCppKnown;
    bool isCsharpKnown;
public:
    Developer(const char *name, const unsigned int months, bool knowCPlusPlus, bool knowCSharp);

    Developer(const Developer &obj);

    Developer &operator=(const Developer &obj);

    Developer &operator=(Developer &&obj);

    ~Developer();


    void setCppKnown(bool isCppKnown);

    void setCsharpKnown(bool isCsharpKnown);

    bool getCppKnown();

    bool getCsharpKnown();

private:
    void copy(const Developer &other);
};

#endif // !DEVELOPER_H
