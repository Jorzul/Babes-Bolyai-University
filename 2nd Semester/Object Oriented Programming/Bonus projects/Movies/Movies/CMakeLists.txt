cmake_minimum_required(VERSION 3.24)
project(norbi)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(norbi
        App.cpp
        Console.cpp
        Console.h
        DynamicVector.h
        Movie.cpp
        Movie.h
        Repository.cpp
        Repository.h
        Service.cpp
        Service.h testqtwidget.cpp)
