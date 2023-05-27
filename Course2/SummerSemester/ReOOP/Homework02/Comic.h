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
    ~Comic() override;

};


#endif //HW02_LIBRARY_COMIC_H
