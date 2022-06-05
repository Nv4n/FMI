//
// Created by Sybatron on 6/5/2022.
//

#include "RadioButton.h"

RadioButton::RadioButton(const char *text, const size_t positionX, const size_t positionY, size_t optionIndex) {
    controlId = Id++;
    position.x = positionX;
    position.y = positionY;
    size_t size = std::strlen(text);
    description = new char[size + 1];
    std::strcpy(description, text);

    size_t rowsCount = 1;
    for (int i = 0; i < size; ++i) {
        if (description[i] == '|') {
            rowsCount++;
        }
    }

    size_t index = 0;
    if (optionIndex < rowsCount) {
        index = optionIndex;
    }
    this->text[size + 4 * rowsCount + 1];

    bool isNewRow = true;
    for (int i = 0, j = 4, row = 0; i < size; ++i, ++j) {
        if (isNewRow) {
            this->text[j++] = '|';
            if (row == index) {
                this->text[j++] = 'X';
            } else {
                this->text[j++] = ' ';
            }
            this->text[j++] = '|';
            this->text[j++] = ' ';
            isNewRow = false;
        }

        if (description[i] == '|') {
            this->text[j] = '\n';
            row++;
            isNewRow = true;
        } else {
            this->text[j] = description[i];
        }
    }


    this->size.height = rowsCount;
    this->size.width = size + 4 * rowsCount;
}

Control *RadioButton::clone() const {
    return new RadioButton(*this);
}
