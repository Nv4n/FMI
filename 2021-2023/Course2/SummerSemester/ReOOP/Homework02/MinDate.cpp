//
// Created by Sybatron on 5/28/2023.
//
#include <iostream>
#include <stdexcept>
#include <ctime>
#include "MinDate.h"
#include "MinString.h"

// Constructors
MinDate::MinDate() {
    std::time_t currentTime = std::time(nullptr);

    std::tm *localTime = std::localtime(&currentTime);

    unsigned int _day = localTime->tm_mday;
    unsigned int _month = localTime->tm_mon + 1;
    unsigned int _year = localTime->tm_year + 1900;

    setDay(_day);
    setMonth(_month);
    setYear(_year);
}

MinDate::MinDate(unsigned int _year, unsigned int _month, unsigned int _day) {
    setYear(_year);
    setMonth(_month);
    setDay(_day);
}

MinDate::MinDate(const MinDate &other) {
    copy(other);
}

MinDate &MinDate::operator=(const MinDate &other) {
    if (this != &other) {
        copy(other);
    }
    return *this;
}

// Getters and Setters
void MinDate::advanceMonth() {
    month = month == 12 ? 1 : month + 1;
}

unsigned int MinDate::getYear() const {
    return year;
}

unsigned int MinDate::getMonth() const {
    return month;
}

unsigned int MinDate::getDay() const {
    return day;
}

/**
 *
 * @param _year
 * @throw invalid_argument("Year can't be earlier than 1000-th")
 * @throw invalid_argument("Year can't be greater than 2024")
 */
void MinDate::setYear(unsigned int _year) {
    if (_year < 1900) {
        throw std::invalid_argument("Year can't be earlier than 1900-th");
    }
    if (_year > 2024) {
        throw std::invalid_argument("Year can't be greater than 2024");
    }
    year = _year;
}

/**
 *
 * @param _month
 * @throw invalid_argument("Invalid month")
 */
void MinDate::setMonth(unsigned int _month) {
    if (_month < 1 || _month > 12) {
        throw std::invalid_argument("Invalid month");
    }
    month = _month;
}

void MinDate::setDay(unsigned int _day) {
    if (_day < 1 || _day > 31) {
        throw std::invalid_argument("Invalid day");
    }
    day = _day;
}

// Read and Write
std::ostream &operator<<(std::ostream &os, const MinDate &date) {
    os << date.year << '-' << date.month << '-' << date.day;
    return os;
}

/**
 *
 * @param is
 * @param date
 * @return <b>istream &</b>
 * @throw invalid_argument("Invalid year format")
 */
std::istream &operator>>(std::istream &is, MinDate &date) {
    MinString input;
    is >> input;
    if (input.getLength() < 8 || input.getLength() > 10) {
        throw std::invalid_argument("Invalid year format");
    }
    unsigned int _year = 0;
    size_t globalIndex = 0;
    for (size_t i = 0; i < 4; ++i, ++globalIndex) {
        if (!MinDate::isDigit(input[globalIndex])) {
            throw std::invalid_argument("Invalid year format");
        }
        _year = _year * 10 + (input[globalIndex] - '0');
    }
    if (input[globalIndex] != '-') {
        throw std::invalid_argument("Invalid year format");
    }

    unsigned int _month = 0;
    for (size_t i = 0; i < 2; ++i, ++globalIndex) {
        if (i == 1 && input[globalIndex]) {
            break;
        }
        if (!MinDate::isDigit(input[globalIndex])) {
            throw std::invalid_argument("Invalid year format");
        }
        _month = _month * 10 + (input[globalIndex] - '0');
    }
    if (input[globalIndex] != '-') {
        throw std::invalid_argument("Invalid year format");
    }

    unsigned int _day = 0;
    for (size_t i = 0; i < 2; ++i, ++globalIndex) {
        if (i == 1 && input[globalIndex]) {
            break;
        }
        if (!MinDate::isDigit(input[globalIndex])) {
            throw std::invalid_argument("Invalid year format");
        }
        _day = _day * 10 + (input[globalIndex] - '0');
    }
    if (globalIndex != input.getLength()) {
        throw std::invalid_argument("Invalid year format");
    }

    date.setYear(_year);
    date.setMonth(_month);
    date.setDay(_day);
    return is;
}

// Comparators
bool operator==(const MinDate &lvs, const MinDate &rvs) {
    return lvs.year == rvs.year && lvs.month == rvs.month && lvs.day == rvs.day;
}

bool operator!=(const MinDate &lvs, const MinDate &rvs) {
    return !(lvs == rvs);
}

bool operator>(const MinDate &lvs, const MinDate &rvs) {
    return lvs.year > rvs.year && lvs.month > rvs.month && lvs.day > rvs.day;
}

bool operator>=(const MinDate &lvs, const MinDate &rvs) {
    return lvs > rvs && lvs == rvs;
}

bool operator<(const MinDate &lvs, const MinDate &rvs) {
    return !(lvs >= rvs);
}

bool operator<=(const MinDate &lvs, const MinDate &rvs) {
    return !(lvs > rvs);
}


// Private
bool MinDate::isDigit(char symbol) {
    return symbol >= '0' && symbol <= '9';
}

void MinDate::copy(const MinDate &other) {
    year = other.year;
    month = other.month;
    day = other.day;
}

