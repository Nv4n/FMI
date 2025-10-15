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
    MinDate();

    MinDate(unsigned int _year, unsigned int _month, unsigned int _day);

    MinDate(const MinDate &other);

    MinDate &operator=(const MinDate &other);

    unsigned int getYear() const;

    unsigned int getMonth() const;

    unsigned int getDay() const;

    void advanceMonth();

    friend std::ostream &operator<<(std::ostream &os, const MinDate &date);

    friend std::istream &operator>>(std::istream &is, MinDate &date);

    friend bool operator==(const MinDate &lvs, const MinDate &rvs);

    friend bool operator!=(const MinDate &lvs, const MinDate &rvs);

    friend bool operator>(const MinDate &lvs, const MinDate &rvs);

    friend bool operator>=(const MinDate &lvs, const MinDate &rvs);

    friend bool operator<(const MinDate &lvs, const MinDate &rvs);

    friend bool operator<=(const MinDate &lvs, const MinDate &rvs);


private:
    void setYear(unsigned int _year);

    void setMonth(unsigned int _month);

    void setDay(unsigned int _day);

    static bool isDigit(char symbol);

    void copy(const MinDate &other);
};


#endif //HW02_LIBRARY_MINDATE_H
