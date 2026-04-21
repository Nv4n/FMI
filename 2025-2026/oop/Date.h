
#ifndef DATE_H

#define DATE_H
#pragma once
#include <stdexcept>
#include <iostream>

class Date
{
private:
    /* data */
private:
    unsigned day = 0;
    unsigned month = 0;
    unsigned year = 0;

public:
    Date(unsigned day, unsigned month, unsigned year);
    ~Date();
    Date(const char *date);
    void Validate(unsigned day, unsigned month, unsigned year);
    int ParseInt(const char *num);

    unsigned GetDay() const { return day };
    unsigned GetMonth() const { return month };
    unsigned GetYear() const { return year };

    void Print(std::ostream &out) const;
};

#endif // DATE_H