//
// Created by Sybatron on 5/23/2022.
//

#ifndef FMI_VECTOR_H
#define FMI_VECTOR_H

template<typename Type=int>
class IStack {
private:
    size_t capacity{16};
    Type *storage{new Type[capacity]};
    size_t size{};
public:
    IStack() = default;

    IStack(const IStack &other);

    IStack &operator=(const IStack &other);

    virtual ~IStack();

    void pushBack(Type item);

    void popBack(Type item);

    void clear();

private:
    void resize();

    void destroy();

    void copy(const IStack &other);
};

#include "vector.inl"

#endif //FMI_VECTOR_H
