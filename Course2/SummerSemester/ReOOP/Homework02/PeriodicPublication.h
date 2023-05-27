//
// Created by Sybatron on 5/26/2023.
//

#ifndef HW02_LIBRARY_PERIODICPUBLICATION_H
#define HW02_LIBRARY_PERIODICPUBLICATION_H

#include "Item.h"

#pragma once
enum class PeriodicPeriod {
    UNKNOWN = -1,
    WEEKLY,
    MONTHLY,
    YEARLY
};


class PeriodicPublication : public virtual Item {
protected:
    PeriodicPeriod period;
    unsigned int count;
public:
    virtual ~PeriodicPublication() override;

    unsigned int getCount() const;
};


#endif //HW02_LIBRARY_PERIODICPUBLICATION_H
