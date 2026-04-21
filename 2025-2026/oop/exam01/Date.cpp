//
// Created by Sybatron on 4/21/2026.
//

#include "Date.h"

#include <cstring>

Date::Date(unsigned day, unsigned month, unsigned year) {
    SetDay(day);
    SetMonth(month);
    SetYear(year);
}

Date::Date(const char *date) {
    const char *copy = date;
    SetDay(ParseDate(copy));
    copy++;
    SetMonth(ParseDate(copy));
    copy++;
    SetYear(ParseDate(copy));

    if (*copy != '\0') {
        throw std::invalid_argument("Invalid date format");
    }

    if (std::strlen(date) != 10) {
        throw std::invalid_argument("Invalid date format");
    }
}

Date::Date(const Date &other) {
    bitDate = other.bitDate;
}

Date &Date::operator=(const Date &other) {
    if (this != &other) {
        bitDate = other.bitDate;
    }
    return *this;
}

void Date::Print(std::ostream &os) const {
    unsigned day = GetDay();
    unsigned month = GetMonth();
    if (day < 10) {
        os << "0" << day;
    } else {
        os << day;
    }
    os << "/";
    if (month < 10) {
        os << "0" << month;
    } else {
        os << month;
    }
    os << "/" << GetYear();
}

void Date::SetDay(unsigned day) {
    if (day < 1 || day > 31) {
        throw std::invalid_argument("Invalid day");
    }
    uint16_t dayMask = (1u << 5) - 1;
    dayMask = ~(dayMask << 10);
    bitDate &= dayMask;
    day <<= 10;
    bitDate |= day;
}

void Date::SetMonth(unsigned month) {
    if (month < 1 || month > 12) {
        throw std::invalid_argument("Invalid month");
    }
    uint16_t monthMask = (1u << 4) - 1;
    monthMask = ~(monthMask << 6);
    bitDate &= monthMask;
    month <<= 6;
    bitDate |= month;
}

void Date::SetYear(unsigned year) {
    if (year < 1970 || year > 2033) {
        throw std::invalid_argument("Invalid year");
    }
    uint16_t yearMask = ~((1u << 6) - 1);
    bitDate &= yearMask;
    year -= 1970;
    bitDate |= year;
}

unsigned Date::GetDay() const {
    unsigned bits = bitDate;
    bits >>= 10;
    return bits;
}

unsigned Date::GetMonth() const {
    uint16_t bits = bitDate;
    uint16_t monthMask = ((1u << 4) - 1) << 6;

    bits &= monthMask;
    bits >>= 6;
    return bits;
}

unsigned Date::GetYear() const {
    uint16_t bits = bitDate;
    uint16_t yearMask = (1u << 6) - 1;

    bits &= yearMask;
    unsigned year = bits + 1970;
    return year;
}

unsigned Date::ParseDate(const char *&date) {
    unsigned val = 0;
    while (*date != '/' && *date != '\0') {
        if (*date < '0' || *date > '9') {
            throw std::invalid_argument("Invalid date");
        }
        val = val * 10 + *date - '0';
        ++date;
    }
    return val;
}
