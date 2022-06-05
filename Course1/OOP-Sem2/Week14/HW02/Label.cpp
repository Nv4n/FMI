//
// Created by Sybatron on 6/5/2022.
//

#include <cstring>
#include "Label.h"

Label::Label(const char *text, const size_t positionX, const size_t positionY) {
    setControlId();
    setPosition(positionX, positionY);

    size_t size = std::strlen(text);
    description = new char[size + 1];
    this->text = new char[size + 1];
    std::strcpy(description, text);
    std::strcpy(this->text, description);

    setSize(size, 1);
}
