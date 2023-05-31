cmake_minimum_required(VERSION 3.22)

project(Project_SocialMedia)
project(HW02_LIBRARY)
#project(TestProj)

set(CMAKE_CXX_STANDARD 14)

include_directories(Course2/SummerSemester/ReOOP)

add_executable(Project_SocialMedia
        Course2/SummerSemester/ReOOP/Project/User.cpp Course2/SummerSemester/ReOOP/Project/User.h Course2/SummerSemester/ReOOP/Project/Set.inl Course2/SummerSemester/ReOOP/Project/Set.h Course2/SummerSemester/ReOOP/Project/SystemCommander.cpp Course2/SummerSemester/ReOOP/Project/SystemCommander.h Course2/SummerSemester/ReOOP/Project/Topic.cpp Course2/SummerSemester/ReOOP/Project/Topic.h)

add_executable(HW02_LIBRARY
        Course2/SummerSemester/ReOOP/Homework02/MinString.cpp Course2/SummerSemester/ReOOP/Homework02/MinString.h Course2/SummerSemester/ReOOP/Homework02/MinVector.inl Course2/SummerSemester/ReOOP/Homework02/MinVector.h Course2/SummerSemester/ReOOP/Homework02/Book.cpp Course2/SummerSemester/ReOOP/Homework02/Book.h Course2/SummerSemester/ReOOP/Homework02/PeriodicPublication.cpp Course2/SummerSemester/ReOOP/Homework02/PeriodicPublication.h Course2/SummerSemester/ReOOP/Homework02/Comic.cpp Course2/SummerSemester/ReOOP/Homework02/Comic.h Course2/SummerSemester/ReOOP/Homework02/Item.cpp Course2/SummerSemester/ReOOP/Homework02/Item.h Course2/SummerSemester/ReOOP/Homework02/User.cpp Course2/SummerSemester/ReOOP/Homework02/User.h Course2/SummerSemester/ReOOP/Homework02/Library.cpp Course2/SummerSemester/ReOOP/Homework02/Library.h Course2/SummerSemester/ReOOP/Homework02/Demo.cpp Course2/SummerSemester/ReOOP/Homework02/Genre.cpp Course2/SummerSemester/ReOOP/Homework02/Genre.h Course2/SummerSemester/ReOOP/Homework02/MinDate.cpp Course2/SummerSemester/ReOOP/Homework02/MinDate.h)
