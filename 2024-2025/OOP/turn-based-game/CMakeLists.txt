cmake_minimum_required(VERSION 3.10)

project(TurnBasedGame)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set_target_properties(Game PROPERTIES LINKER_LANGUAGE CXX)

add_executable(Game
        Armor.cpp Armor.h
        Unit.cpp
        Unit.h
        living-creatures/Archer.h
        living-creatures/Archer.cpp
        living-creatures/Knight.h
        living-creatures/Knight.cpp
        living-creatures/Infantryman.h
        living-creatures/Infantryman.cpp
        living-creatures/Healer.cpp
        living-creatures/Healer.h
        living-creatures/Wizard.cpp
        living-creatures/Wizard.h
        undead-creatures/Skeleton.cpp
        undead-creatures/Skeleton.h
        undead-creatures/Ghoul.cpp
        undead-creatures/Ghoul.h
        undead-creatures/Necromancer.cpp
        undead-creatures/Necromancer.h
        undead-creatures/Zombie.cpp
        undead-creatures/Zombie.h
        undead-creatures/Dybbuk.cpp
        undead-creatures/Dybbuk.h
        undead-creatures/Revenant.cpp
        undead-creatures/Revenant.h
        undead-creatures/Ghost.cpp
        undead-creatures/Ghost.h
        undead-creatures/Lich.cpp
        undead-creatures/Lich.h
        undead-creatures/Dreadlord.cpp
        undead-creatures/Dreadlord.h
        undead-creatures/DeathKnight.cpp
        undead-creatures/DeathKnight.h
        living-creatures/UndeadHunter.cpp
        living-creatures/UndeadHunter.h
        living-creatures/BladeDancer.cpp
        living-creatures/BladeDancer.h
        living-creatures/Paladin.cpp
        living-creatures/Paladin.h
        GameConfig.cpp
        GameConfig.h
        LeaderEnums.h
        main.cpp
        Base.cpp
        Base.h
        Game.cpp
        Game.h
        BaseImports.h
)

