//
// Created by Sybatron on 5/25/2023.
//

#ifndef HW02_LIBRARY_MINSTRING_H
#define HW02_LIBRARY_MINSTRING_H


class MinString {
private:
    char *data;
    size_t length;
    size_t size;

public:
    MinString();

    MinString(const char *_data);
    
    MinString(const MinString &other);

    // Move constructor
    MinString(MinString &&other) noexcept: data(other.data), length(other.length) {
        other.data = nullptr;
        other.length = 0;
    }

    // Destructor
    ~MinString() {
        delete[] data;
    }

    // Assignment operator for const char*
    MinString &operator=(const char *data) {
        delete[] data;
        length = strlen(data);
        data = new char[length + 1];
        strcpy(data, data);
        return *this;
    }

    // Assignment operator for integers
    template<typename T>
    MinString &operator=(T value) {
        std::ostringstream oss;
        oss << value;
        return operator=(oss.str().c_str());
    }

    // Copy assignment operator
    MinString &operator=(const MinString &other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    // Move assignment operator
    MinString &operator=(MinString &&other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            length = other.length;
            other.data = nullptr;
            other.length = 0;
        }
        return *this;
    }

    // Concatenation operator (+)
    MinString operator+(const MinString &other) const {
        MinString result;
        result.length = length + other.length;
        result.data = new char[result.length + 1];
        strcpy(result.data, data);
        strcat(result.data, other.data);
        return result;
    }

    // Compound assignment operator (+=)
    MinString &operator+=(const MinString &other) {
        char *temp = new char[length + other.length + 1];
        strcpy(temp, data);
        strcat(temp, other.data);

        delete[] data;
        length += other.length;
        data = temp;

        return *this;
    }

    // Getter for the string length
    int length() const {
        return length;
    }

    const char *getData() const;

    friend std::ostream &operator<<(std::ostream &os, const MinString &str);

    friend std::istream &operator>>(std::istream &is, MinString &str);


    friend bool operator==(const MinString &lhs, const MinString &rhs);

private:

};


#endif //HW02_LIBRARY_MINSTRING_H
