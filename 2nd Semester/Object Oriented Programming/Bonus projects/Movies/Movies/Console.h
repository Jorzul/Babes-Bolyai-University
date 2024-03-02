#ifndef CONSOLE_H
#define CONSOLE_H

#include "Service.h"

class Console {
private:
    Service* _movieService;
    Service* _watchListService;

    /**
     * Adds ten movies to the service by calling the service's `AddMovie()` function ten times.
     */
    void AddTenMovies();

    /**
     * Prompts the user to enter information for a new movie, and adds it to the service by calling the service's `AddMovie()` function.
     */
    void AddMovie();

    /**
     * Prompts the user to enter the ID of the movie they want to delete, and deletes it from the service by calling the service's `DeleteMovie()` function.
     */
    void DeleteMovie();

    /**
     * Prompts the user to enter the ID of the movie they want to update, and then prompts them to enter updated information for the movie. The updated movie is then passed to the service's `UpdateMovie()` function.
     */
    void UpdateMovie();

    /**
     * Displays all the movies in the service by calling the service's `GetAllMovies()` function and printing the results to the console.
     */
    void DisplayAllMovies();

    /**
     * Displays all the movies in the service by calling the service's `GetAllMovies()` function and printing the results to the console.
     */
    void DisplayAllMoviesOfGenre();

    /**
     * Displays the administrator menu, which allows the user to add ten movies, add a movie, delete a movie, update a movie, display all movies, or exit the program.
     */
    void RunAdministratorMenu();

    /**
     * Displays the user menu, which allows the user to add ten movies, add a movie, delete a movie, update a movie, display all movies, or exit the program.
     */
    void RunUserMenu();

public:
    /**
     * Constructor that takes a reference to a service and sets the `_service` pointer.
     *
     * @param service The service to use for managing movies.
     */
    Console(Service& movieService, Service& watchListService);

    /**
     * Runs the console by displaying the administrator menu and handling user input until the user chooses to exit.
     */
    void RunConsole();

    void DisplayWatchList();

    void DeleteMovieFromWatchList();

    /**
     * Destructor that deletes the `_service` pointer.
     */
    ~Console();
};

#endif
