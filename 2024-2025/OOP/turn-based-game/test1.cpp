//
// Created by Sybatron on 6/9/2025.
//

#include "Validator.h"
#include "Unit.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    // Инициализация на базите
    Base livingBase(10000, 10, Faction::Living);
    Base undeadBase(8000, 10, Faction::Undead);

    // Създаване на няколко единици
    std::vector<Unit*> allUnits;
    allUnits.push_back(new Unit("Healer", 1000, 500, ArmorType::Leather, 5, 50, false, Faction::Living));
    allUnits.push_back(new Unit("Necromancer", 800, 600, ArmorType::Unarmored, 0, 40, false, Faction::Undead));
    allUnits.push_back(new Unit("Living Commander", 2000, 1000, ArmorType::Heavy, 10, 80, true, Faction::Living));
    allUnits.push_back(new Unit("Undead Commander", 2500, 1200, ArmorType::Heavy, 15, 90, true, Faction::Undead));

    Validator validator(livingBase, undeadBase);

    try {
        // Пример на валидиране на създаване на единица
        validator.validateUnitCreation(livingBase, 1500);
        std::cout << "Unit created successfully.\n";
    } catch (const std::runtime_error& e) {
        std::cout << "Error creating unit: " << e.what() << "\n";
    }

    // Пример на обработка на края на ход
    validator.endTurnHealthAndManaBoost(Faction::Living, allUnits);

    // Пример на получаване на щети и използване на броня
    std::cout << "Before damage: " << allUnits[0]->getName() << " HP=" << allUnits[0]->getHealth() << "\n";
    validator.validateArmorUsage(*allUnits[0], 200);
    std::cout << "After damage: " << allUnits[0]->getName() << " HP=" << allUnits[0]->getHealth() << "\n";

    // Освобождаване на паметта
    for (Unit* u : allUnits) delete u;

    return 0;
}
