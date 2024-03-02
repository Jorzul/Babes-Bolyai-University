cmake_minimum_required(VERSION 3.24)
project(exSLLA)

set(CMAKE_CXX_STANDARD 14)

include_directories(exSLLA)

add_executable(exSLLA
        exSLLA/App.cpp
        exSLLA/Iterator.cpp
        exSLLA/Iterator.h
        exSLLA/SLLArr.cpp
        exSLLA/SLLArr.h)
