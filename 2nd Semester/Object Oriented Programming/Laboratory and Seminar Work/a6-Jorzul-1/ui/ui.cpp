//
// Created by User on 5/4/2023.
//

#include "ui.h"

#include<cstdio>
#include<cstring>
#include <windows.h>
#include <shellapi.h>

Console::Console(Service &movieService, Service& watchListService)
/*
* Constructor that takes a reference to a service and sets the `_service` pointer.
*
* parameters: movieService, watchListService: The services used for managing movies.
*/
{
    _movieService = &movieService;
    _watchListService = &watchListService;
}

Console::~Console()
= default;
/*
* Destructor that deletes the `_service` pointer.
*/

static bool validate_year(int year)
{
    if (year < 0)
        return false;
    return true;
}

static bool validate_likes(int likes)
{
    if (likes < 0)
        return false;
    return true;
}

static void remove_last_character(char* str)
{
    // Only removing the last character if there is at least one character and it is '\n'.
    if (strlen(str) > 0 && str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
}


void Console::add_10_random_movies()
/*
* Adds ten movies to the service by calling the service's `add_movie()` function ten times.
*/
{
    _movieService->add_movie("Movie of the year", "Adventure", 2020, 200000,
                             "https://www.youtube.com/watch?v=dQw4w9WgXcQ");
    _movieService->add_movie("Titanic", "Drama", 2008, 650000,
                             "https://www.youtube.com/watch?v=kVrqfYjkTdQ");
    _movieService->add_movie("Marvel's Avengers", "Action", 2002, 95000,
                             "https://www.youtube.com/watch?v=eOrNdBpGMv8");
    _movieService->add_movie("Home Alone", "Comedy", 2004, 500000,
                             "https://www.youtube.com/watch?v=Fmih-zWIjGY");
    _movieService->add_movie("Justitiarul de Berceni", "Action", 2023, 65000,
                             "https://www.youtube.com/watch?v=Q7cJ5_JZjuk");
    _movieService->add_movie("Shrek movie", "Adventure", 2001, 150000,
                             "https://www.youtube.com/watch?v=ooJJX3R42WM");
    _movieService->add_movie("Avatar the last airbender", "Adventure", 2020, 100000,
                             "https://www.youtube.com/watch?v=IphpIUm_F7E");
    _movieService->add_movie("The Amazing Ian", "Adventure", 2010, 65100,
                             "https://www.youtube.com/watch?v=-eo3_509Wmc");
    _movieService->add_movie("Fast and Furious", "Racing", 2012, 690000,
                             "https://www.youtube.com/watch?v=dQw4w9WgXcQ");
    _movieService->add_movie("Pixels", "SF", 2015, 150500,
                             "https://www.youtube.com/watch?v=dQw4w9WgXcQ");
}

void Console::add_movie_ui()
/*
* Prompts the user to enter information for a new movie, and adds it to the service by calling the service's `add_movie()` function.
*/
{
    char title[101];
    char genre[101];
    int year;
    int likes;
    char trailer[101];

    printf("Title : ");
    fgets(title, 100, stdin);

    remove_last_character(title);

    printf("Genre : ");
    fgets(genre, 100, stdin);

    remove_last_character(genre);


    printf("Year : ");
    int yearReadStatus = scanf("%d", &year);

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    if (yearReadStatus != 1)
    {
        printf("The year should be an unsigned integer number.");
        return;
    }

    if (!validate_year(year))
    {
        printf("The year cannot be a negative number.");
        return;
    }

    printf("Likes : ");
    int likesReadStatus = scanf("%d", &likes);


    while ((c = getchar()) != '\n' && c != EOF);

    if (likesReadStatus != 1)
    {
        printf("The likes should be an unsigned integer number.");
        return;
    }

    if (!validate_likes(likes))
    {
        printf("The number of likes cannot be negative.");
        return;
    }


    printf("Trailer : ");
    fgets(trailer, 100, stdin);

    remove_last_character(trailer);

    if (_movieService->add_movie(title, genre, year, likes, trailer) == 1)
        printf("Movie added.\n");
    else printf("There is another movie with the same title.\n");
}

void Console::delete_movie_ui()
/*
* Prompts the user to enter the ID of the movie they want to delete, and deletes it from the service by calling
 * the service's `delete_movie()` function.
*/
{
    char title[101];

    printf("Title : ");
    fgets(title, 100, stdin);

    remove_last_character(title);

    if (_movieService->delete_movie(title) == 1)
        printf("Movie deleted.\n");
    else printf("There is no movie with the given title.\n");
}

void Console::update_movie_ui()
/*
* Prompts the user to enter the ID of the movie they want to update, and then prompts them to enter updated
 * information for the movie. The updated movie is then passed to the service's `update_movie()` function.
*/
{
    char oldTitle[101];
    char newTitle[101];
    char newGenre[101];
    int newYear;
    int newLikes;
    char newTrailer[101];

    printf("Old Title : ");
    fgets(oldTitle, 100, stdin);

    remove_last_character(oldTitle);

    printf("New Title : ");
    fgets(newTitle, 100, stdin);

    remove_last_character(newTitle);

    printf("New Genre : ");
    fgets(newGenre, 100, stdin);

    remove_last_character(newGenre);


    printf("New Year : ");
    int yearReadStatus = scanf("%d", &newYear);

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    if (yearReadStatus != 1)
    {
        printf("The year should be an unsigned integer number.");
        return;
    }

    if (!validate_year(newYear))
    {
        printf("The year cannot be a negative number.");
        return;
    }

    printf("New Likes : ");
    int likesReadStatus = scanf("%d", &newLikes);

    while ((c = getchar()) != '\n' && c != EOF);

    if (likesReadStatus != 1)
    {
        printf("The likes should be an unsigned integer number.");
        return;
    }

    if (!validate_likes(newLikes))
    {
        printf("The number of likes cannot be negative.");
        return;
    }

    printf("New Trailer : ");
    fgets(newTrailer, 100, stdin);

    remove_last_character(newTrailer);

    if (_movieService->update_movie(oldTitle, newTitle, newGenre, newYear, newLikes, newTrailer) == 1)
        printf("Movie updated.\n");
    else printf("There is no movie with the given old title. Operation canceled.\n");
}

void Console::display_all_movies_ui()
/*
* Displays all the movies in the service by calling the service's `get_all_movies()` function and printing the results to the console.
*/
{
    printf("Displaying all the movies :\n");

    int size = -1;
    Movie* allMovies = _movieService->get_all_movies(size);

    if (size == 0)
    {
        printf("No movies yet.\n");

        return;
    }

    for (int i = 0; i < size; i++)
        printf("%d. Title: %s | Genre: %s | Year: %u | Likes: %u | Trailer: %s\n",
               (i+1), allMovies[i].get_title(), allMovies[i].get_genre(), allMovies[i].get_year(),
               allMovies[i].get_likes(), allMovies[i].get_trailer());
}

void Console::display_all_movies_of_genre_ui()
/*
* Displays all the movies in the service by calling the service's `get_all_movies()` function and printing the results to the console.
*/
{
    printf("Displaying all the movies :\n");

    char genre[101];

    printf("Genre : ");
    fgets(genre, 100, stdin);

    remove_last_character(genre);

    int size = -1;
    Movie* allMovies = _movieService->get_all_movies_of_genres(genre, size);

    if (size == 0)
    {
        printf("No movies yet.\n");
        free(allMovies);

        return;
    }

    int current_movie_int = 0;
    bool continue_watching = true;

    char c;
    while (continue_watching)
    {
        printf("%d. Title: %s ; Genre : %s ; Year : %u ; Likes : %u\n",
               (current_movie_int + 1), allMovies[current_movie_int].get_title(), allMovies[current_movie_int].get_genre(),
               allMovies[current_movie_int].get_year(), allMovies[current_movie_int].get_likes());

        // Opening the trailer in the browser.
        ShellExecuteA(nullptr, "open", allMovies[current_movie_int].get_trailer(), nullptr, nullptr, SW_SHOWNORMAL);

        printf("Do you want to add the movie to the watch list? (y/n)");
        while (true)
        {
            char response;
            scanf("%c", &response);

            while ((c = getchar()) != '\n' && c != EOF);

            if (response == 'y')
            {
                if (_watchListService->add_movie(allMovies[current_movie_int].get_title(),
                                                 allMovies[current_movie_int].get_genre(),
                                                 allMovies[current_movie_int].get_year(), allMovies[current_movie_int].get_likes(),
                                                 allMovies[current_movie_int].get_trailer()) == 1)
                    printf("Movie added to the watch list.\n");
                else printf("Movie already in the watch list.\n");
                break;
            }
            else if (response == 'n')
                break;
            else
                printf("Only y / n allowed.");
        }

        printf("Do you want to watch the next movie ? (y/n)");
        while (true)
        {
            char response;
            scanf("%c", &response);

            while ((c = getchar()) != '\n' && c != EOF);

            if (response == 'y')
            {
                current_movie_int = (current_movie_int + 1) % size;
                break;
            }
            else if (response == 'n')
            {
                continue_watching = false;
                break;
            }
            else
                printf("Only y / n allowed.");
        }

        printf("\n");
    }

    free(allMovies);
}

void Console::delete_movie_from_watchlist_ui()
/*
 * If we want to delete a movie from the watchlist, we call this function. We type the title and then the function
 * deletes that movie from the watchList repository.
 */
{
    char title[101], c;

    printf("Title : ");
    fgets(title, 101, stdin);

    remove_last_character(title);

    if (_watchListService->delete_movie(title) == 1) {
        printf("Movie deleted.\n");
        printf("Do you want to like the movie you deleted? (y/n)");

        char response;
        scanf("%c", &response);

        while ((c = getchar()) != '\n' && c != EOF);

        if (response == 'y')
        {
            int size = -1;
            Movie* allMovies = _movieService->get_all_movies(size);

            if (size == 0)
            {
                printf("No movies yet.\n");

                return;
            }

            for (int i = 0; i < size; i++) {
                if (strcmp(allMovies[i].get_title(), title) == 0) {
                    if (_movieService->update_movie(allMovies[i].get_title(), allMovies[i].get_title(),
                                                    allMovies[i].get_genre(), allMovies[i].get_year(),
                                                    allMovies[i].get_likes() + 1, allMovies[i].get_trailer()) == 1)
                        printf("Movie liked successfully.\n");
                    else
                        printf("Going on.\n");
                }
            }
        }
        else if (response == 'n')
        {
            printf("Going on.\n");
        }
        else
            printf("Only y / n allowed.");
    }
    else printf("There is no movie with the given title in the watch list. Operation canceled.\n");
}

void Console::display_watchlist_ui()
/*
 * This function displays all the movies from the watchlist.
 */
{
    printf("Displaying the watch list :\n");

    int size = -1;
    Movie* allMovies = _watchListService->get_all_movies(size);

    if (size == 0)
        printf("No movies added to the watch list yet.\n");

    for (int i = 0; i < size; i++)
        printf("%d. Title: %s ; Genre : %s ; Year : %u ; Likes : %u ; Trailer : %s\n",
               (i + 1), allMovies[i].get_title(), allMovies[i].get_genre(), allMovies[i].get_year(),
               allMovies[i].get_likes(), allMovies[i].get_trailer());
}

static void print_user_options() {
    printf("\nChoose the option:\n");
    printf("1. Display all movies of genre.\n");
    printf("2. Delete movie from watch list.\n");
    printf("3. Display the watch list.\n");
    printf("0. Exit user mode.\n");
}

void Console::user_menu()
/*
* Displays the user menu, which allows the user to add ten movies, add a movie, delete a movie, update a movie,
 * display all movies, or exit the program.
*/
{
    while (true)
    {
        print_user_options();

        int option = -1;

        while (true) {

            printf(">");

            if (scanf("%d", &option) == 1)
                break;

            printf("The option should be an integer.\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        char newLine;
        scanf("%c", &newLine);

        if (option == 0)
            break;
        else if (option == 1)
            display_all_movies_of_genre_ui();
        else if (option == 2)
            delete_movie_from_watchlist_ui();
        else if (option == 3)
            display_watchlist_ui();
        else
            printf("Invalid input.");
    }
}

static void print_administrator_options()
{
    printf("\nChoose the option:\n");
    printf("1. Add a movie.\n");
    printf("2. Delete a movie.\n");
    printf("3. Update movie.\n");
    printf("4. Display all movies.\n");
    printf("0. Exit administrator mode.\n");
}

void Console::administrator_menu()
/*
* Displays the administrator menu, which allows the user to add ten movies, add a movie,
 * delete a movie, update a movie, display all movies, or exit the program.
*/
{
    while (true)
    {
        print_administrator_options();

        int option = -1;

        while (true) {

            printf(">");

            if (scanf("%d", &option) == 1)
                break;

            printf("The option should be an integer.\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        char newLine;
        scanf("%c", &newLine);

        if (option == 0)
            break;
        else if (option == 1)
            add_movie_ui();
        else if (option == 2)
            delete_movie_ui();
        else if (option == 3)
            update_movie_ui();
        else if (option == 4)
            display_all_movies_ui();
        else
            printf("Invalid input.");
    }
}


void Console::menu()
/*
* Runs the console by displaying the administrator menu and handling user input until the user chooses to exit.
*/
{
    add_10_random_movies();

    while (true)
    {
        printf("\nHow you want to open the program?\n");
        printf("1. Administrator mode.\n");
        printf("2. User mode.\n");
        printf("0. Exit the program.\n");
        printf(">");

        int option = -1;

        int readStatus = scanf("%d", &option);

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        if (readStatus == 1)
        {
            if (option == 0)
                break;
            else if (option == 1)
                administrator_menu();
            else if (option == 2)
                user_menu();
        }
        else
        {
            printf("The mode should be an integer (either 1 or 2).\n");
        }
    }
}
