//
// Created by User on 5/17/2023.
//

#include "Service.h"
#include "Exceptions.h"
#include "CSVWatchList.h"
#include "HTMLWatchList.h"
#include "FileRepository.h"
#include <string>

Service::Service()
{
    this->repository = nullptr;
    this->adminCredentials = false;
    this->watchList = nullptr;
}

Service::~Service()
{
    delete this->watchList;
    delete this->repository;
}

bool Service::compare_strings(const std::string &firstComparedString, const std::string &secondComparedString) const
{
    if (firstComparedString.size() != secondComparedString.size())
        return false;
    for (int index = 0; firstComparedString[index]; ++index)
        if (tolower(firstComparedString[index]) != tolower(secondComparedString[index]))
            return false;
    return true;
}

void Service::setAdminMode(bool adminCredentials)
{
    this->adminCredentials = adminCredentials;
}

bool Service::AdminMode()
{
    return this->adminCredentials;
}

void Service::addMovie(Movie movie)
{
    // If the movie is already in the repository, we don't add it
    if (this->repository->validatePosition(this->repository->returnPosition(movie)))
        throw DuplicateMovieException();

    this->repository->addMovie(movie);
}

void Service::removeMovieByPosition(int positionOfMovie)
{
    if (!this->repository->validatePosition(positionOfMovie))
        throw InvalidPositionException();
    this->repository->removeMovieByPosition(positionOfMovie);
}

void Service::updateMovie(int position, Movie movie)
{
    if (!this->repository->validatePosition(position))
        throw InvalidPositionException();

    if (this->repository->returnPosition(movie) != Positions::INDEX_NOT_FOUND)
        throw DuplicateMovieException();

    this->repository->updateMovie(position, movie);
}

std::vector<Movie> Service::getMovies() const
{
    return this->repository->getMovies();
}

Movie Service::getMovieByPosition(int position) const
{
    if (!this->repository->validatePosition(position))
        throw InvalidPositionException();
    return this->repository->getMovieByPosition(position);
}

std::vector<Movie> Service::getMoviesByGenre(const std::string &genreOfMovie)
{
    std::vector<Movie> moviesWithAGivenGenre;
    for (auto movie : this->repository->getMovies())
    {
        std::string genreOfCurrentMovie = movie.getGenre();
        if (genreOfMovie == "" || (this->compare_strings(genreOfCurrentMovie, genreOfMovie)))
            moviesWithAGivenGenre.push_back(movie);
    }
    return moviesWithAGivenGenre;
}

std::vector<Movie> Service::getMoviesFromWatchList() const
{
    return this->watchList->getMovies();
}

void Service::addMovieToWatchList(Movie movieToAddToWatchList)
{
    this->watchList->addMovie(movieToAddToWatchList);
}

void Service::increaseLikesCountOfMovie(Movie &movieForWhichTheLikesCountWillBeIncreased)
{
    int positionOfMovieThatTheUserHasJustLiked = this->repository->returnPosition(movieForWhichTheLikesCountWillBeIncreased);
    this->repository->modifyLikesCountOfMovieByPosition(positionOfMovieThatTheUserHasJustLiked, 1);
}

void Service::setTypeOfWatchList(FileWatchList *watchList)
{
    this->watchList = watchList;
}

void Service::removeWatchedMovieFromWatchList(int positionOfMovie)
{
    this->watchList->removeMovieFromPlaylist(positionOfMovie);
}

void Service::displayPlaylist()
{
    this->watchList->openInApp();
}

void Service::checkIfMovieIsAlreadyInThePlaylist(const Movie &movie)
{
    this->watchList->checkIfMovieIsAlreadyInThePlaylist(movie);
}

void Service::setTypeOfRepository(Repository *repository)
{
    this->repository = repository;
    this->repository->load_movies_into_repo();
}
