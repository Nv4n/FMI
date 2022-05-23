//
// Created by Sybatron on 5/23/2022.
//

#ifndef FMI_VECTOR_H
#define FMI_VECTOR_H

template<typename Type=int>
class Vector {
private:
    size_t capacity{16};
    Type *storage{new Type[capacity]};
    size_t size{};
public:
    Vector() = default;

    Vector(const Vector &other);

    Vector &operator=(const Vector &other);

    virtual ~Vector();

    void pushBack(Type item);

    void popBack(Type item);

    void clear();

private:
    void resize();

    void destroy();

    void copy(const Vector &other);
};

#include "vector.inl"

#endif //FMI_VECTOR_H
