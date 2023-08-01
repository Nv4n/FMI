cmake_minimum_required(VERSION 3.22)

project(Project_SocialMedia)
project(Retake_Sounds)

set(CMAKE_CXX_STANDARD 14)

include_directories(Course2/SummerSemester/ReOOP)

add_executable(Project_SocialMedia
        Course2/SummerSemester/ReOOP/Project/User.cpp Course2/SummerSemester/ReOOP/Project/User.h Course2/SummerSemester/ReOOP/Project/Set.inl Course2/SummerSemester/ReOOP/Project/Set.h Course2/SummerSemester/ReOOP/Project/SystemCommander.cpp Course2/SummerSemester/ReOOP/Project/SystemCommander.h Course2/SummerSemester/ReOOP/Project/Topic.cpp Course2/SummerSemester/ReOOP/Project/Topic.h Course2/SummerSemester/ReOOP/Project/Question.cpp Course2/SummerSemester/ReOOP/Project/Question.h Course2/SummerSemester/ReOOP/Project/Comment.cpp Course2/SummerSemester/ReOOP/Project/Comment.h Course2/SummerSemester/ReOOP/Project/Database.cpp Course2/SummerSemester/ReOOP/Project/Database.h Course2/SummerSemester/ReOOP/Project/Demo.cpp)

add_executable(Retake_Sounds
        Course2/SummerSemester/ReOOP/RetakeSounds/Sound.h Course2/SummerSemester/ReOOP/RetakeSounds/Sound.cpp Course2/SummerSemester/ReOOP/RetakeSounds/Silence.cpp Course2/SummerSemester/ReOOP/RetakeSounds/Silence.h Course2/SummerSemester/ReOOP/RetakeSounds/FileSound.cpp Course2/SummerSemester/ReOOP/RetakeSounds/FileSound.h)