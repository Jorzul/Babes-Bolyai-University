cmake_minimum_required(VERSION 3.24)
project(send1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(send1
        driver.cpp
        driver.h
        main.cpp
        observer.h
        report.cpp
        report.h
        repository.cpp
        repository.h
        session.cpp
        session.h
        subject.cpp
        subject.h
        ui_user_window.h
        user_window.cpp
        user_window.h
        user_window.ui)
