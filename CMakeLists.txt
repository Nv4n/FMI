cmake_minimum_required(VERSION 3.22)

include_directories(Course2/SummerSemester/ReOOP)
project(Project_SocialMedia)
project(Retake_Sounds)
set(CMAKE_CXX_STANDARD 14)
set_source_files_properties(FileSound.inl PROPERTIES LANGUAGE CXX)
set_source_files_properties(PeriodicSound.inl PROPERTIES LANGUAGE CXX)
set_source_files_properties(Silence.inl PROPERTIES LANGUAGE CXX)
set_source_files_properties(Sound.inl PROPERTIES LANGUAGE CXX)


add_executable(Project_SocialMedia
        Course2/SummerSemester/ReOOP/Project/User.cpp Course2/SummerSemester/ReOOP/Project/User.h Course2/SummerSemester/ReOOP/Project/Set.inl Course2/SummerSemester/ReOOP/Project/Set.h Course2/SummerSemester/ReOOP/Project/SystemCommander.cpp Course2/SummerSemester/ReOOP/Project/SystemCommander.h Course2/SummerSemester/ReOOP/Project/Topic.cpp Course2/SummerSemester/ReOOP/Project/Topic.h Course2/SummerSemester/ReOOP/Project/Question.cpp Course2/SummerSemester/ReOOP/Project/Question.h Course2/SummerSemester/ReOOP/Project/Comment.cpp Course2/SummerSemester/ReOOP/Project/Comment.h Course2/SummerSemester/ReOOP/Project/Database.cpp Course2/SummerSemester/ReOOP/Project/Database.h Course2/SummerSemester/ReOOP/Project/Demo.cpp)

add_executable(Retake_Sounds
        Course2/SummerSemester/ReOOP/RetakeSounds/Sound.h
        Course2/SummerSemester/ReOOP/RetakeSounds/Sound.inl
        Course2/SummerSemester/ReOOP/RetakeSounds/Silence.inl
        Course2/SummerSemester/ReOOP/RetakeSounds/Silence.h
        Course2/SummerSemester/ReOOP/RetakeSounds/FileSound.inl
        Course2/SummerSemester/ReOOP/RetakeSounds/FileSound.h
        Course2/SummerSemester/ReOOP/RetakeSounds/PeriodicSound.inl
        Course2/SummerSemester/ReOOP/RetakeSounds/PeriodicSound.h
        Course2/SummerSemester/ReOOP/RetakeSounds/main.cpp Course2/SummerSemester/ReOOP/RetakeSounds/Mix.inl Course2/SummerSemester/ReOOP/RetakeSounds/Mix.h Course2/SummerSemester/ReOOP/RetakeSounds/Sequence.inl Course2/SummerSemester/ReOOP/RetakeSounds/Sequence.h Course2/SummerSemester/ReOOP/RetakeSounds/Effect.inl Course2/SummerSemester/ReOOP/RetakeSounds/Effect.h Course2/SummerSemester/ReOOP/RetakeSounds/Playlist.cpp Course2/SummerSemester/ReOOP/RetakeSounds/Playlist.h)