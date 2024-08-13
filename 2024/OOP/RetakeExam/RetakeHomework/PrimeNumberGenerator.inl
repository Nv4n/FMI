//
// Created by Sybatron on 8/12/2024.
//

/**
 *
 * @tparam T
 * @throws logic_error if you don't use one of the preferred number types
 */
template<typename T>
PrimeNumberGenerator<T>::PrimeNumberGenerator() {
    currentNumber = 2;
    size = 8;
    length = 0;
    if (!isNumber()) {
        throw std::logic_error(
                "The chosen type is not the same as the list of preferred number types.\nCheck isNumber() method to find the list of all preferred number types");
    }
    prevPrimeNums = new T[size];
}

template<typename T>
PrimeNumberGenerator<T>::~PrimeNumberGenerator() {
    destroy();
}

template<typename T>
PrimeNumberGenerator<T>::PrimeNumberGenerator(const PrimeNumberGenerator<T> &other) {
    copy(other);
}

template<typename T>
PrimeNumberGenerator<T> &PrimeNumberGenerator<T>::operator=(const PrimeNumberGenerator<T> &other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

template<typename T>
T PrimeNumberGenerator<T>::get() {
    if (length == size) {
        resize();
    }
    T returnElement;
    bool dividableByPrime;
    while (true) {
        dividableByPrime = false;

        for (size_t i = 0; i < length; ++i) {
            if (currentNumber == prevPrimeNums[i]) {
                returnElement = currentNumber;
                currentNumber++;
                return returnElement;
            }
            if (currentNumber % prevPrimeNums[i] == 0) {
                dividableByPrime = true;
                currentNumber++;
                break;
            }
        }
        if (dividableByPrime) {
            continue;
        }
        break;
    }
    returnElement = currentNumber;
    prevPrimeNums[length] = currentNumber;
    length++;
    currentNumber++;
    return returnElement;
}

template<typename T>
bool PrimeNumberGenerator<T>::hasNext() {
    return true;
}

template<typename T>
Generator<T> *PrimeNumberGenerator<T>::clone() {
    return new PrimeNumberGenerator<T>(*this);
}

template<typename T>
bool PrimeNumberGenerator<T>::reset() {
    currentNumber = 2;
    return true;
}

template<typename T>
void PrimeNumberGenerator<T>::copy(const PrimeNumberGenerator<T> &other) {
    size = other.size;
    length = other.length;
    currentNumber = other.currentNumber;
    prevPrimeNums = new T[size];
    for (size_t i = 0; i < length; ++i) {
        prevPrimeNums[i] = other.prevPrimeNums[i];
    }
}

template<typename T>
void PrimeNumberGenerator<T>::destroy() {
    delete[] prevPrimeNums;
}

template<typename T>
void PrimeNumberGenerator<T>::resize() {
    size *= 2;
    T *temp = new T[size];
    for (size_t i = 0; i < length; ++i) {
        temp[i] = prevPrimeNums[i];
    }
    delete[]prevPrimeNums;
    prevPrimeNums = temp;
}

template<typename T>
bool PrimeNumberGenerator<T>::isNumber() {
    if (is_same<T, int>::value ||
        is_same<T, long>::value ||
        is_same<T, short>::value ||
        is_same<T, unsigned int>::value ||
        is_same<T, unsigned long>::value ||
        is_same<T, unsigned short>::value ||
        is_same<T, long long>::value ||
        is_same<T, unsigned long long>::value ||
        is_same<T, char>::value ||
        is_same<T, unsigned char>::value) {
        return true;
    }
    return false;
}