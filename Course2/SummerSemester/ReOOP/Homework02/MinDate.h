//
// Created by Sybatron on 5/28/2023.
//

#ifndef HW02_LIBRARY_MINDATE_H
#define HW02_LIBRARY_MINDATE_H

#pragma once

class MinDate {
private:
    unsigned int year{};
    unsigned int month{};
    unsigned int day{};
public:
    MinDate(unsigned int _year = 1900, unsigned int _month = 1, unsigned int _day = 1);

    MinDate(const MinDate &other);

    MinDate &operator=(const MinDate &other);

    unsigned int getYear() const;

    unsigned int getMonth() const;

    unsigned int getDay() const;

    friend std::ostream &operator<<(std::ostream &os, const MinDate &date);

    friend std::istream &operator>>(std::istream &is, MinDate &date);

private:
    void setYear(unsigned int _year);

    void setMonth(unsigned int _month);

    void setDay(unsigned int _day);

    static bool isDigit(char symbol);

    void copy(const MinDate &other);
};


#endif //HW02_LIBRARY_MINDATE_H
