cmake_minimum_required(VERSION 3.22)

project(Week07_Task01)
project(Week07_Task02)
project(Week07_Task03)
project(Week07_HonoiTowers)
project(Week07_KARH)

set(CMAKE_CXX_STANDARD 14)

include_directories(Course2/StructuresOfData)


add_executable(Week07_Task01
        Course2/StructuresOfData/Week07/01-fillgaps.cpp)

add_executable(Week07_Task02
        Course2/StructuresOfData/Week07/02-makeFib.cpp)

add_executable(Week07_Task03
        Course2/StructuresOfData/Week07/03-reverseList.cpp
        )

add_executable(Week07_HonoiTowers
        Course2/StructuresOfData/Week07/HonoiTowers/honoiTowers.cpp)

add_executable(Week07_KARH
        Course2/StructuresOfData/Week07/KARH/karh.cpp
        )