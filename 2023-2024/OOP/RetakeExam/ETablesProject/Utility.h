//
// Created by Sybatron on 8/27/2024.
//

#ifndef ETABLES_UTILITY_H
#define ETABLES_UTILITY_H
#pragma once

/**
 * @brief A utility struct to check if two types are the same.
 *
 * @tparam T The first type.
 * @tparam U The second type.
 */
template<typename T, typename U>
struct is_same {
public:
    static const bool value = false;

    /**
     *
     * @return False if T and U are different types
     */
    explicit operator bool() const {
        return value;
    }
};

/**
 * @brief A specialization of "is_same" for the case where T and U are the same type.
 *
 * @tparam T The type (same for both parameters).
 *
 */
template<typename T>
struct is_same<T, T> {
    static const bool value = true;

    /**
     *
     * @return True if T and U are different types
     */
    explicit operator bool() const {
        return value;
    }
};

#endif //ETABLES_UTILITY_H
