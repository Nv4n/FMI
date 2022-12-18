cmake_minimum_required(VERSION 3.22)

project(Week09_TreesT01)
project(Week09_TreesT02)
project(Week09_TreesT03)
project(Week09_TreesT04)
project(Week09_TreesT05)
project(Week11_AdditionalT01)
project(Week11_AdditionalT02)
project(Week11_AdditionalT03)
project(Week11_AdditionalT04)
project(Week11_AdditionalT05)
project(Week11_AdditionalT06)

set(CMAKE_CXX_STANDARD 14)

include_directories(Course2/StructuresOfData)

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

add_executable(Week11_AdditionalT01
        Course2/StructuresOfData/Week11/additional/task01.cpp)

add_executable(Week11_AdditionalT02
        Course2/StructuresOfData/Week11/additional/task02.cpp)

add_executable(Week11_AdditionalT03
        Course2/StructuresOfData/Week11/additional/task03.cpp)

add_executable(Week11_AdditionalT04
        Course2/StructuresOfData/Week11/additional/task04.cpp)

add_executable(Week11_AdditionalT05
        Course2/StructuresOfData/Week11/additional/task05.cpp)

add_executable(Week11_AdditionalT06
        Course2/StructuresOfData/Week11/additional/task06.cpp)
