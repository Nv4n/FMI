//
// Created by Sybatron on 7/20/2024.
//

#include "StatelessGenerator.h"

template<typename T>
T StatelessGenerator<T>::operator()() {
    return generator();
}

template<typename T>
StatelessGenerator<T>::StatelessGenerator(StatelessGenerator::LambdaGenerator lambda):generator(lambda) {}

template<typename T>
StatelessGenerator<T>::StatelessGenerator(const StatelessGenerator<T> &statelessGen) {
    generator = statelessGen.generator;
}

template<typename T>
Generator<T> *StatelessGenerator<T>::clone() {
    return StatelessGenerator<T>(this);
}

template<typename T>
bool StatelessGenerator<T>::hasNext() {
    return true;
}