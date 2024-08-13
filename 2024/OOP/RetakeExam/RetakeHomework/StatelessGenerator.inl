//
// Created by Sybatron on 7/20/2024.
//

#include "StatelessGenerator.h"

template<typename T>
T StatelessGenerator<T>::get() {
    return generator();
}

template<typename T>
StatelessGenerator<T>::StatelessGenerator(StatelessGenerator::LambdaGenerator lambda):generator(lambda) {}

template<typename T>
StatelessGenerator<T>::StatelessGenerator(const StatelessGenerator<T> &other) {
    copy(other);
}

template<typename T>
StatelessGenerator<T> &StatelessGenerator<T>::operator=(const StatelessGenerator<T> &other) {
    if (this != &other) {
        copy(other);
    }
}

template<typename T>
Generator<T> *StatelessGenerator<T>::clone() {
    return new StatelessGenerator<T>(*this);
}

template<typename T>
bool StatelessGenerator<T>::hasNext() {
    return true;
}

template<typename T>
bool StatelessGenerator<T>::reset() {
    return true;
}

template<typename T>
void StatelessGenerator<T>::copy(const StatelessGenerator<T> &other) {
    generator = other.generator;
}

