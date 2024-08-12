//
// Created by Sybatron on 7/20/2024.
//

template<typename T>
GeneratorDataSource<T>::GeneratorDataSource(Generator<T> *gen) {
    generator = gen->clone();
}


template<typename T>
GeneratorDataSource<T>::~GeneratorDataSource() {
    destroy();
}

template<typename T>
GeneratorDataSource<T>::GeneratorDataSource(const GeneratorDataSource<T> &other) {
    copy(other);
}

template<typename T>
GeneratorDataSource<T> &GeneratorDataSource<T>::operator=(const GeneratorDataSource<T> &other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}


template<typename T>
T GeneratorDataSource<T>::get() {
    T result = generator->get();
    return result;
}

template<typename T>
T *GeneratorDataSource<T>::get(size_t count) {
    T *elements = new T[count];
    for (size_t i = 0; i < count; ++i) {
        elements[i] = get();
    }
    return elements;
}

template<typename T>
bool GeneratorDataSource<T>::hasNext() {
    return generator->hasNext();
}

template<typename T>
bool GeneratorDataSource<T>::reset() {
    return generator->reset();
}

template<typename T>
T GeneratorDataSource<T>::operator()() {
    return get();
}

template<typename T>
DataSource<T> &GeneratorDataSource<T>::operator>>(T &output) {
    output = get();
    return *this;
}

template<typename T>
GeneratorDataSource<T>::operator bool() const {
    return generator->hasNext();
}

template<typename T>
DataSource<T> *GeneratorDataSource<T>::clone() {
    return new GeneratorDataSource<T>(generator);
}


template<typename T>
void GeneratorDataSource<T>::destroy() {
    delete generator;
}

template<typename T>
void GeneratorDataSource<T>::copy(const GeneratorDataSource<T> &other) {
    generator = other.generator->clone();
}
