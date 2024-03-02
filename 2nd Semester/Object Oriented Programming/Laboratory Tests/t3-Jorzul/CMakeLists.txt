cmake_minimum_required(VERSION 3.24)
project(t3_Jorzul)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(t3_Jorzul
        domain.cpp
        domain.h
        main.cpp
        repository.h
        repository.cpp
        service.cpp
        service.h test3.h test3.cpp)
