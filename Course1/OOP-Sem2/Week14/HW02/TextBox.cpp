//
// Created by Sybatron on 6/5/2022.
//

#include "TextBox.h"

TextBox::TextBox(const char *text, const size_t positionX, const size_t positionY, const size_t width,
                 const size_t height) {
    setControlId();
    setPosition(positionX, positionY);

    setSize(width, height);

    size_t size = std::strlen(text);
    description = new char[size + 1];
    size_t rowsCount;

    for (int i = 0; i < size; ++i) {
        if (text[i] == '|') {
            description[i] = '\n';
        } else {
            description[i] = text[i];
        }
    }

    size_t textSize = 0;
    if (this->size.width * this->size.height > size) {
        textSize = size;
    } else {
        textSize = this->size.width * this->size.height;
    }
    this->text = new char[textSize] + 1;
    for (int i = 0, j = 0, widthIndex = 0, heightIndex = 0;
         i < size | heightIndex < this->size.height; ++i, ++j, ++widthIndex) {

        if (widthIndex == this->size.width || description[i] == '\n') {
            widthIndex = 0;
            heightIndex++;
            this->text[j] = '\n';

            while (description[i] != '|') {
                i++;
            }
        } else {
            this->text[j] = description[i];
        }
    }
}

Control *TextBox::clone() const {
    return new TextBox(*this);
}

Control *TextBox::input() {
    char text[256];
    std::cin.ignore();
    std::cin.getline(text, 255);

    size_t positionX;
    std::cin >> positionX;
    size_t positionY;
    std::cin >> positionY;
    size_t width;
    std::cin >> width;
    size_t height;
    std::cin >> height;
    return new TextBox(text, positionX, positionY, width, height);
}

const char *TextBox::print() {
    char *output = new char[size.width * size.height + 1 + 2];
    output[0] = '[';
    for (int i = 1, j = 0; j < size.width; ++i, ++j) {
        output[i] = text[j];
    }

    size_t rowsCount = 0;
    for (int i = 0; i < size.width; ++i) {
        if (text[i] == '\n') {
            rowsCount++;
        }
    }
    
    return nullptr;
}
