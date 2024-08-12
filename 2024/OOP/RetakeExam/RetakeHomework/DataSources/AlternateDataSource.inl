//
// Created by Sybatron on 8/11/2024.
//
#include <stdexcept>

template<typename T>
AlternateDataSource<T>::AlternateDataSource(DataSource<T> **sources, size_t length) {
    size = length;
    currentIndex = 0;
    data = new DataSource<T> *[size];
    for (int i = 0; i < size; ++i) {
        data[i] = sources[i]->clone();
    }
}

template<typename T>
AlternateDataSource<T>::~AlternateDataSource() {
    destroy();
}

template<typename T>
AlternateDataSource<T>::AlternateDataSource(const AlternateDataSource<T> &other) {
    copy(other);
}

template<typename T>
AlternateDataSource<T> &AlternateDataSource<T>::operator=(const AlternateDataSource<T> &other) {
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
T AlternateDataSource<T>::get() {
    if (currentIndex >= size) {
        currentIndex = 0;
    }
    size_t startIndex = currentIndex;
    T returnElement;
    bool firstPass = true;
    while (true) {
        if (currentIndex == startIndex) {
            if (!firstPass) {
                throw std::runtime_error("No next element");
            }
            firstPass = false;
        }

        if (data[currentIndex]->hasNext()) {
            returnElement = data[currentIndex]->get();
            break;
        }

        currentIndex = (currentIndex + 1) % size;
    }
    currentIndex++;
    return returnElement;
}

/**
 *
 * @tparam T
 * @throws runtime_error when there are no more elements
 * @return T* array
 */
template<typename T>
T *AlternateDataSource<T>::get(size_t count) {
    if (!hasNext()) {
        throw std::runtime_error("No next element");
    }
    size_t length = 0;
    T *sequence = new T[count];
    for (size_t i = 0; i < count; ++i) {
        try {
            sequence[i] = get();
        } catch (std::runtime_error &e) {
            delete[] sequence;
            throw e;
        }
    }
    return sequence;
}

template<typename T>
bool AlternateDataSource<T>::hasNext() {
    for (size_t i = 0; i < size; ++i) {
        if (data[i]->hasNext()) {
            return true;
        }
    }
    return false;
}

template<typename T>
bool AlternateDataSource<T>::reset() {
    for (size_t i = 0; i < size; ++i) {
        bool resetResult = data[i]->reset();
        if (!resetResult) {
            return false;
        }
    }
    return true;
}

/**
 *
 * @tparam T
 * @throws runtime_error when there are no more elements
 * @return T element
 */
template<typename T>
T AlternateDataSource<T>::operator()() {
    return get();
}

/**
 *
 * @tparam T
 * @throws runtime_error when there are no more elements
 * @return DataSource<T>& (*this)
 */
template<typename T>
DataSource<T> &AlternateDataSource<T>::operator>>(T &output) {
    output = get();
    return *this;
}

template<typename T>
AlternateDataSource<T>::operator bool() {
    return hasNext();
}

template<typename T>
DataSource<T> *AlternateDataSource<T>::clone() {
    return new AlternateDataSource<T>(*this);
}

template<typename T>
void AlternateDataSource<T>::copy(const AlternateDataSource<T> &other) {
    size = other.size;
    currentIndex = other.currentIndex;
    data = new DataSource<T> *[size];
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i]->clone();
    }
}

template<typename T>
void AlternateDataSource<T>::destroy() {
    for (size_t i = 0; i < size; ++i) {
        delete data[i];
    }
    delete[] data;
}