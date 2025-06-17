cmake_minimum_required(VERSION 3.10)

project(TurnBasedGame)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set_target_properties(Game PROPERTIES LINKER_LANGUAGE CXX)

add_executable(Game
Armor.cpp Armor.h
        Unit.cpp
        Unit.h
        LivingUnits.cpp
        LivingUnits.h
        UndeadUnits.cpp
        UndeadUnits.h
        Leaders.cpp
        Leaders.h
        Validator.cpp
        Validator.h
        test1.cpp
        Validator2.cpp
        Validator2.h)

