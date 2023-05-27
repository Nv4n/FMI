//
// Created by Sybatron on 5/27/2023.
//

#ifndef HW02_LIBRARY_GENRE_H
#define HW02_LIBRARY_GENRE_H
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
    bool parity;
    unsigned short genre;

public:
    Character getCharacter() const;

    void setCharacter(Character _character);

    Type getType() const;

    void setType(Type _type);

    Audience getAudience() const;

    void setAudience(Audience _audience);

    unsigned short getGenre() const;

    void setGenre(unsigned short _genre);

private:
    void combineGenre();

    bool isEvenBitCount(unsigned short number);
};


#endif //HW02_LIBRARY_GENRE_H
