cmake_minimum_required(VERSION 3.22)

project(Task01NRow)
project(Task01_1Factorial)
project(Task02Polymorphism)
project(Week02_SLL)
project(Week02_LinkedList)

set(CMAKE_CXX_STANDARD 14)

include_directories(Course2/StructuresOfData/Week01)

add_executable(Task01NRow
        Course2/StructuresOfData/Week01/Task01.cpp)

add_executable(Task01_1Factorial
        Course2/StructuresOfData/Week01/Task01_1Factorial.cpp)

add_executable(Task02Polymorphism
        Course2/StructuresOfData/Week01/Polymorphism/Hero.cpp Course2/StructuresOfData/Week01/Polymorphism/Hero.h Course2/StructuresOfData/Week01/Polymorphism/Magician.cpp Course2/StructuresOfData/Week01/Polymorphism/Magician.h Course2/StructuresOfData/Week01/Polymorphism/Warrior.cpp Course2/StructuresOfData/Week01/Polymorphism/Warrior.h Course2/StructuresOfData/Week01/Polymorphism/Arena.cpp Course2/StructuresOfData/Week01/Polymorphism/Arena.h Course2/StructuresOfData/Week01/Polymorphism/main.cpp)

add_executable(Week02_SLL
        Course2/StructuresOfData/Week02/SLL.cpp Course2/StructuresOfData/Week02/SLL.h Course2/StructuresOfData/Week02/main.cpp)

add_executable(Week02_LinkedList
        Course2/StructuresOfData/Week02/list/LList.inl Course2/StructuresOfData/Week02/list/LList.h Course2/StructuresOfData/Week02/list/main.cpp)