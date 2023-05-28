//
// Created by Sybatron on 5/25/2023.
//

#ifndef HW02_LIBRARY_MINSTRING_H
#define HW02_LIBRARY_MINSTRING_H

#pragma once

class MinString {
private:
    char *data{};
    size_t length{};
    size_t size{};

public:
    MinString();

    MinString(const char *_data);

    ~MinString();

    MinString(MinString &&other) noexcept;

    MinString &operator=(MinString &&other) noexcept;

    MinString(const MinString &other);

    MinString &operator=(const char *_data);

    MinString &operator=(const MinString &other);

    size_t getLength() const;

    MinString &operator+=(const MinString &other);

    friend MinString &operator+(const MinString &lvs, const MinString &rvs);

    MinString &operator+=(const char *&_data);

    friend MinString &operator+(const MinString &lvs, const char *&_data);

    friend std::ostream &operator<<(std::ostream &os, const MinString &str);

    friend std::istream &operator>>(std::istream &is, MinString &str);

    friend bool operator==(const MinString &lvs, const MinString &rvs);

    friend bool operator!=(const MinString &lvs, const MinString &rvs);

    friend bool operator>(const MinString &lvs, const MinString &rvs);

    friend bool operator>=(const MinString &lvs, const MinString &rvs);

    friend bool operator<(const MinString &lvs, const MinString &rvs);

    friend bool operator<=(const MinString &lvs, const MinString &rvs);

    char operator[](size_t index);

    void erase();

private:
    void copy(const MinString &other);

    void copy(const char *_data);

    void move(MinString &other) noexcept;

    void scaleUp(size_t minLength = 0);

    void destroy();
};


#endif //HW02_LIBRARY_MINSTRING_H
