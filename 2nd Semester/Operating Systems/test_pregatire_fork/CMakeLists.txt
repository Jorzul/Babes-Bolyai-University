cmake_minimum_required(VERSION 3.24)
project(test_pregatire_fork)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_pregatire_fork main.cpp fork_ex.c pipe_ex_AB.c)
