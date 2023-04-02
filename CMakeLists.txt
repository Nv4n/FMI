cmake_minimum_required(VERSION 3.22)

project(Week05_OOPCoin_Homework01)

set(CMAKE_CXX_STANDARD 14)

include_directories(Course2/SummerSemester/ReOOP)

add_executable(Week05_OOPCoin_Homework01
        Course2/SummerSemester/ReOOP/Homework01/demo.cpp
        Course2/SummerSemester/ReOOP/Homework01/UserHelper.cpp
        Course2/SummerSemester/ReOOP/Homework01/UserHelper.h
        Course2/SummerSemester/ReOOP/Homework01/TransactionHelper.cpp
        Course2/SummerSemester/ReOOP/Homework01/TransactionHelper.h Course2/SummerSemester/ReOOP/Homework01/RichDataHelper.cpp Course2/SummerSemester/ReOOP/Homework01/RichDataHelper.h)
