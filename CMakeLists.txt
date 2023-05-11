cmake_minimum_required(VERSION 3.22)

project(Project_SocialMedia)

set(CMAKE_CXX_STANDARD 14)

include_directories(Course2/SummerSemester/ReOOP)

add_executable(Project_SocialMedia
        Course2/SummerSemester/ReOOP/Project/User.cpp Course2/SummerSemester/ReOOP/Project/User.h Course2/SummerSemester/ReOOP/Project/Set.inl Course2/SummerSemester/ReOOP/Project/Set.h Course2/SummerSemester/ReOOP/Project/SystemCommander.cpp Course2/SummerSemester/ReOOP/Project/SystemCommander.h Course2/SummerSemester/ReOOP/Project/Topic.cpp Course2/SummerSemester/ReOOP/Project/Topic.h)