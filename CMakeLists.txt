cmake_minimum_required(VERSION 3.22)

project(Week12_ExamV01T01)
project(Week12_ExamV01T02)
project(Week12_ExamV02T01)
project(Week12_ExamV02T02)
project(JsonParser)
project(FastFix)


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

add_executable(JsonParser
        Course2/StructuresOfData/JsonParser/src/JsonParser.cpp
        Course2/StructuresOfData/JsonParser/headers/JsonParser.h
        Course2/StructuresOfData/JsonParser/src/CommandInterpreter.cpp
        Course2/StructuresOfData/JsonParser/headers/CommandInterpreter.h
        Course2/StructuresOfData/JsonParser/src/CommandLineValidator.cpp
        Course2/StructuresOfData/JsonParser/headers/CommandLineValidator.h Course2/StructuresOfData/JsonParser/src/main.cpp)

file(COPY Course2/StructuresOfData/JsonParser/organization.json
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


add_executable(FastFix
        Course2/StructuresOfData/FastFix/getQuestions.cpp)
file(COPY Course2/StructuresOfData/FastFix/inputQuestions.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

