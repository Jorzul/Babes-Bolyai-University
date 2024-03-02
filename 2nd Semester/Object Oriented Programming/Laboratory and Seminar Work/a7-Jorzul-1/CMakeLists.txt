CMAKE_MINIMUM_REQUIRED(VERSION 3.22.4)
PROJECT(a7_Jorzul_1)

SET(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES(.)

ADD_EXECUTABLE(a7_Jorzul_1
        main.cpp

        CSVWatchList.h
        CSVWatchList.cpp

        Exceptions.h
        Exceptions.cpp

        FileRepository.h
        FileRepository.cpp

        FileWatchList.h
        FileWatchList.cpp

        HTMLWatchList.h
        HTMLWatchList.cpp

        Movie.h
        Movie.cpp

        MovieValidator.h
        MovieValidator.cpp

        Repository.h
        Repository.cpp

        Service.h
        Service.cpp

        UI.h
        UI.cpp

        StringUtilities.h
        StringUtilities.cpp

        WatchList.h
        WatchList.cpp

        )