//
// Created by Sybatron on 4/21/2026.
//

#ifndef DATE_H
#define DATE_H

#include <cstdint>
#include <iostream>

class Date {
private:
    uint16_t bitDate = 0;

public:
    Date() = delete;

    Date(unsigned day, unsigned month, unsigned year);

    explicit Date(const char *date);

    Date(const Date &);

    Date &operator=(const Date &other);

    void Print(std::ostream &os) const;

    void SetDay(unsigned day);

    void SetMonth(unsigned month);

    void SetYear(unsigned year);

    [[nodiscard]] unsigned GetDay() const;

    [[nodiscard]] unsigned GetMonth() const;

    [[nodiscard]] unsigned GetYear() const;

private:
    unsigned ParseDate(const char *&date);
};


#endif //DATE_H
