//
// Created by Sybatron on 8/6/2022.
//

#include "SetReader.h"

template<typename T>
SetReader<T>::SetReader(std::ifstream &reader) {
    if (!reader.is_open()) {
        throw std::runtime_error("Unable to open file!");
    }

    char buffer[256];
    while (!reader.eof()) {
        reader.getline(buffer, sizeof(buffer));

        std::ifstream binaryReader(buffer, std::ios::binary);
        readSet(binaryReader);
    }
}

template<typename T>
SetReader<T>::~SetReader() {

}

template<typename T>
void SetReader<T>::readSet(std::ifstream &reader, const bool isItFirst) {
    if (!reader.is_open()) {
        throw std::runtime_error("Unable to open file!");
    }

    short numCount;
    reader.read(reinterpret_cast<char *>(numCount), sizeof(numCount));

    short operationType;
    reader.read(reinterpret_cast<char *>(operationType), sizeof(operationType));

    T *data = new T[numCount];
    for (int i = 0; i < numCount; ++i) {
        reader.read(reinterpret_cast<char *>(data[i]), sizeof(data[i]));
    }

    reader.close();

    calculateResult(data, operationType, numCount, isItFirst);
}

template<typename T>
void SetReader<T>::calculateResult(const T *data, const short operationType, const short numCount,
                                   const bool isItFirst) {
    switch (operationType) {
        case 0: {
            FiniteSet<T> set(data, numCount);
            break;
        }
        case 1: {
            auto func = [&numCount, &data](T n) {
                for (int i = 0; i < numCount; ++i) {
                    if (n % data[i] != 0) {
                        return false;
                    }
                }

                return true;
            };

            CriteriaSet<T> set(func);

            if (isItFirst) {
                resultSet = set;
            }
            break;
        }
        case 2: {
            auto func = [&numCount, &data](T n) {
                for (int i = 0; i < numCount; ++i) {
                    if (n % data[i] == 0) {
                        return true;
                    }
                }

                return false;
            };

            CriteriaSet<T> set(func);

            if (isItFirst) {
                resultSet = set;
            }
            break;
        }
        case 8: {
            FiniteSet<T> set(data, numCount);
            break;
        }
        case 9: {
            auto func = [&numCount, &data](T n) {
                for (int i = 0; i < numCount; ++i) {
                    if (n % data[i] != 0) {
                        return false;
                    }
                }
                return true;
            };

            CriteriaSet<T> set(func);

            if (isItFirst) {
                resultSet = set;
            }
            break;
        }
        case 10: {
            auto func = [&numCount, &data](T n) {
                for (int i = 0; i < numCount; ++i) {
                    if (n % data[i] == 0) {
                        return true;
                    }
                }

                return false;
            };

            CriteriaSet<T> set(func);

            if (isItFirst) {
                resultSet = set;
            }
            break;
        }
    }
}

template<typename T>
size_t SetReader<T>::getEqualElementsCount(const T *data, size_t size) {
    size_t count = 0;
    for (int i = 0; i < size; ++i) {
        if (resultSet->doesContains(data[i])) {
            count++;
        }
    }

    return count;
}