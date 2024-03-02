cmake_minimum_required(VERSION 3.24)
project(copy C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(copy
        DynamicArray.c
        DynamicArray.h
        main.c
        Material.c
        Material.h
        Repository.c
        Repository.h
        Service.c
        Service.h
        Tests.c
        Tests.h
        UI.c
        UI.h
        UndoRedo.c
        UndoRedo.h
        Validation.c
        Validation.h)
