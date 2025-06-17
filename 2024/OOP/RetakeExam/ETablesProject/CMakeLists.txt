
project(ETables)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
cmake_minimum_required(VERSION 3.10)


add_library(ETable_Headers
        Utility.h
        Types.h)

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