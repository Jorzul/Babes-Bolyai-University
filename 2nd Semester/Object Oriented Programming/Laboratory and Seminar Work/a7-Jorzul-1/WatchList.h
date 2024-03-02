//
// Created by User on 5/17/2023.
//

#ifndef A7_JORZUL_1_WATCHLIST_H
#define A7_JORZUL_1_WATCHLIST_H

#pragma once
#include "Movie.h"

class WatchList
{
protected:
    std::vector<Movie> movies;

public:
    WatchList() {};
    virtual ~WatchList() {}
    void addMovie(const Movie &);
    void removeMovieFromPlaylist(int);
    void checkIfMovieIsAlreadyInThePlaylist(const Movie &);
    std::vector<Movie> getMovies() const { return this->movies; }
};

#endif //A7_JORZUL_1_WATCHLIST_H
