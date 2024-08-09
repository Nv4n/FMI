//
// Created by Sybatron on 8/9/2024.
//
template<typename T>
FileDataSource<T>::FileDataSource(const char *filename) {

}

template<typename T>
FileDataSource<T>::~FileDataSource() {
    delete[] data;
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
 * @throws runtime_error where there are no more elements
 * @return T element
 */
template<typename T>
T FileDataSource<T>::get() {
    if (currentIndex >= length) {
        throw std::runtime_error("No next element");
    }

    return data[length++];
}
/**
 *
 * @tparam T
 * @param count - how many items you want
 * @throws runtime_error where there are no more elements
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
    T *elements = new T[0];
    for (int i = 0; i < ; ++i) {

    }
    return elements;
}

template<typename T>
bool FileDataSource<T>::hasNext() {
    return length < size;
}

template<typename T>
bool FileDataSource<T>::reset() {
    length = 0;
    return true;
}

template<typename T>
T FileDataSource<T>::operator()() {
    return get();
}

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
    return nullptr;
}


template<typename T>
void FileDataSource<T>::destroy() {

}

template<typename T>
void FileDataSource<T>::copy(const FileDataSource<T> &other) {

}

