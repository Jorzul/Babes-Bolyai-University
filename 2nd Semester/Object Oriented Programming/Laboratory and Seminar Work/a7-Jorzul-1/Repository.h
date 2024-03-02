//
// Created by User on 5/17/2023.
//

#ifndef A7_JORZUL_1_REPOSITORY_H
#define A7_JORZUL_1_REPOSITORY_H

#pragma once
#include "Movie.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace Positions
{
    const int INDEX_NOT_FOUND = -1;
}

class Repository
{
protected:
    std::vector<Movie> movies;

public:
    Repository();
    virtual ~Repository();
    virtual void load_movies_into_repo() {};
    virtual void saveMovies() {};
    virtual void addMovie(const Movie &);
    virtual void removeMovie(Movie &);
    virtual void removeMovieByPosition(int);
    virtual void updateMovie(int, const Movie &);
    bool validatePosition(int) const;
    std::vector<Movie> getMovies() const;
    size_t getMoviesCount() const;
    Movie getMovieByPosition(int) const;
    int returnPosition(Movie &);
    void modifyLikesCountOfMovieByPosition(int, int);
};

#endif //A7_JORZUL_1_REPOSITORY_H
