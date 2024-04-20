//
// Created by Sybatron on 4/15/2024.
//

#include "2.h"

ModifiableIntegerFunction::ModifiableIntegerFunction(INTEGER_FUNCTION &func) {
    this->func = func;
    length = 0;
    capacity = 8;
    changedVals = new ChangedValueRes[capacity];
}

ModifiableIntegerFunction::ModifiableIntegerFunction(const ModifiableIntegerFunction &other) {
    copy(other);
}

ModifiableIntegerFunction &ModifiableIntegerFunction::operator=(const ModifiableIntegerFunction &other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

ModifiableIntegerFunction::~ModifiableIntegerFunction() {
    destroy();
}

/**
 *
 * @param input
 * @throws out_of_range value is excluded
 * @return
 */
int16_t ModifiableIntegerFunction::apply(int16_t input) const {
    for (int i = 0; i < length; ++i) {
        if (changedVals[i].inputValue != input) {
            continue;
        }
        if (changedVals[i].isExcluded) {
            throw std::out_of_range("Function is not defined for this input");
        }
        return changedVals[i].outputValue;
    }
    return func(input);
}

void ModifiableIntegerFunction::specifyResult(int16_t input, int16_t result) {
    for (int i = 0; i < length; ++i) {
        if (changedVals[i].inputValue != input) {
            continue;
        }
        changedVals[i].outputValue = result;
        changedVals[i].isExcluded = false;
        return;
    }
    if (length >= capacity) {
        resize();
    }
    changedVals[length].inputValue = input;
    changedVals[length].outputValue = result;
    changedVals[length].isExcluded = false;
    length++;
}

void ModifiableIntegerFunction::excludeInput(int16_t input) {
    for (int i = 0; i < length; ++i) {
        if (changedVals[i].inputValue != input) {
            continue;
        }
        changedVals[i].isExcluded = true;
        return;
    }
    if (length >= capacity) {
        resize();
    }
    changedVals[length].inputValue = input;
    changedVals[length].isExcluded = true;
    length++;
}

ModifiableIntegerFunction ModifiableIntegerFunction::operator^(unsigned int power) {
    ModifiableIntegerFunction result(*this);
    INTEGER_FUNCTION savedFunc = func;
    result.func = [power, savedFunc](int16_t x) -> int16_t {
        int16_t res = x;
        for (int i = 0; i < power; ++i) {
            res = savedFunc(res);
        }
        return res;
    };
    return result;
}

//TODO  add specific values from other in + and - and compose
ModifiableIntegerFunction ModifiableIntegerFunction::operator+(const ModifiableIntegerFunction &other) {
    ModifiableIntegerFunction result(*this);
    INTEGER_FUNCTION savedThisFunc = func;
    INTEGER_FUNCTION savedOtherFunc = other.func;
    result.func = [savedThisFunc, savedOtherFunc](int16_t x) -> int16_t {
        return static_cast<int16_t>(savedThisFunc(x) + savedOtherFunc(x));
    };
    for (int i = 0; i < length; ++i) {

    }
    return result;
}

ModifiableIntegerFunction ModifiableIntegerFunction::operator-(const ModifiableIntegerFunction &other) {
    ModifiableIntegerFunction result(*this);
    INTEGER_FUNCTION savedThisFunc = func;
    INTEGER_FUNCTION savedOtherFunc = other.func;
    result.func = [savedThisFunc, savedOtherFunc](int16_t x) -> int16_t {
        return static_cast<int16_t>(savedThisFunc(x) - savedOtherFunc(x));
    };
    return result;
}

ModifiableIntegerFunction ModifiableIntegerFunction::compose(const ModifiableIntegerFunction &other) {
    ModifiableIntegerFunction result(*this);
    INTEGER_FUNCTION savedThisFunc = func;
    INTEGER_FUNCTION savedOtherFunc = other.func;
    result.func = [savedThisFunc, savedOtherFunc](int16_t x) -> int16_t {
        return savedThisFunc(savedOtherFunc(x));
    };
    return result;
}

/**
 *
 * @param fileName
 * @throws runtime_error file not opened
 * @throws runtime_error cannot serialize func
 */
void ModifiableIntegerFunction::serialize(const char *fileName) {
    std::ofstream writer(fileName, std::ios::binary);
    if (!writer.is_open()) {
        throw std::runtime_error("File couldn't be opened for serialization");
    }
    writer.write(reinterpret_cast<const char *>(capacity), sizeof(capacity));
    writer.write(reinterpret_cast<const char *>(length), sizeof(length));
    writer.write(reinterpret_cast<const char *>(changedVals), length * sizeof(ChangedValueRes));
    int16_t (**ptr)(int16_t) = func.target<int16_t (*)(int16_t)>();
    if (ptr) {
        writer.write(reinterpret_cast<const char *>(&(*ptr)), sizeof(ptr));
    } else {
        throw std::runtime_error("Cannot serialize the function");
    }
}

/**
 *
 * @param fileName
 * @throws runtime_error cannot open file
 */
void ModifiableIntegerFunction::deserialize(const char *fileName) {
    std::ifstream reader(fileName, std::ios::binary);
    if (!reader.is_open()) {
        throw std::runtime_error("File couldn't be opened for deserialization");
    }
    reader.read(reinterpret_cast< char *>(capacity), sizeof(capacity));
    reader.read(reinterpret_cast< char *>(length), sizeof(length));
    reader.read(reinterpret_cast< char *>(changedVals), length * sizeof(ChangedValueRes));
    int16_t (*ptr)(int16_t);

    reader.read(reinterpret_cast< char *>(&ptr), sizeof(ptr));
    func = ptr;
}

/**
 *
 * @return
 * @throws invalid_argument not invertible func
 * @throws runtime_error function is not defined
 */
ModifiableIntegerFunction ModifiableIntegerFunction::inverse() {
    if (length > 0) {
        throw std::invalid_argument("Function is not invertible");
        // If some point is changed or excluded then the functions is not defined there
    }

    INTEGER_FUNCTION function = [](int16_t x) -> int16_t {
        throw std::runtime_error("Function is not defined");
    };
    ModifiableIntegerFunction result(function);
    for (int16_t i = INT16_MIN; i <= INT16_MAX; ++i) {
        result.specifyResult(func(i), i);
    }
    return result;
}

bool ModifiableIntegerFunction::operator>(const ModifiableIntegerFunction &other) const {
    for (int16_t x = INT16_MIN; x <= INT16_MAX; ++x) {
        bool isExcluded = false;
        int16_t currY;
        bool otherIsExcluded = false;
        int16_t otherCurrY;
        try {
            currY = apply(x);
        }
        catch (std::out_of_range &e) {
            isExcluded = true;
        } catch (...) {
            return false;
        }

        try {
            otherCurrY = other.apply(x);
        }
        catch (std::out_of_range &e) {
            otherIsExcluded = true;
        } catch (...) {
            return true;
        }
        if (isExcluded && !otherIsExcluded) {
            return false;
        }
        if (!isExcluded && otherIsExcluded) {
            return true;
        }
        if (isExcluded && otherIsExcluded) {
            continue;
        }
        if (currY < otherCurrY) {
            return false;
        }
    }
    return true;
}

bool ModifiableIntegerFunction::operator<(const ModifiableIntegerFunction &other) const {
    for (int16_t x = INT16_MIN; x <= INT16_MAX; ++x) {
        bool isExcluded = false;
        int16_t currY;
        bool otherIsExcluded = false;
        int16_t otherCurrY;
        try {
            currY = apply(x);
        }
        catch (std::out_of_range &e) {
            isExcluded = true;
        } catch (...) {
            return false;
        }

        try {
            otherCurrY = other.apply(x);
        }
        catch (std::out_of_range &e) {
            otherIsExcluded = true;
        } catch (...) {
            return true;
        }

        if (isExcluded && !otherIsExcluded) {
            return true;
        }
        if (!isExcluded && otherIsExcluded) {
            return false;
        }
        if (isExcluded && otherIsExcluded) {
            continue;
        }
        if (currY > otherCurrY) {
            return false;
        }
    }

    return true;
}

bool ModifiableIntegerFunction::operator==(const ModifiableIntegerFunction &other) const {
    if (length != other.length) {
        return false;
    }
    for (int16_t x = INT16_MIN; x <= INT16_MAX; ++x) {
        bool isExcluded = false;
        int16_t currY;
        bool otherIsExcluded = false;
        int16_t otherCurrY;
        try {
            currY = apply(x);
        }
        catch (std::out_of_range &e) {
            isExcluded = true;
        } catch (...) {
            return false;
        }

        try {
            otherCurrY = other.apply(x);
        }
        catch (std::out_of_range &e) {
            otherIsExcluded = true;
        } catch (...) {
            return false;
        }

        if (isExcluded != otherIsExcluded) {
            return false;
        }
        if (currY != otherCurrY) {
            return false;
        }
    }

    return true;
}

bool ModifiableIntegerFunction::operator<=(const ModifiableIntegerFunction &other) const {
    return !(*this > other);
}

bool ModifiableIntegerFunction::operator>=(const ModifiableIntegerFunction &other) const {
    return !(*this < other);
}


bool ModifiableIntegerFunction::operator!=(const ModifiableIntegerFunction &other) const {
    return !(*this == other);
}

/**
 *
 * @param fromX
 * @param toX
 * @param fromY
 * @param toY
 * @throws invalid_argument either X or Y range is not 20
 */
void ModifiableIntegerFunction::plot(int16_t fromX, int16_t toX, int16_t fromY, int16_t toY) {
    if (toX - fromX != 20 || toY - fromY != 20) {
        throw std::invalid_argument("Either axis range is not 20");
    }
    size_t matrixSide = 21;
    char **plotMatrix = new char *[matrixSide];
    for (int row = 0; row < matrixSide; ++row) {
        plotMatrix[row] = new char[matrixSide];
    }
    for (int row = 0; row < matrixSide; ++row) {
        plotMatrix[row][0] = '|';
    }
    for (int col = 0; col < matrixSide; ++col) {
        plotMatrix[matrixSide - 1][col] = '_';
    }

    int16_t prevY = fromY;
    for (int16_t x = fromX, col = 1; x < toY && col < matrixSide; ++x, ++col) {
        int16_t currY;
        bool isExcluded = false;
        try {
            currY = apply(x);
        } catch (std::out_of_range &e) {
            isExcluded = true;
            currY = prevY;

        } catch (...) {
            isExcluded = true;
            currY = prevY;
        }

        prevY = currY;
        if (currY > toY) {
            if (isExcluded) {
                plotMatrix[0][col] = 'o';
                continue;
            }
            plotMatrix[0][col] = '^';
        } else if (currY < fromY) {
            if (isExcluded) {
                plotMatrix[matrixSide - 2][col] = 'o';
                continue;
            }
            plotMatrix[matrixSide - 2][col] = '.';
        } else {
            int16_t rowIndex = currY - fromY;
            if (isExcluded) {
                plotMatrix[rowIndex][col] = 'o';
                continue;
            }
            plotMatrix[rowIndex][col] = '*';
        }
    }

    for (int row = 0; row < matrixSide; ++row) {
        delete[] plotMatrix[row];
    }
    delete[]plotMatrix;
}

bool ModifiableIntegerFunction::isInjection() {
    size_t size = INT16_MAX - INT16_MIN + 1;
    int16_t *yValues = new int16_t[size];
    for (size_t i = 0; i < length; ++i) {
        if (changedVals[i].isExcluded) {
            delete[]yValues;
            return false;
        }
    }

    for (int16_t x = INT16_MIN; x <= INT16_MAX; ++x) {
        try {
            int16_t currY = apply(x);
            size_t yIndex = currY - INT16_MIN;
            if (yValues[yIndex] > 0) {
                delete[]yValues;
                return false;
            }
            yValues[yIndex]++;
        } catch (...) {
            delete[]yValues;
            return false;
        }
    }
    delete[]yValues;
    return true;
}

bool ModifiableIntegerFunction::isSurjection() {
    size_t size = INT16_MAX - INT16_MIN + 1;
    int16_t *yValues = new int16_t[size];
    for (size_t i = 0; i < length; ++i) {
        if (changedVals[i].isExcluded) {
            delete[]yValues;
            return false;
        }
    }

    for (int16_t x = INT16_MIN; x <= INT16_MAX; ++x) {
        try {
            int16_t currY = apply(x);
            size_t yIndex = currY - INT16_MIN;
            yValues[yIndex]++;
        } catch (...) {
            delete[]yValues;
            return false;
        }
    }

    for (int16_t y = INT16_MIN; y <= INT16_MAX; ++y) {
        size_t yIndex = y - INT16_MIN;
        if (yValues[y] == 0) {
            delete[]yValues;
            return false;
        }
    }
    delete[]yValues;
    return true;
}

bool ModifiableIntegerFunction::isBijection() {
    return isInjection() && isSurjection();
}


bool ModifiableIntegerFunction::isParallel(const ModifiableIntegerFunction &other) const {
    int distance;
    bool isCalculatedOnce = false;
    for (int16_t x = INT16_MIN; x <= INT16_MAX; ++x) {
        bool isExcluded = false;
        int16_t currY;
        bool otherIsExcluded = false;
        int16_t otherCurrY;
        try {
            currY = apply(x);
        }
        catch (std::out_of_range &e) {
            isExcluded = true;
        } catch (...) {
            return false;
        }

        try {
            otherCurrY = other.apply(x);
        }
        catch (std::out_of_range &e) {
            otherIsExcluded = true;
        } catch (...) {
            return true;
        }
        if (isExcluded && !otherIsExcluded ||
            !isExcluded && otherIsExcluded) {
            return false;
        }
        if (isExcluded && otherIsExcluded) {
            continue;
        }
        if (!isCalculatedOnce) {
            distance = currY - otherCurrY;
            isCalculatedOnce = true;
            continue;
        }

        int currDistance = currY - otherCurrY;
        if (currDistance != distance) {
            return false;
        }
    }
    return true;
}

void ModifiableIntegerFunction::destroy() {
    delete[]changedVals;
}

void ModifiableIntegerFunction::copy(const ModifiableIntegerFunction &other) {
    func = other.func;
    length = other.length;
    capacity = other.capacity;
    changedVals = new ChangedValueRes[capacity];
    for (size_t i = 0; i < length; ++i) {
        changedVals[i].inputValue = other.changedVals[i].inputValue;
        changedVals[i].outputValue = other.changedVals[i].outputValue;
        changedVals[i].isExcluded = other.changedVals[i].isExcluded;
    }
}

void ModifiableIntegerFunction::resize() {
    capacity *= 2;
    ChangedValueRes *temp = new ChangedValueRes[capacity];
    for (int i = 0; i < length; ++i) {
        temp[i].inputValue = changedVals[i].inputValue;
        temp[i].outputValue = changedVals[i].outputValue;
        temp[i].isExcluded = changedVals[i].isExcluded;
    }
    delete[] changedVals;
    changedVals = temp;
}





//`void ModifiableIntegerFunction::insert(int16_t input, int16_t value, bool isExcluded, size_t index) {
//    if (length >= capacity) {
//        return;
//    }
//    for (size_t i = length; i > index; --i) {
//        changedVals[i].inputValue = changedVals[i - 1].inputValue;
//        changedVals[i].outputValue = changedVals[i - 1].outputValue;
//        changedVals[i].isExcluded = changedVals[i - 1].isExcluded;
//    }
//    changedVals[index].inputValue = input;
//    changedVals[index].outputValue = value;
//    changedVals[index].isExcluded = isExcluded;
//}`





