//
// Created by Sybatron on 7/19/2024.
//

#ifndef OOPSTRUCTURES_DATASOURCE_H
#define OOPSTRUCTURES_DATASOURCE_H

#pragma once

#include <iostream>

template<typename T>
class DataSource {
private:
    size_t length{};
    size_t size{};
public:
    virtual ~DataSource() = default;

    /**
    * @tparam T
    * @throws runtime_error When there are no more elements.
     * That will happen with every source except Default
    * @return T element
    */
    virtual T get() = 0;

    /**
    * @tparam T
    * @throws runtime_error when there are no more elements
    * @return T element
    */
    virtual T *get(size_t count) = 0;

    virtual bool hasNext() = 0;

    virtual bool reset() = 0;

    /**
    * @tparam T
    * @throws runtime_error when there are no more elements
    * @return T element
    */
    virtual T operator()() = 0;

    /**
    * @tparam T
    * @throws runtime_error when there are no more elements
    * @return T element
    */
    virtual DataSource &operator>>(T &output) = 0;

    virtual explicit operator bool() = 0;

    virtual DataSource *clone() = 0;
};

#include "DataSource.inl"

#endif //OOPSTRUCTURES_DATASOURCE_H
