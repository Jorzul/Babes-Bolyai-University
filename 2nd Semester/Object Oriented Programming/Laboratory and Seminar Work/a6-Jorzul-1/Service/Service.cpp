//
// Created by User on 5/4/2023.
//

#include <algorithm>
#include "Service.h"
using namespace std;

Service::Service(Repository& repository)
/*
 * Constructor that takes a reference to a repository and sets the `_repository` pointer.
*
* parameters: repository: The repository to use for managing movies.
*/
{
    _repository = &repository;
}

Service::~Service()
= default;
/*
* Destructor that deletes the `_repository` pointer.
*/

int Service::add_movie(const char title[], const char genre[], unsigned int year, unsigned int likes, const char trailer[])
/*
* Adds a movie to the repository with the given title, genre, year, likes, and trailer.
*
* parameters: title: The title of the movie, genre: Genre of the movie, year: The year of the release of the movie,
 *              likes: The number of likes, trailer: The link to the trailer of the movie
 *return: 1 if the movie was successfully added
 *          0 if the movie cannot be added (it already exists)
*/
{
    // int size = -1;
    // Movie* allMovies = get_all_movies(size);

    /*for (int i = 0; i < size; i++)
        if (strcmp(allMovies[i].get_title(), title) == 0)
            return 0;*/

    vector<TElem> allMoviesSTL = this->_repository->get_all_entities_STL();

    for( auto movie : allMoviesSTL){
        if (strcmp(movie.get_title(), title) == 0)
            return 0;
    }

    Movie movieToAdd(title, genre, year, likes, trailer);

    _repository->add_entity(movieToAdd);

    return 1;
}

int Service::delete_movie(char title[])
/*
* Deletes the movie with the given title from the repository.
*
* parameters: title: The title of the movie to delete.
* return: 1 if the movie was successfully deleted,
 *          0 if no movie with the given title was found.
*/
{
    // int size = -1;
    //Movie* allMovies = get_all_movies(size);

    /*for (int i = 0; i < size; i++)
    {
        if (strcmp(allMovies[i].get_title(), title) != 0) continue;

        _repository->delete_entity_at(i);

        return 1;
    }*/

    vector<TElem> allMoviesSTL = this->_repository->get_all_entities_STL();
    int index = -1;

    for (auto movie: allMoviesSTL)
    {
        index++;
        if (strcmp(movie.get_title(), title) != 0) continue;

        _repository->delete_entity_at(index);

        return 1;
    }

    return 0;
}

int Service::update_movie(char title[], char newTitle[], char newGenre[], unsigned int newYear, unsigned int newLikes, char newTrailer[])
/*
* Updates the movie with the given title with new information.
*
* parameters: title: The title of the movie, newTitle: The updated movie title, newGenre: The updated genre of the movie,
*              newYear: The updated year of the release of the movie, newLikes: The updated number of likes of the movie,
*              newTrailer: The updated link to the movie trailer
* return: 1 if the movie was successfully updated,
*          0 if no movie with the given title was found.
*/
{
    // int size = -1;
    // Movie* allMovies = get_all_movies(size);

    vector<TElem> allMoviesSTL = this->_repository->get_all_entities_STL();
    int index = -1;

    /*for (int i = 0; i < size; i++)
    {
        if (strcmp(allMovies[i].get_title(), title) != 0) continue;

        Movie newMovie{ newTitle, newGenre, newYear, newLikes, newTrailer };

        _repository->update_entity_at(i, newMovie);

        return 1;
    }*/

    for (auto movie: allMoviesSTL)
    {
        index++;
        if (strcmp(movie.get_title(), title) != 0) continue;

        Movie newMovie{ newTitle, newGenre, newYear, newLikes, newTrailer};

        _repository->update_entity_at(index, newMovie);

        return 1;
    }

    return 0;
}

Movie* Service::get_all_movies(int& size)
/*
* Returns an array of all the movies in the repository.
*
* parameters: size: A reference to an integer that will be set to the size of the returned array.
* return: A pointer to an array of Movie objects containing all the movies in the repository.
*/
{
    size = _repository->get_size();
    return _repository->get_all_entities();
}

Movie* Service::get_all_movies_of_genres(char genre[], int &size)
/*
 * Returns an array of all the movies in the repository of a given genre.
 *
 * parameters: genre: The genre of the movie, size: A reference to an integer that will be set to the size of the returned array.
 * return: The array of all movies of a given genre.
 */
{
    int initialSize = _repository->get_size();
    Movie* allMovies = _repository->get_all_entities();

    size = 0;

    for (int i = 0; i < initialSize; i++)
        if (strcmp(allMovies[i].get_genre(), genre) == 0 || strcmp("", genre) == 0)
            size++;

    auto* allMoviesOfGenre = (Movie*)(malloc(size * sizeof(Movie)));

    int currentIndex = 0;

    for (int i = 0; i < initialSize; i++)
    {
        if (strcmp(allMovies[i].get_genre(), genre) == 0 || strcmp("", genre) == 0)
            allMoviesOfGenre[currentIndex++] = allMovies[i];
    }

    return allMoviesOfGenre;
}
