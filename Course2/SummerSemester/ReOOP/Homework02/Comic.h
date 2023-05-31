//
// Created by Sybatron on 5/26/2023.
//

#ifndef HW02_LIBRARY_COMIC_H
#define HW02_LIBRARY_COMIC_H

#include "PeriodicPublication.h"
#include "Book.h"

#pragma once

class Comic final : public Book, public PeriodicPublication {
public:
    Comic();

    ~Comic() override;

    Comic(const MinString &_title, const MinString &_shortDescr, size_t _libraryId, unsigned short _publishYear,
          const MinString &_author, const MinString &_publisher, const Genre &_genre, PeriodicPeriod period,
          unsigned int issue);

    Comic(const Comic &other);

    Comic &operator=(const Comic &other);

    Item *clone() const override;

};


#endif //HW02_LIBRARY_COMIC_H
