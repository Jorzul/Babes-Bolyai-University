//
// Created by User on 5/17/2023.
//

#ifndef A7_JORZUL_1_FILEREPOSITORY_H
#define A7_JORZUL_1_FILEREPOSITORY_H

#pragma once
#include "Repository.h"

class FileRepository : public Repository
{
private:
    std::string fileName;

public:
    FileRepository(const std::string &fileName) : fileName{fileName} {};
    virtual ~FileRepository();
    void load_movies_into_repo();
    void saveMovies();
    void addMovie(const Movie &);
    void removeMovie(Movie &);
    void removeMovieByPosition(int);
    void updateMovie(int, const Movie &);
};

#endif //A7_JORZUL_1_FILEREPOSITORY_H
