cmake_minimum_required(VERSION 3.22)

project(Week12_ExamV01T01)
project(Week12_ExamV01T02)
project(Week12_ExamV02T01)
project(Week12_ExamV02T02)
project(Week13_JsonParser)

set(CMAKE_CXX_STANDARD 14)

include_directories(Course2/StructuresOfData)

add_executable(Week12_ExamV01T01
        Course2/StructuresOfData/Week12/examV01/tasks/problem1.cpp)

add_executable(Week12_ExamV01T02
        Course2/StructuresOfData/Week12/examV01/tasks/problem2.cpp)

add_executable(Week12_ExamV02T01
        Course2/StructuresOfData/Week12/examV02/tasks/problem1.cpp)

add_executable(Week12_ExamV02T02
        Course2/StructuresOfData/Week12/examV02/tasks/problem2.cpp)

add_executable(Week12_ExamV02T02
        Course2/StructuresOfData/Week12/examV02/tasks/problem2.cpp)