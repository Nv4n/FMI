//
// Created by Sybatron on 8/26/2024.
//

#ifndef OOP_OPTIONAL_H
#define OOP_OPTIONAL_H

#pragma once

/**
 * @brief Custom Optional class that maybe saves T value
 * or is empty
 *
 * @tparam T The type of the saved value
 */
template<typename T>
class Optional {
private:
    bool hasVal{};
    union {
        T value;
    };
public:
    Optional();

    Optional(const Optional<T> &other);

    Optional<T> &operator=(const Optional<T> &other);

    Optional<T> &operator=(const T &val);

    virtual ~Optional();

    bool hasValue() const;

    explicit operator bool() const;

    T &getValue();

    const T &getValue() const;

    void reset();

private:
    void copy(const Optional<T> &other);

    void destroy();
};


#include "Optional.inl"

#endif //OOP_OPTIONAL_H
