//
// Created by Sybatron on 8/9/2024.
//
#include <fstream>
#include <stdexcept>

/**
 *
 * @tparam T
 * @param fileDir the directory of file
 * @throws invalid_argument When can't open the file
 */
template<typename T>
FileDataSource<T>::FileDataSource(const char *fileDir) {
    try {
        initFromFile(fileDir);
    } catch (std::invalid_argument &e) {
        destroy();
        throw e;
    }
}

/**
 *
 * @tparam T
 * @param fileDir
 */
template<typename T>
void FileDataSource<T>::initFromFile(const char *fileDir) {
    std::ifstream reader(fileDir);
    if (!reader.is_open()) {
        throw std::invalid_argument("Can't open the file");
    }
    size = 8;
    length = 0;
    currentIndex = 0;
    data = new T[size];
    while (!reader.eof()) {
        if (length >= size) {
            resize();
        }
        T element;
        reader >> element;
        data[length] = element;
        length++;
    }
}

template<typename T>
FileDataSource<T>::~FileDataSource() {
    destroy();
}

template<typename T>
FileDataSource<T>::FileDataSource(const FileDataSource<T> &other) {
    copy(other);
}

template<typename T>
FileDataSource<T> &FileDataSource<T>::operator=(const FileDataSource<T> &other) {
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
T FileDataSource<T>::get() {
    if (currentIndex >= length) {
        throw std::runtime_error("No next element");
    }

    T returnData = data[currentIndex];
    currentIndex++;
    return returnData;
}

/**
 *
 * @tparam T
 * @param count - how many items you want
 * @throws runtime_error when there are no more elements
 * @return T* array
 */
template<typename T>
T *FileDataSource<T>::get(size_t count) {
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
bool FileDataSource<T>::hasNext() {
    return currentIndex < length;
}

template<typename T>
bool FileDataSource<T>::reset() {
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
T FileDataSource<T>::operator()() {
    return get();
}

/**
 *
 * @tparam T
 * @throws runtime_error when there are no more elements
 * @return T element
 */
template<typename T>
DataSource<T> &FileDataSource<T>::operator>>(T &output) {
    output = get();
    return *this;
}

template<typename T>
FileDataSource<T>::operator bool() const {
    return hasNext();
}

template<typename T>
DataSource<T> *FileDataSource<T>::clone() {
    return new FileDataSource<T>(*this);
}

template<typename T>
void FileDataSource<T>::destroy() {
    delete[] data;
}

template<typename T>
void FileDataSource<T>::copy(const FileDataSource<T> &other) {
    currentIndex = other.currentIndex;
    length = other.length;
    size = other.size;
    data = new T[size];
    for (size_t i = 0; i < length; ++i) {
        data[i] = other.data[i];
    }
}

template<typename T>
void FileDataSource<T>::resize() {
    size *= 2;
    T *tempData = new T[size];
    for (size_t i = 0; i < length; ++i) {
        tempData[i] = data[i];
    }
    delete[] data;
    data = tempData;
}

