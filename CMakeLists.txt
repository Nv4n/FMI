cmake_minimum_required(VERSION 3.22)
project(Templates)
project(Vector)

set(CMAKE_CXX_STANDARD 14)

include_directories(Course1/OOP-Sem2/Week13)

add_executable(Templates
        Course1/OOP-Sem2/Week13/Templates/main.cpp
        )
add_executable(Vector
        Course1/OOP-Sem2/Week13/Vector/main.cpp
        Course1/OOP-Sem2/Week13/Vector/vector.h
        Course1/OOP-Sem2/Week13/Vector/vector.inl

        )