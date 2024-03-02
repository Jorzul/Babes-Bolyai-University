cmake_minimum_required(VERSION 3.24)
project(Seminar4_Week1_stub)

set(CMAKE_CXX_STANDARD 14)

include_directories(Playlist)

add_executable(Seminar4_Week1_stub
        Playlist/Controller.cpp
        Playlist/Controller.h
        Playlist/main.cpp
        Playlist/PlayList.cpp
        Playlist/PlayList.h
        Playlist/Repository.cpp
        Playlist/Repository.h
        Playlist/RepositoryExceptions.cpp
        Playlist/RepositoryExceptions.h
        Playlist/Song.cpp
        Playlist/Song.h
        Playlist/SongValidator.cpp
        Playlist/SongValidator.h
        Playlist/UI.cpp
        Playlist/UI.h
        Playlist/Utils.cpp
        Playlist/Utils.h)
