cmake_minimum_required(VERSION 3.10)

project(ETables)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(ETable_Headers
        Optional.inl
        Optional.inl
        Utility.h)

set_target_properties(ETable_Headers PROPERTIES LINKER_LANGUAGE CXX)

add_executable(ETable
        Table.cpp
        Table.h
        main.cpp
        Cell.cpp
        Cell.h
        CmdInterpreter.cpp
        CmdInterpreter.h
        CellValueInterpreter.cpp
        CellValueInterpreter.h
)

target_link_libraries(ETable ETable_Headers)