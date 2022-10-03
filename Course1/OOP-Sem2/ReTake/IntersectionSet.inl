//
// Created by Sybatron on 8/6/2022.
//

#include "IntersectionSet.h"

template<typename T>
IntersectionSet<T>::IntersectionSet(const Set<T> *left, const Set<T> *right) {

}

template<typename T>
IntersectionSet<T>::IntersectionSet(const IntersectionSet<T> &other) {
    copy(other);
}

template<typename T>
IntersectionSet<T> &IntersectionSet<T>::operator=(const IntersectionSet<T> &other) {
    if (this != &other) {
        destroy();
        copy(other);
    }

    return *this;
}

template<typename T>
IntersectionSet<T>::~IntersectionSet() {
    destroy();
}

template<typename T>
void IntersectionSet<T>::copy(const IntersectionSet<T> &other) {

}

template<typename T>
void IntersectionSet<T>::destroy() {
    if (data != nullptr) {
        delete[] data;
    }
}

template<typename T>
bool IntersectionSet<T>::doesContains(const T &element) {
    for (int i = 0; i < size; ++i) {
        if (data[i] == element) {
            return true;
        }
    }

    if (predicate != nullptr) {
        return predicate(element);
    }

    return false;
}
