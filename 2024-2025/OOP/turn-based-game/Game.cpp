//
// Created by Sybatron on 6/20/2025.
//

#include "Game.h"

Game::Game(int gold, size_t unitLimit)
        : living(Faction::LIVING, gold, unitLimit),
          undead(Faction::UNDEAD, gold, unitLimit) {}

void Game::saveGame(const std::string &filename) {
    std::ofstream out(filename);
    if(!out.is_open()){
        throw std::runtime_error("Cannot open save file: " + filename);
    }
    out << livingWins << ' ' << undeadWins << '\n';
    living.save(out);
    undead.save(out);
    out.close()
}

void Game::loadGame(const std::string &filename) {
    std::ifstream in(filename);
    if(!out.is_open()){
        throw std::runtime_error("Cannot open save file: " + filename);
    }
    in >> livingWins >> undeadWins;
    living.load(in);
    undead.load(in);
}

void Game::restart() {
    living = Base(Faction::LIVING, 1000, 50);
    undead = Base(Faction::UNDEAD, 1000, 50);
    livingWins = undeadWins = 0;
}

bool Game::isGameOver() const {
    return livingWins >= 3 || undeadWins >= 3;
}

void Game::handleCommand(const std::string& commandLine) {
    std::string cmd = commandLine;
    if (cmd.rfind("CREATE ", 0) == 0) {
        std::string name = cmd.substr(7);
        Unit* unit = Unit::createFromName(name, Faction::LIVING);
        if (unit && living.createUnit(unit)) {
            std::cout << "Created unit: " << name << "\n";
        } else {
            std::cout << "Failed to create unit: " << name << "\n";
        }
    } else if (cmd.rfind("SELECT BOSS ", 0) == 0) {
        std::string name = cmd.substr(12);
        for (Unit* c : living.getAliveCommanders()) {
            if (c->getName() == name) {
                selectedLivingCommanders.push_back(c);
                std::cout << "Selected commander: " << name << "\n";
                return;
            }
        }
        std::cout << "Commander not found: " << name << "\n";
    } else if (cmd.rfind("SELECT ", 0) == 0) {
        size_t spacePos = cmd.find(' ', 7);
        if (spacePos != std::string::npos) {
            std::string timesStr = cmd.substr(7, spacePos - 7);
            std::string name = cmd.substr(spacePos + 1);
            int times = std::atoi(timesStr.c_str());
            int count = 0;
            for (Unit* u : living.getAliveUnits()) {
                if (u->getName() == name && count < times) {
                    selectedLivingUnits.push_back(u);
                    ++count;
                }
            }
            std::cout << "Selected " << count << " units of type: " << name << "\n";
        }
    } else if (cmd == "START") {
        startDuel();
    } else if (cmd == "SAVE") {
        saveGame("savegame.txt");
        std::cout << "Game saved.\n";
    } else if (cmd == "LOAD") {
        loadGame("savegame.txt");
        std::cout << "Game loaded.\n";
    } else if (cmd == "EXIT") {
        std::string choice;
        std::cout << "Do you want to save the game before exit? (yes/no): ";
        std::cin >> choice;
        if (choice == "yes") saveGame("savegame.txt");
        std::exit(0);
    } else if (cmd == "RESTART") {
        restart();
        std::cout << "Game restarted.\n";
    }
}

void Game::startDuel() {
    selectedUndeadUnits.clear();
    selectedUndeadCommanders.clear();

    std::vector<Unit*> allUndeadUnits = undead.getAliveUnits();
    std::vector<Unit*> allUndeadCommanders = undead.getAliveCommanders();

    int maxUnits = std::min(3, (int)allUndeadUnits.size());
    int selectedUnitCount = std::rand() % (maxUnits + 1);
    for (int i = 0; i < selectedUnitCount; ++i) {
        int idx = std::rand() % allUndeadUnits.size();
        selectedUndeadUnits.push_back(allUndeadUnits[idx]);
    }

    if (!allUndeadCommanders.empty()) {
        int idx = std::rand() % allUndeadCommanders.size();
        selectedUndeadCommanders.push_back(allUndeadCommanders[idx]);
    }

    std::cout << "\n--- Duel begins ---\n";

    // Nemртви attack
    for (Unit* undead : selectedUndeadCommanders) for (Unit* target : selectedLivingUnits) if (target->isAlive()) { undead->attack(*target); std::cout << undead->getName() << " (Cmd) attacks " << target->getName() << "\n"; break; }
    for (Unit* undead : selectedUndeadUnits) for (Unit* target : selectedLivingUnits) if (target->isAlive()) { undead->attack(*target); std::cout << undead->getName() << " attacks " << target->getName() << "\n"; break; }

    // Living counterattack
    for (Unit* l : selectedLivingCommanders) for (Unit* target : selectedUndeadUnits) if (target->isAlive()) { l->attack(*target); std::cout << l->getName() << " (Cmd) counterattacks " << target->getName() << "\n"; break; }
    for (Unit* l : selectedLivingUnits) for (Unit* target : selectedUndeadUnits) if (target->isAlive()) { l->attack(*target); std::cout << l->getName() << " counterattacks " << target->getName() << "\n"; break; }

    // Final strike from living
    for (Unit* l : selectedLivingUnits) for (Unit* target : selectedUndeadUnits) if (target->isAlive()) { l->attack(*target); std::cout << l->getName() << " final hit " << target->getName() << "\n"; break; }

    // Check winner
    bool undeadAlive = false, livingAlive = false;
    for (Unit* u : selectedUndeadUnits) if (u->isAlive()) undeadAlive = true;
    for (Unit* u : selectedUndeadCommanders) if (u->isAlive()) undeadAlive = true;
    for (Unit* u : selectedLivingUnits) if (u->isAlive()) livingAlive = true;
    for (Unit* u : selectedLivingCommanders) if (u->isAlive()) livingAlive = true;

    if (undeadAlive && !livingAlive) {
        undeadWins++;
        std::cout << "\nUndead win the duel!\n";
    } else if (!undeadAlive && livingAlive) {
        livingWins++;
        std::cout << "\nLiving win the duel!\n";
    } else {
        std::cout << "\nThe duel ends in a draw.\n";
    }

    living.addGold(1000);
    undead.addGold(1000);

    selectedLivingUnits.clear();
    selectedLivingCommanders.clear();
}

