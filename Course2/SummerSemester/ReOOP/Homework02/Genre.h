//
// Created by Sybatron on 5/27/2023.
//

#ifndef HW02_LIBRARY_GENRE_H
#define HW02_LIBRARY_GENRE_H

#include <ostream>

enum class Character {
    FICTION = 0,
    THRILLER,
    CRIME,
};

enum class Type {
    POETRY = 0,
    PROSE,
    DRAMA,
};

enum class Audience {
    CHILDREN = 0,
    TEEN,
    ADULTS,
};

class Genre {
private:
    Character character;
    Type type;
    Audience audience;
    bool parity{};
    unsigned short genre{};

public:
    Genre();

    Genre(Character character, Type type, Audience audience);

    Character getCharacter() const;

    void setCharacter(Character _character);

    Type getType() const;

    void setType(Type _type);

    Audience getAudience() const;

    void setAudience(Audience _audience);

    unsigned short getGenre() const;

    void setGenre(unsigned short _genre);

    friend std::ostream &operator<<(std::ostream &os, const Genre &genre);

    friend std::istream &operator>>(std::istream &is, Genre &genre);

private:
    void combineGenre();

    static bool isEvenBitCount(unsigned short number);
};


#endif //HW02_LIBRARY_GENRE_H
