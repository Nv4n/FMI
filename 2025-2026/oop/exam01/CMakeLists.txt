# Specifies the minimum version of CMake required to build the project
cmake_minimum_required(VERSION 3.26)

# Sets the project name
project(Exam01)

# Specifies the C++ standard to use (e.g., 11, 14, 17, 20, 23)
set(CMAKE_CXX_STANDARD 17)

# Creates an executable target named 'MyProjectName' using 'main.cpp'
add_executable(Exam01 main.cpp
        Date.cpp
        Date.h)
