cmake_minimum_required(VERSION 3.24)
project(SortedIndexedLists)

set(CMAKE_CXX_STANDARD 14)

include_directories(SortedIndexedList)

add_executable(SortedIndexedLists
        SortedIndexedList/App.cpp
        SortedIndexedList/ExtendedTest.cpp
        SortedIndexedList/ExtendedTest.h
        SortedIndexedList/ListIterator.cpp
        SortedIndexedList/ListIterator.h
        SortedIndexedList/ShortTest.cpp
        SortedIndexedList/ShortTest.h
        SortedIndexedList/SortedIndexedList.h
        SortedIndexedList/SortedIndexeList.cpp)
