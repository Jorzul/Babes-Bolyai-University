cmake_minimum_required(VERSION 3.24)
project(a6_Jorzul_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(Domain)
include_directories(Repository)
include_directories(Service)
include_directories(ui)

add_executable(a6_Jorzul_1
        Domain/Movie.cpp
        Domain/Movie.h
        Repository/Repository.cpp
        Repository/Repository.h
        Service/Service.cpp
        Service/Service.h
        ui/ui.cpp
        ui/ui.h
        main.cpp Tests/test.cpp)
