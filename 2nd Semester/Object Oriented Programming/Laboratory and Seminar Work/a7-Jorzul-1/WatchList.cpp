//
// Created by User on 5/17/2023.
//

#include "WatchList.h"
#include "Exceptions.h"

void WatchList::addMovie(const Movie &movie)
{
    this->movies.push_back(movie);
}

void WatchList::checkIfMovieIsAlreadyInThePlaylist(const Movie &movie)
{
    for (auto movieFromPlaylist : this->movies)
        if (movieFromPlaylist.getTitle() == movie.getTitle())
            throw DuplicateMovieException();
}

void WatchList::removeMovieFromPlaylist(int positionOfMovie)
{
    std::vector<Movie>::iterator iteratorPointingToMovieThatWillBeErased = this->movies.begin();
    std::advance(iteratorPointingToMovieThatWillBeErased, positionOfMovie);
    if (iteratorPointingToMovieThatWillBeErased != this->movies.end())
        this->movies.erase(iteratorPointingToMovieThatWillBeErased);
}
