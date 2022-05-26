//
// Created by Sybatron on 5/26/2022.
//

#include "Queue.h"
template<typename T>
Queue<T>::~Queue(){
    delete[] storage;
}

template<typename T>
bool Queue<T>::empty() const{
    return size == 0;
};

template<typename T>
void Queue<T>::push(T element){
    if(size+1>=capacity){
        //resize();
    }

    storage[size]=element;
    size++;
}

template<typename T>
void Queue<T>::pop(){
    first++;
}

template<typename T>
T & Queue<T>::front(){
    return storage[first];
}

template<typename T>
T & Queue<T>::back(){
    return storage[size - 1];
}

void Queue<T>::resize();