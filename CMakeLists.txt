cmake_minimum_required(VERSION 3.22)

project(Week03_FSTREAM_T01)
project(Week05_OOPCoin_Homework01)

set(CMAKE_CXX_STANDARD 14)

include_directories(Course2/WinterSemester/StructuresOfData)

add_executable(Week03_FSTREAM_T01
        Course2/SummerSemester/ReOOP/Week03/tasksfstream.cpp)

add_executable(Week05_OOPCoin_Homework01
        Course2/SummerSemester/ReOOP/Homework01/demo.cpp Course2/SummerSemester/ReOOP/Homework01/UserObj.cpp Course2/SummerSemester/ReOOP/Homework01/UserObj.h Course2/SummerSemester/ReOOP/Homework01/TransactionHelper.cpp Course2/SummerSemester/ReOOP/Homework01/TransactionHelper.h)