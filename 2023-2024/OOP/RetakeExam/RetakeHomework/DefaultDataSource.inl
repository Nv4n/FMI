//
// Created by Sybatron on 7/19/2024.
//


template<typename T>
T DefaultDataSource<T>::get() {
    T element;
    return element;
}

template<typename T>
T *DefaultDataSource<T>::get(size_t count) {
    T *elements = new T[count];
    for (size_t i = 0; i < count; ++i) {
        T defaultElement;
        elements[i] = defaultElement;
    }
    return elements;
}


template<typename T>
bool DefaultDataSource<T>::hasNext() {
    return true;
}

template<typename T>
bool DefaultDataSource<T>::reset() {
    return true;
}

template<typename T>
T DefaultDataSource<T>::operator()() {
    return get();
}

template<typename T>
DataSource<T> &DefaultDataSource<T>::operator>>(T &output) {
    output = get();
    return *this;
}

template<typename T>
DefaultDataSource<T>::operator bool() {
    return true;
}

template<typename T>
DataSource<T> *DefaultDataSource<T>::clone() {
    return new DefaultDataSource<T>();
}
