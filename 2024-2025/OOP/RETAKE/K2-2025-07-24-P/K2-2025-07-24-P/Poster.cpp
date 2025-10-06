#include "Poster.h"
#include <stdexcept>

Poster::Poster(char** authors, char* title, bool format[POSTER_FORMAT_LENGTH], char date[POSTER_DATE_LENGTH]) :Article(authors, title)
{
    try {
        for (size_t i = 0; i < POSTER_FORMAT_LENGTH; i++)
        {
            this->format[i] = format[i];
        }
        for (size_t i = 0; i < POSTER_DATE_LENGTH; i++)
        {
            if (date[i] < '0' || date[i]>'9') {
                throw std::invalid_argument("Date consists only of digits");
            }
            this->date[i] = date[i];
        }
    }
    catch (std::invalid_argument& e) {
        Article::clearMem();
        throw e;
    }
}

Poster::Poster(const Poster& other):Article(other)
{
    copy(other);
}

Poster& Poster::operator=(const Poster& other)
{
    if (this != &other) {
        Poster temp(other);
        clearMem();
        std::swap(*this, temp);
    }
    return *this;
}

Article* Poster::clone()
{
    return new Poster(*this);
}

void Poster::copy(const Poster& other)
{
    for (size_t i = 0; i < POSTER_FORMAT_LENGTH; i++)
    {
        this->format[i] = other.format[i];
    }
    for (size_t i = 0; i < POSTER_DATE_LENGTH; i++)
    {
        this->date[i] = other.date[i];
    }
}
