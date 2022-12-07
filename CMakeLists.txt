cmake_minimum_required(VERSION 3.22)

project(Week07_KARH)
project(Week09_Trees)
project(Week09_TreesT01)
project(Week09_TreesT02)
project(Week09_TreesT03)
project(Week09_TreesT04)
project(Week09_TreesT05)
project(Week09_Ivo)

set(CMAKE_CXX_STANDARD 14)

include_directories(Course2/StructuresOfData)

add_executable(Week07_KARH
        Course2/StructuresOfData/Week07/KARH/karh.cpp
        )

add_executable(Week09_Trees
        Course2/StructuresOfData/Week09/Trees.cpp)

add_executable(Week09_TreesT01
        Course2/StructuresOfData/Week09/exercises/tree19_1.cpp)

add_executable(Week09_TreesT02
        Course2/StructuresOfData/Week09/exercises/tree19_2.cpp)

add_executable(Week09_TreesT03
        Course2/StructuresOfData/Week09/exercises/tree19_3.cpp)

add_executable(Week09_TreesT04
        Course2/StructuresOfData/Week09/exercises/tree19_4.cpp)

add_executable(Week09_TreesT05
        Course2/StructuresOfData/Week09/exercises/tree19_5.cpp)

add_executable(Week09_Ivo
        Course2/StructuresOfData/Week09/Ivo/ivo.cpp)