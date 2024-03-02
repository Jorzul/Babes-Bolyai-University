#ifndef SERVICE_H
#define SERVICE_H

#include "Repository.h"

class Service {
private:
    Repository* _repository;

public:
    /**
     * Constructor that takes a reference to a repository and sets the `_repository` pointer.
     *
     * @param repository The repository to use for managing movies.
     */
    Service(Repository& movieRepository);

    /**
     * Destructor that deletes the `_repository` pointer.
     */
    ~Service();

    /**
     * Adds a movie to the repository with the given title, genre, year, likes, and trailer.
     *
     * @param title The title of the movie.
     * @param genre The genre of the movie.
     * @param year The year the movie was released.
     * @param likes The number of likes the movie has.
     * @param trailer The URL of the movie's trailer.
     * @return 1 if the movie was successfully added, 0 if a movie with the same title already exists.
     */
    int AddMovie(const char title[], const char genre[], unsigned int year, unsigned int likes, const char trailer[]);

    /**
     * Deletes the movie with the given title from the repository.
     *
     * @param title The title of the movie to delete.
     * @return 1 if the movie was successfully deleted, 0 if no movie with the given title was found.
     */
    int DeleteMovie(char title[]);

    /**
     * Updates the movie with the given title with new information.
     *
     * @param title The title of the movie to update.
     * @param newTitle The new title of the movie.
     * @param newGenre The new genre of the movie.
     * @param newYear The new year the movie was released.
     * @param newLikes The new number of likes the movie has.
     * @param newTrailer The new URL of the movie's trailer.
     * @return 1 if the movie was successfully updated, 0 if no movie with the given title was found.
     */
    int UpdateMovie(char title[], char newTitle[], char newGenre[], unsigned int newYear, unsigned int newLikes, char newTrailer[]);

    /**
     * Returns an array of all the movies in the repository.
     *
     * @param size A reference to an integer that will be set to the size of the returned array.
     * @return A pointer to an array of Movie objects containing all the movies in the repository.
     */
    Movie* GetAllMovies(int& size);

    Movie* GetAllMoviesOfGenre(char genre[], int& size);
};

#endif
