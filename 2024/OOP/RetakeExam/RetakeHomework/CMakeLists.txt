cmake_minimum_required(VERSION 3.10)

project(OopRetake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(DataSource_Headers
        DataSources/DataSource.inl
        DataSources/DataSource.h
        DataSources/DefaultDataSource.inl
        DataSources/DefaultDataSource.h
        DataSources/GeneratorDataSource.inl
        DataSources/GeneratorDataSource.h
        Generators/Generator.inl
        Generators/Generator.h
        Generators/StatelessGenerator.inl
        Generators/StatelessGenerator.h
        DataSources/ArrayDataSource.inl
        DataSources/ArrayDataSource.h
        DataSources/FileDataSource.inl
        DataSources/FileDataSource.h
        DataSources/FileDataSource.inl
        DataSources/AlternateDataSource.inl
        DataSources/AlternateDataSource.h
        Generators/PrimeNumberGenerator.inl
        Generators/PrimeNumberGenerator.h)

set_target_properties(DataSource_Headers PROPERTIES LINKER_LANGUAGE CXX)

add_executable(DataSourceHw
        main.cpp
)

target_link_libraries(DataSourceHw DataSource_Headers)