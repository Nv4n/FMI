//
// Created by Sybatron on 5/26/2023.
//

#ifndef HW02_LIBRARY_PERIODICPUBLICATION_H
#define HW02_LIBRARY_PERIODICPUBLICATION_H

#include <cstddef>
#include "Item.h"

#pragma once
enum class PeriodicPeriod {
    WEEKLY,
    MONTHLY,
    YEARLY
};


class PeriodicPublication : public virtual Item {
protected:
    PeriodicPeriod period{};
    unsigned int issue{};
public:
    virtual ~PeriodicPublication() override;

    PeriodicPublication(const MinString &_title, const MinString &_shortDescr, const size_t &_libraryId,
                        unsigned short _publishYear, PeriodicPeriod _period, unsigned int _issue);

    PeriodicPublication(const PeriodicPublication &other);

    PeriodicPublication();

    PeriodicPublication &operator=(const PeriodicPublication &other);

    Item *clone() const override;

    PeriodicPeriod getPeriod() const;

    void setPeriod(PeriodicPeriod _period);

    void setIssue(unsigned int _issue);

    unsigned int getIssue() const;

    friend std::istream &operator>>(std::istream &is, PeriodicPublication &perPublicat);

    std::ostream &out(std::ostream &os) const override;

protected:

    void copy(const PeriodicPublication &other);
};


#endif //HW02_LIBRARY_PERIODICPUBLICATION_H
