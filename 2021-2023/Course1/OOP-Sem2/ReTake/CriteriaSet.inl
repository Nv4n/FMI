//
// Created by Sybatron on 8/5/2022.
//

#include "CriteriaSet.h"


template<typename T>
CriteriaSet<T>::CriteriaSet(bool (*predicate)(const T &)) {
    this->type = SetType::CRITERIA;
    this->predicate = predicate;
}

template<typename T>
CriteriaSet<T>::CriteriaSet(const CriteriaSet<T> &other) {
    copy(other);
}

template<typename T>
CriteriaSet<T> &CriteriaSet<T>::operator=(const CriteriaSet<T> &other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

template<typename T>
CriteriaSet<T>::~CriteriaSet() {
    destroy();
}

template<typename T>
bool CriteriaSet<T>::doesContains(const T &element) {
    return predicate(element);
}

template<typename T>
void CriteriaSet<T>::copy(const CriteriaSet<T> other) {
    predicate = other.predicate;
    this->type = other.type;
}

template<typename T>
void CriteriaSet<T>::destroy() {
    if (predicate != nullptr) {
        delete[] predicate;
    }
}
