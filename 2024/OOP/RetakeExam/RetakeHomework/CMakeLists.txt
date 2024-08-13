cmake_minimum_required(VERSION 3.10)

project(OopRetake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(DataSource_Headers
        DataSource.inl
        DataSource.h
        DefaultDataSource.inl
        DefaultDataSource.h
        GeneratorDataSource.inl
        GeneratorDataSource.h
        Generator.inl
        Generator.h
        StatelessGenerator.inl
        StatelessGenerator.h
        ArrayDataSource.inl
        ArrayDataSource.h
        FileDataSource.inl
        FileDataSource.h
        FileDataSource.inl
        AlternateDataSource.inl
        AlternateDataSource.h
        PrimeNumberGenerator.inl
        PrimeNumberGenerator.h)

set_target_properties(DataSource_Headers PROPERTIES LINKER_LANGUAGE CXX)

add_executable(DataSourceHw
        main.cpp
)

target_link_libraries(DataSourceHw DataSource_Headers)