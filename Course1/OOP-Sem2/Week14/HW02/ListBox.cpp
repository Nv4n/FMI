//
// Created by Sybatron on 6/5/2022.
//

#include "ListBox.h"

ListBox::ListBox(const char *text, const size_t positionX, const size_t positionY, const size_t optionIndex) {
    setControlId();
    setPosition(positionX, positionY);

    size_t size = std::strlen(text);
    description = new char[size + 1];
    this->text = new char[size + 1];

    size_t optionCount = 1;
    size_t longestOption = 0;
    for (int i = 0, currentLongest = 0; i < size; ++i, ++currentLongest) {
        if (text[i] == '|') {
            optionCount++;
            this->text[i] = '\n';
            description[i] = '\n';

            if (longestOption < currentLongest) {
                longestOption = currentLongest;
            }
            currentLongest = 0;
        } else {
            description[i] = text[i];
            this->text[i] = text[i];
        }
    }

    setSize(longestOption, optionCount);
}

Control *ListBox::clone() const {
    return new ListBox(*this);
}

Control *ListBox::input() {
    return nullptr;
}
