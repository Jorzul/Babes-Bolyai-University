cmake_minimum_required(VERSION 3.24)
project(seminar_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(seminar_3
        DynamicVector.h
        main.cpp
        Song.cpp
        Song.h
        Tests.cpp
        Tests.h)
