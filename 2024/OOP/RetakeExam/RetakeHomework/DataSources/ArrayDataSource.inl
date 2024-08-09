//
// Created by Sybatron on 7/21/2024.
//

template<typename T>
T ArrayDataSource<T>::get() {
    return nullptr;
}

template<typename T>
T *ArrayDataSource<T>::get(size_t count) {
    return nullptr;
}

template<typename T>
bool ArrayDataSource<T>::hasNext() {
    return false;
}

template<typename T>
bool ArrayDataSource<T>::reset() {
    return false;
}

template<typename T>
T ArrayDataSource<T>::operator()() {
    return nullptr;
}

template<typename T>
DataSource <T> &ArrayDataSource<T>::operator>>(T &output) {
    output = get();
    return *this;
}

template<typename T>
ArrayDataSource<T>::operator bool() const {
    return false;
}

template<typename T>
DataSource <T> *ArrayDataSource<T>::clone() {
    return nullptr;
}