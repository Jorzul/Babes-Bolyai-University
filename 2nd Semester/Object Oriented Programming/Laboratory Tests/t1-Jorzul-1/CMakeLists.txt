cmake_minimum_required(VERSION 3.24)
project(t1_Jorzul_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(domain)
include_directories(repository)
include_directories(service)
include_directories(ui)

add_executable(t1_Jorzul_1
        domain/domain.cpp
        domain/domain.h
        repository/repository.cpp
        repository/repository.h
        service/service.cpp
        service/service.h
        ui/ui.cpp
        ui/ui.h
        main.cpp)
