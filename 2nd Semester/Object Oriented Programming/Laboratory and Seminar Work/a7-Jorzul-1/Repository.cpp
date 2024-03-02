//
// Created by User on 5/17/2023.
//

#include "Repository.h"
#include "Exceptions.h"

using namespace Positions;

Repository::Repository()
{
    this->movies = std::vector<Movie>();
}

Repository::~Repository()
{
}

void Repository::addMovie(const Movie &movie)
{
    this->movies.push_back(movie);
}

void Repository::removeMovie(Movie &movie)
{
    std::vector<Movie>::iterator iterator_for_deleted_elem = std::find(this->movies.begin(), this->movies.end(), movie);
    this->movies.erase(iterator_for_deleted_elem);
}

void Repository::removeMovieByPosition(int position)
{
    this->movies.erase(this->movies.begin() + position);
}

void Repository::updateMovie(int position_of_movie, const Movie &updated_movie)
{
    this->movies[position_of_movie] = updated_movie;
}

std::vector<Movie> Repository::getMovies() const
{
    return this->movies;
}

size_t Repository::getMoviesCount() const
{
    return this->movies.size();
}

Movie Repository::getMovieByPosition(int position) const
{
    if (position < 0 || position >= this->movies.size())
        throw InvalidPositionException();
    return this->movies[position];
}

bool Repository::validatePosition(int position) const
{
    return position >= 0 && position < this->movies.size();
}

int Repository::returnPosition(Movie &movie)
{
    auto iteratorForPosition = std::find(this->movies.begin(), this->movies.end(), movie);
    if (iteratorForPosition == this->movies.end())
        return INDEX_NOT_FOUND;
    return std::distance(this->movies.begin(), iteratorForPosition);
}

void Repository::modifyLikesCountOfMovieByPosition(int position_of_movie, int likes)
{
    Movie movieToBeUpdated = this->getMovieByPosition(position_of_movie);
    movieToBeUpdated.setLikesCount(movieToBeUpdated.getLikesCount() + likes);
    this->updateMovie(position_of_movie, movieToBeUpdated);
}
