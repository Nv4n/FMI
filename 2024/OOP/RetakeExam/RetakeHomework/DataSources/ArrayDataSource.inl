//
// Created by Sybatron on 7/21/2024.
//
template<typename T>
ArrayDataSource<T>::ArrayDataSource(const T *arr, size_t arrSize) {
    currentIndex = 0;
    size = arrSize;
    length = arrSize;
    data = new T[arrSize];
    for (size_t i = 0; i < length; ++i) {
        data[i] = arr[i];
    }
}

template<typename T>
ArrayDataSource<T>::~ArrayDataSource() {
    destroy();
}


template<typename T>
ArrayDataSource<T>::ArrayDataSource(const ArrayDataSource<T> &other) {
    copy(other);
}

template<typename T>
ArrayDataSource<T> &ArrayDataSource<T>::operator=(const ArrayDataSource<T> &other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

/**
 *
 * @tparam T
 * @throws runtime_error when there are no more elements
 * @return T element
 */
template<typename T>
T ArrayDataSource<T>::get() {
    if (currentIndex >= length) {
        throw std::runtime_error("No next element");
    }

    T returnData = data[currentIndex];
    currentIndex++;
    return returnData;
}

/**
 * @tparam T
 * @param count how many items you want
 * @throws runtime_error when there are no more elements
 * @return T* array
 */
template<typename T>
T *ArrayDataSource<T>::get(size_t count) {
    if (currentIndex >= length) {
        throw std::runtime_error("No next element");
    }
    size_t returnLength = length - currentIndex;
    if (length - currentIndex >= count) {
        returnLength = count;
    }
    T *elements = new T[returnLength];
    for (size_t countdown = returnLength; countdown > 0; --countdown) {
        elements[currentIndex] = get();
    }
    return elements;
}

template<typename T>
bool ArrayDataSource<T>::hasNext() {
    return currentIndex < length;
}

template<typename T>
bool ArrayDataSource<T>::reset() {
    currentIndex = 0;
    return true;
}

/**
 *
 * @tparam T
 * @throws runtime_error when there are no more elements
 * @return T element
 */
template<typename T>
T ArrayDataSource<T>::operator()() {
    return get();
}

/**
 *
 * @tparam T
 * @throws runtime_error when there are no more elements
 * @return T element
 */
template<typename T>
DataSource<T> &ArrayDataSource<T>::operator>>(T &output) {
    output = get();
    return *this;
}

template<typename T>
ArrayDataSource<T>::operator bool() const {
    return hasNext();
}

template<typename T>
DataSource<T> *ArrayDataSource<T>::clone() {
    return new ArrayDataSource<T>(*this);
}


template<typename T>
ArrayDataSource<T> &ArrayDataSource<T>::operator--() {
    if (currentIndex > 0) {
        currentIndex--;
    }
    return *this;
}

template<typename T>
ArrayDataSource<T> ArrayDataSource<T>::operator--(int) {
    ArrayDataSource<T> old = *this;
    operator--();
    return old;
}


template<typename T>
ArrayDataSource<T> &ArrayDataSource<T>::operator+=(T element) {
    if (length >= size) {
        resize();
    }
    data[length] = element;
    length++;
    return *this;
}

template<typename T>
ArrayDataSource<T> ArrayDataSource<T>::operator+(T element) {
    ArrayDataSource<T> temp = *this;
    temp += element;
    return temp;
}


template<typename T>
void ArrayDataSource<T>::resize() {
    size *= 2;
    T *tempData = new T[size];
    for (size_t i = 0; i < length; ++i) {
        tempData[i] = data[i];
    }
    delete[] data;
    data = tempData;
}

template<typename T>
void ArrayDataSource<T>::copy(const ArrayDataSource<T> &other) {
    currentIndex = other.currentIndex;
    length = other.length;
    size = other.size;
    data = new T[size];
    for (size_t i = 0; i < length; ++i) {
        data[i] = other.data[i];
    }
}

template<typename T>
void ArrayDataSource<T>::destroy() {
    delete[] data;
}