//
// Created by Sybatron on 6/5/2022.
//

#include "ListBox.h"

ListBox::ListBox(const char *text, const size_t positionX, const size_t positionY, const size_t optionIndex) {
    setControlId();
    setPosition(positionX, positionY);

    size_t size = std::strlen(text);
    description = new char[size + 1];
    size_t optionCount = 1;
    for (int i = 0; i < size; ++i) {
        if (text[i] == '|') {
            description[i] = text[i];
        }
    }

    text = new char[size + 1];
}
