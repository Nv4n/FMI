//
// Created by Sybatron on 11/3/2022.
//

#ifndef WEEK05_STACK_STACK_H
#define WEEK05_STACK_STACK_H

template<class T>
class Stack {
private:
    struct Node {
        T data;
        Node *next;
    };

    Node *first;

private:
    void erase();

    void copy(const Stack &other);

public:
    Stack();

    Stack(const Stack &other);

    Stack &operator=(const Stack &other);

    virtual ~Stack();

    const T &pop();

    void push(const T &el);

    const T &peek();
};


#endif //WEEK05_STACK_STACK_H
