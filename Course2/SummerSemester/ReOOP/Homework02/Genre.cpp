//
// Created by Sybatron on 5/27/2023.
//
#include <fstream>
#include <stdexcept>
#include "Genre.h"

// Getters and Setters
Character Genre::getCharacter() const {
    return character;
}

void Genre::setCharacter(Character _character) {
    character = _character;
    combineGenre();
}

Type Genre::getType() const {
    return type;
}

void Genre::setType(Type _type) {
    type = _type;
    combineGenre();
}

Audience Genre::getAudience() const {
    return audience;
}

void Genre::setAudience(Audience _audience) {
    audience = _audience;
    combineGenre();
}

unsigned short Genre::getGenre() const {
    return genre;
}

/**
 * @param _genre
 * @throws invalid_argument When given invalid genre
 */
void Genre::setGenre(unsigned short _genre) {
    bool isEvenParity = isEvenBitCount(_genre);
    bool isValid = (isEvenParity && ((_genre >> 15) & 0x1) == 0)
                   || (!isEvenParity && ((_genre >> 15) & 0x1) == 1);

    if (!isValid) {
        throw std::invalid_argument("Invalid Genre");
    }
    character = static_cast<Character>(_genre & 0x7F);
    type = static_cast<Type>((_genre >> 7) & 0xF);
    audience = static_cast<Audience>((_genre >> 11) & 0xF);
    parity = isEvenParity;
    genre = _genre;
}
// Write and Read

std::ostream &operator<<(std::ostream &os, const Genre &genre) {
    os << genre.genre;
    return os;
}

std::istream &operator>>(std::istream &is, Genre &genre) {
    unsigned short _genre;
    is >> _genre;
    genre.setGenre(_genre);
    return is;
}


// Private
void Genre::combineGenre() {
    unsigned short _genre = 0;
    _genre |= (unsigned short) character & 0xF;
    _genre |= ((unsigned short) type & 0xF) << 7;
    _genre |= ((unsigned short) audience & 0xF) << 11;
    parity = !isEvenBitCount(_genre);
    _genre |= (parity & 0x1) << 15;

    genre = _genre;
}

bool Genre::isEvenBitCount(unsigned short number) {
    int count = 0;

    while (number != 0) {
        if (number & 1) {
            count++;
        }
        number >>= 1;
    }

    return count % 2 == 0;
}



