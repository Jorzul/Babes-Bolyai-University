cmake_minimum_required(VERSION 3.24)
project(LAB_2_Server C)

set(CMAKE_C_STANDARD 11)

link_libraries(ws2_32 wsock32)

add_executable(LAB_2_Server
        Server.c)
