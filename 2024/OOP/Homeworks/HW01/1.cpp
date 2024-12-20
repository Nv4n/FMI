//
// Created by Sybatron on 4/15/2024.
//

#include "1.h"

MultiSet::MultiSet(unsigned int maxNumber, unsigned char frequencyBits) :
        maxNumber(maxNumber) {
    if (frequencyBits < 1 || frequencyBits > 8) {
        throw std::invalid_argument("FrequencyBits are out of range (1<=fb<=8)");
    }
    maxBits = frequencyBits;
    maxFrequency = 2;
    for (int i = 0; i < maxBits - 1; ++i) {
        maxFrequency *= 2;
    }
    maxFrequency -= 1;
    length = 0;
    capacity = 8;
    data = new DataFrequency[capacity];
}

MultiSet::~MultiSet() {
    destroy();
}


MultiSet::MultiSet(const MultiSet &other) {
    copy(other);
}

MultiSet &MultiSet::operator=(const MultiSet &other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

void MultiSet::destroy() {
    delete[] data;
    data = nullptr;
}

void MultiSet::copy(const MultiSet &other) {
    maxFrequency = other.maxFrequency;
    maxBits = other.maxBits;
    maxNumber = other.maxNumber;

    capacity = other.capacity;
    length = other.length;
    data = new DataFrequency[capacity];
    for (size_t i = 0; i < length; ++i) {
        data[i].number = other.data[i].number;
        data[i].frequency = other.data[i].frequency;
    }
}

std::ifstream &operator>>(std::ifstream &reader, MultiSet &set) {
    reader.read(reinterpret_cast<char *>(&set.maxNumber), sizeof(unsigned int));
    reader.read(reinterpret_cast< char *>(&set.maxBits), sizeof(unsigned char));
    reader.read(reinterpret_cast<char *>(&set.maxFrequency), sizeof(unsigned char));
    reader.read(reinterpret_cast<char *>(&set.capacity), sizeof(size_t));
    reader.read(reinterpret_cast<char *>(&set.length), sizeof(size_t));
    delete[] set.data;
    set.data = new MultiSet::DataFrequency[set.capacity];
    reader.read(reinterpret_cast<char *>(&set.data), sizeof(MultiSet::DataFrequency) * set.length);
    return reader;
}

std::ofstream &operator<<(std::ofstream &writer, const MultiSet &set) {
    writer.write(reinterpret_cast<const char *>(&set.maxNumber), sizeof(unsigned int));
    writer.write(reinterpret_cast<const char *>(&set.maxBits), sizeof(unsigned char));
    writer.write(reinterpret_cast<const char *>(&set.maxFrequency), sizeof(unsigned char));
    writer.write(reinterpret_cast<const char *>(&set.capacity), sizeof(size_t));
    writer.write(reinterpret_cast<const char *>(&set.length), sizeof(size_t));
    writer.write(reinterpret_cast<const char *>(&set.data), sizeof(MultiSet::DataFrequency) * set.length);

    return writer;
}

void MultiSet::add(unsigned int number) {
    add(number, 1);
}

void MultiSet::add(unsigned int number, unsigned char frequency) {
    if (number > maxNumber) {
        throw std::invalid_argument("The number is over the max value");
    }
    if (length >= capacity) {
        resize();
    }
    if (length == 0) {
        insertNumber(number, frequency, 0);
        length++;
        return;
    }
    if (frequency > maxFrequency) {
        throw std::out_of_range("This value is entered too many times");
    }
    size_t i = 0;
    for (; i < length; ++i) {
        if (data[i].number > number) {
            insertNumber(number, frequency, i);
            length++;
            return;
        }
        if (data[i].number != number) {
            continue;
        }

        if (data[i].frequency + frequency > maxFrequency) {
            throw std::out_of_range("This value was entered too many times");
        }
        data[i].frequency += frequency;
        return;
    }
    insertNumber(number, frequency, length);
    length++;
}


void MultiSet::insertNumber(unsigned int number, unsigned char frequency, size_t index) {
    if (length >= capacity) {
        return;
    }
    for (size_t i = length; i > index; --i) {
        data[i].number = data[i - 1].number;
        data[i].frequency = data[i - 1].frequency;
    }
    data[index].number = number;
    data[index].frequency = frequency;
}

unsigned char MultiSet::frequencyOf(unsigned int number) {
    for (size_t i = 0; i < length; ++i) {
        if (data[i].number == number) {
            return data[i].frequency;
        }
    }
    return 0;
}

void MultiSet::printMemoryRepresentation() {
    const unsigned char *rawData = reinterpret_cast<const unsigned char *>(this);
    const size_t dataSize = sizeof(MultiSet);
    std::cout << "Memory representation" << std::endl;
    for (size_t i = 0; i < dataSize; ++i) {
        std::cout << std::hex << static_cast<unsigned int>(rawData[i]) << " ";
    }
    std::cout << std::dec;
    std::cout << std::endl;
}

void MultiSet::printAllNumbers() {
    std::cout << "MultiSet: {" << std::endl;
    for (int i = 0; i < length; ++i) {
        std::cout << "Number: " << data[i].number << ", Frequency: " << (int) data[i].frequency
                  << std::endl;
    }
    std::cout << "}" << std::endl;
}

MultiSet MultiSet::intersect(const MultiSet &other) {
    MultiSet result(maxNumber, maxBits);
    for (size_t i = 0, j = 0; i < length; ++i) {
        for (; j < other.length; ++j) {
            if (data[i].number < other.data[j].number) {
                break;
            }
            if (data[i].number != other.data[j].number) {
                continue;
            }
            if (data[i].frequency > other.data[j].frequency) {
                result.add(data[i].number, other.data[j].frequency);
            } else {
                result.add(data[i].number, data[i].frequency);
            }
        }
    }

    return result;
}

MultiSet MultiSet::except(const MultiSet &other) {
    maxNumber = this->maxNumber > other.maxNumber
                ? this->maxNumber
                : other.maxNumber;
    maxBits = this->maxBits > other.maxBits
              ? this->maxBits
              : other.maxBits;
    MultiSet result(maxNumber, maxBits);
    for (size_t i = 0, j = 0; i < length; ++i) {
        bool isFound = false;
        for (; j < other.length; ++j) {
            if (data[i].number < other.data[j].number) {
                break;
            }
            if (data[i].number == other.data[j].number) {
                isFound = true;
                break;
            }
        }
        if (!isFound) {
            result.add(data[i].number, data[i].frequency);
        }
    }

    for (size_t i = 0, j = 0; i < other.length; ++i) {
        bool isFound = false;
        for (; j < length; ++j) {
            if (other.data[i].number < data[j].number) {
                break;
            }
            if (other.data[i].number == data[j].number) {
                isFound = true;
                break;
            }
        }
        if (!isFound) {
            result.add(other.data[i].number, other.data[i].frequency);
        }
    }

    return result;
}

MultiSet MultiSet::addition() {
    MultiSet result(*this);
    for (size_t i = 0; i < length; ++i) {
        result.data[i].frequency = maxFrequency - result.data[i].frequency;
    }
    return result;
}


MultiSet::MultiSet() {
    maxBits = 1;
    maxFrequency = 1;
    maxNumber = 0;
    length = 0;
    capacity = 1;
    data = new DataFrequency[capacity];
}


void MultiSet::resize() {
    capacity *= 2;
    DataFrequency *temp = new DataFrequency[capacity];
    for (size_t i = 0; i < length; ++i) {
        temp[i].number = data[i].number;
        temp[i].frequency = data[i].frequency;
    }
    delete[] data;
    data = temp;
}