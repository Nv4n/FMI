cmake_minimum_required(VERSION 3.0)

project(OopStructures)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Task6_3
        Task6_3.cpp
)

add_executable(Task6_4
        Task6_4.cpp
)
add_executable(Task6_5
        Task6_5.cpp
)

add_executable(Task7_5
        Task7_5.cpp
)

add_executable(Task6_6
        Task6_6.cpp
)
add_executable(Test_Task
        Test_Task.cpp
)

include_directories(Task9_1
        T9_1)
add_executable(Task9_1
        T9_1/Time.h
        T9_1/main.cpp
)


#include_directories(Task9_3
#        T9_3)
#add_executable(Task9_3
#        T9_3/Dictionary.h
#)
#

add_executable(HW01_T1
        HW01/2.cpp
        HW01/2.h

)