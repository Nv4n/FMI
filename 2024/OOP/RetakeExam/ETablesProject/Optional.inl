//
// Created by Sybatron on 8/26/2024.
//


template<typename T>
Optional<T>::Optional():hasVal(false) {}

template<typename T>
Optional<T>::Optional(const Optional<T> &other) {
    copy(other);
}

template<typename T>
Optional<T> &Optional<T>::operator=(const Optional<T> &other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

/**
 *@brief Assignment operator= for changing the value of Optional
 *
 * @tparam T The type of Optional saved value
 * @param val The new value
 */
template<typename T>
Optional<T> &Optional<T>::operator=(const T &val) {
    if (hasVal) {
        destroy();
    }

    hasVal = true;
    new(&value) T(val);

    return *this;
}

template<typename T>
Optional<T>::~Optional() {
    destroy();
}

/**
 *
 * @return hasVal If the value is not empty
 */
template<typename T>
bool Optional<T>::hasValue() const {
    return hasVal;
}

template<typename T>
Optional<T>::operator bool() const {
    return hasValue();
}

/**
 *
 * @tparam T The type of the saved value
 * @return value saved value if exist
 * @throws logic_error When the value is empty
 */
template<typename T>
T &Optional<T>::getValue() {
    if (!hasVal) {
        throw std::logic_error("No value present");
    }
    return value;
}

/**
 *
 * @tparam T The type of the saved value
 * @return value saved value if exist
 * @throws logic_error When the value is empty
 */
template<typename T>
const T &Optional<T>::getValue() const {
    if (!hasVal) {
        throw std::logic_error("No value present");
    }
    return value;
}

template<typename T>
void Optional<T>::reset() {
    destroy();
    hasVal = false;
}

template<typename T>
void Optional<T>::copy(const Optional<T> &other) {
    hasVal = other.hasVal;
    new(&value) T(other.value);
}

template<typename T>
void Optional<T>::destroy() {
    if (hasVal) {
        value.~T();
    }
}

