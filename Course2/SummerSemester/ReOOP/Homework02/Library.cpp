//
// Created by Sybatron on 5/26/2023.
//

#include "Library.h"
#include "PeriodicPublication.h"

void Library::addItem(Item *&item) {
    items.pushBack(item);
}

void Library::removeItem(const size_t libraryID) {
    for (int i = 0; i < items.getSize(); ++i) {
        if (libraryID == items[i]->getLibraryId()) {
            items.remove(i);
            break;
        }
    }
}

void Library::printItems() {

    items.sort([](Item *&lvs, Item *&rvs) -> int {
        int yearComparison = lvs->getPublishYear() - rvs->getPublishYear();
        if (yearComparison != 0) {
            return yearComparison > 0 ? 1 : -1;
        }

        ItemType lvsType = lvs->getType();
        ItemType rvsType = rvs->getType();

        if (!((lvsType == ItemType::COMIC || lvsType == ItemType::PERIODIC_PUBLICATION)
              && (rvsType == ItemType::COMIC || rvsType == ItemType::PERIODIC_PUBLICATION))) {

            if (lvs->getTitle() > rvs->getTitle()) {
                return 1;
            }
            return -1;
        }

        PeriodicPublication *lvsPeriodic = dynamic_cast<PeriodicPublication *>(lvs);
        PeriodicPublication *rvsPeriodic = dynamic_cast<PeriodicPublication *>(rvs);
        if (!(lvsPeriodic != nullptr && rvsPeriodic != nullptr)) {
            return -1;
        }

        if (lvsPeriodic->getTitle() > rvsPeriodic->getTitle()) {
            return 1;
        }
        if (lvsPeriodic->getTitle() < rvsPeriodic->getTitle()) {
            return -1;
        }

        long countComparison = lvsPeriodic->getCount() - rvsPeriodic->getCount();
        if (countComparison != 0) {
            return countComparison > 0 ? 1 : -1;
        }
        return 0;
    });

    for (int i = 0; i < items.getSize(); ++i) {
        std::cout << "#" << i + 1 << " " << items[i] << std::endl;
    }
}
