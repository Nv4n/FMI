//
// Created by Sybatron on 8/27/2024.
//

#ifndef ETABLES_UTILITY_H
#define ETABLES_UTILITY_H
#pragma once

template<typename T, typename U>
struct is_same {
public:
    static const bool value = false;

    explicit operator bool() const {
        return value;
    }
};

template<typename T>
struct is_same<T, T> {
    static const bool value = true;

    explicit operator bool() const {
        return value;
    }
};

#endif //ETABLES_UTILITY_H
