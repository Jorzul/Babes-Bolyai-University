cmake_minimum_required(VERSION 3.24)
project(TESTING__FOR_FUN_)

set(CMAKE_CXX_STANDARD 14)

include_directories(domain)
include_directories(repository)
include_directories(service)
include_directories(ui)

add_executable(TESTING__FOR_FUN_
        domain.cpp
        domain.h
        repository.cpp
        repository.h
        service.cpp
        service.h
        ui.cpp
        ui.h
        main.cpp)
