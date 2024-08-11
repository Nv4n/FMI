//
// Created by Sybatron on 7/20/2024.
//

template<typename T>
GeneratorDataSource<T>::GeneratorDataSource(Generator<T> *gen) {
    generator = gen->clone();
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