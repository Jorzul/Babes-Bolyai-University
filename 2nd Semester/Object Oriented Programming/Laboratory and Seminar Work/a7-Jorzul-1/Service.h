//
// Created by User on 5/17/2023.
//

#ifndef A7_JORZUL_1_SERVICE_H
#define A7_JORZUL_1_SERVICE_H

#pragma once
#include "Repository.h"
#include "MovieValidator.h"
#include "WatchList.h"
#include "FileWatchList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <initializer_list>

class Service
{
private:
    Repository *repository;
    bool adminCredentials;
    FileWatchList *watchList;
    std::vector<int> indexesOfMoviesThatTheUserLikes;

public:
    Service();
    ~Service();
    bool compare_strings(const std::string &, const std::string &) const;
    void addMovie(Movie);
    void removeMovieByPosition(int);
    void updateMovie(int, Movie);
    std::vector<Movie> getMovies() const;
    Movie getMovieByPosition(int) const;
    void setAdminMode(bool);
    bool AdminMode();
    std::vector<Movie> getMoviesByGenre(const std::string &);
    std::vector<Movie> getMoviesFromWatchList() const;
    void removeWatchedMovieFromWatchList(int);
    void addMovieToWatchList(Movie);
    void increaseLikesCountOfMovie(Movie &);
    void setTypeOfWatchList(FileWatchList *);
    void setTypeOfRepository(Repository *);
    void displayPlaylist();
    void checkIfMovieIsAlreadyInThePlaylist(const Movie &);
};

#endif //A7_JORZUL_1_SERVICE_H
