//
// Created by User on 5/17/2023.
//

#include "UI.h"
#include <iostream>
#include <string>
#include "Exceptions.h"
#include "CSVWatchList.h"
#include "HTMLWatchList.h"
#include "FileRepository.h"

using namespace std;

using namespace OPTIONS;

UI::UI()
{
    this->service = Service();
    this->service.setTypeOfRepository(new FileRepository{STORAGE_TYPE::STORAGE_FILE_NAME});
    this->choose_watchlist_filetype();
}

void UI::choose_watchlist_filetype()
{
    while (true)
    {
        cout << "How do you wish to open the file?\n";
        cout << "1. CSV\n";
        cout << "2. HTML\n";
        cout << ">";
        string choice;
        cin >> choice;
        if (choice == "1")
        {
            this->service.setTypeOfWatchList(new CSVWatchList{"CSVWatchList.csv"});
            return;
        }
        else if (choice == "2")
        {
            this->service.setTypeOfWatchList(new HTMLWatchList{"HTMLWatchList.html"});
            return;
        }
        else
            cout << "Invalid.\n";
    }
}

void UI::print_admin_user_menu()
{
    cout << "How do you want to proceed?\n";
    cout << "1. Admin\n";
    cout << "2. User\n";
    cout << "3. Exit\n";
    cout << ">";
}

void UI::print_admin_menu()
{
    cout << "This is the Admin Menu:\n";
    cout << "1. Add movie\n";
    cout << "2. Remove movie\n";
    cout << "3. Update movie\n";
    cout << "4. Print all movies\n";
    cout << "5. Switch to user menu\n";
    cout << "6. Exit\n";
}

void UI::print_user_menu()
{
    std::cout << "This is the User Menu:\n";
    std::cout << "1. Get movies by genre\n";
    std::cout << "2. Display watchlist\n";
    std::cout << "3. Delete a movie from the watchlist\n";
    std::cout << "4. Switch to admin menu\n";
    std::cout << "5. Exit\n";
}

void UI::print_all_movies()
{
    std::vector<Movie> movies = this->service.getMovies();
    std::vector<Movie>::iterator iteratorUsedForPrintingMovies = movies.begin();
    for (; iteratorUsedForPrintingMovies != movies.end(); ++iteratorUsedForPrintingMovies)
    {
        Movie currentMovie = *iteratorUsedForPrintingMovies;
        std::cout << std::distance(movies.begin(), iteratorUsedForPrintingMovies) << ". " << currentMovie << "\n";
    }
}

void UI::admin_add_movie()
{
    std::cout << "Enter the movie.\nThe format is: title | genre | year of release | trailer | likesCount\n";
    std::cin.ignore();
    Movie movieToAdd;
    try
    {
        std::cin >> movieToAdd;
    }
    catch (MovieExceptions &errorsCaught)
    {
        std::cout << "There were some errors, try again!\n";
        for (const auto &errorCaught : errorsCaught.returnErrors())
            std::cout << errorCaught.what() << "\n";
        return;
    }
    try
    {
        this->service.addMovie(movieToAdd);
    }
    catch (DuplicateMovieException &caughtException)
    {
        std::cout << caughtException.what() << "\n";
        return;
    }
    catch (RepositoryException &caughtException)
    {
        std::cout << caughtException.what() << "\n";
        return;
    }
}

void UI::admin_remove_movie()
{
    this->print_all_movies();
    int positionOfMovie;
    std::cout << "Position of the movie you want to remove: ";
    std::cin >> positionOfMovie;
    try
    {
        this->service.removeMovieByPosition(positionOfMovie);
    }
    catch (RepositoryException &caughtException)
    {
        std::cout << caughtException.what() << "\n";
        return;
    }
}

void UI::admin_update_movie()
{
    this->print_all_movies();
    int positionOfMovie;
    std::cout << "Position of the movie you want to update: ";
    std::cin >> positionOfMovie;
    std::cin.ignore();

    Movie movieToBeUpdated;
    try
    {
        movieToBeUpdated = this->service.getMovieByPosition(positionOfMovie);
    }
    catch (InvalidPositionException &caughtException)
    {
        std::cout << caughtException.what() << "\n";
        return;
    }

    std::string titleOfMovieToBeUpdated = movieToBeUpdated.getTitle(),
            genreOfMovieToBeUpdated = movieToBeUpdated.getGenre(),
            trailerOfMovieToBeUpdated = movieToBeUpdated.getTrailer(),
            yearOfRelease = std::to_string(movieToBeUpdated.getYearOfRelease()),
            likesCount = std::to_string(movieToBeUpdated.getLikesCount()),
            readInput;

    std::cout << "Title: ";
    std::getline(std::cin, readInput); // read the newline character
    if (readInput != "")
        titleOfMovieToBeUpdated = readInput;

    std::cout << "Genre: ";
    std::getline(std::cin, readInput); // read the newline character
    if (readInput != "")
        genreOfMovieToBeUpdated = readInput;

    std::cout << "Trailer: ";
    std::getline(std::cin, readInput); // read the newline character
    if (readInput != "")
        trailerOfMovieToBeUpdated = readInput;

    std::cout << "Year of release: ";
    std::getline(std::cin, readInput); // read the newline character
    if (readInput != "")
        yearOfRelease = readInput;

    std::cout << "Likes: ";
    std::getline(std::cin, readInput); // read the newline character
    if (readInput != "")
        likesCount = readInput;

    Movie updatedMovie;
    try
    {
        MovieValidator::validateMovieIdentifiers(titleOfMovieToBeUpdated, genreOfMovieToBeUpdated, yearOfRelease, trailerOfMovieToBeUpdated, likesCount);
        updatedMovie.setTitle(titleOfMovieToBeUpdated);
        updatedMovie.setGenre(genreOfMovieToBeUpdated);
        updatedMovie.setYearOfRelease(std::stoi(yearOfRelease));
        updatedMovie.setTrailer(trailerOfMovieToBeUpdated);
        updatedMovie.setLikesCount(std::stoi(likesCount));
    }
    catch (MovieExceptions &errorsCaught)
    {
        std::cout << "There were some errors regarding user input, try again!\n";
        for (const auto &errorCaught : errorsCaught.returnErrors())
            std::cout << errorCaught.what() << "\n";
        return;
    }

    try
    {
        this->service.updateMovie(positionOfMovie, updatedMovie);
    }
    catch (InvalidPositionException &caughtException)
    {
        std::cout << caughtException.what() << "\n";
        return;
    }
    catch (DuplicateMovieException &caughtException)
    {
        std::cout << caughtException.what() << "\n";
        return;
    }
}

void UI::user_get_movies_by_genre()
{
    std::string genre;
    std::cin.ignore();
    std::cout << "Please enter the genre of the movies you want to see: ";
    std::getline(std::cin, genre);

    std::vector<Movie> moviesWithGivenGenre = this->service.getMoviesByGenre(genre);
    if (moviesWithGivenGenre.size() == 0)
    {
        std::cout << "There are no movies with the given genre!\n";
        return;
    }
    bool checkIfThereAreMoreMovies = true;
    while (checkIfThereAreMoreMovies)
    {
        checkIfThereAreMoreMovies = false;
        for (auto movie : moviesWithGivenGenre)
        {
            try
            {
                this->service.checkIfMovieIsAlreadyInThePlaylist(movie);
                checkIfThereAreMoreMovies = true;
                std::cout << "Title: " << movie.getTitle() << "\n";
                std::cout << "Genre: " << movie.getGenre() << "\n";
                std::cout << "Year of Release: " << movie.getYearOfRelease() << "\n";
                std::cout << "Likes Count: " << movie.getLikesCount() << "\n";
                movie.openTrailerInBrowser();
                std::cout << "Do you want to add this movie to your wishlist? (y/n): ";
                char choiceOfUser;
                std::cin >> choiceOfUser;
                choiceOfUser = std::tolower(choiceOfUser);
                if (choiceOfUser == 'y')
                    this->service.addMovieToWatchList(movie);
                else
                    std::cout << "Movie not added to your wishlist!\n";
                std::cout << "Do you want to see the next movie? (y/n): ";
                std::cin >> choiceOfUser;
                if (choiceOfUser == 'n')
                {
                    return;
                }
            }
            catch (DuplicateMovieException &caughtException)
            {
            }
        }
    }
}

void UI::user_display_movies_from_watchlist()
{
    try
    {
        this->service.displayPlaylist();
    }
    catch (FileException &caughtException)
    {
        std::cerr << caughtException.what() << '\n';
    }
}

void UI::user_delete_movies_from_watchlist()
{
    this->user_display_movies_from_watchlist();
    std::vector<Movie> moviesFromWatchList = this->service.getMoviesFromWatchList();
    if (moviesFromWatchList.size() == 0)
        return;
    int positionOfMovieToBeDeleted;
    std::cout << "Please enter the position of the movie you want to delete from your watchlist: ";
    std::cin >> positionOfMovieToBeDeleted;
    std::cout << "Did you like the movie? (y/n): ";
    char choiceOfUser;
    std::cin >> choiceOfUser;
    choiceOfUser = tolower(choiceOfUser);
    if (choiceOfUser == 'y')
    {
        try
        {
            this->service.increaseLikesCountOfMovie(moviesFromWatchList[positionOfMovieToBeDeleted]);
            std::cout << "Likes count increased successfully!\n";
        }
        catch (const std::exception &e)
        {
            std::cout << "Invalid position!\n";
            return;
        }
    }
    this->service.removeWatchedMovieFromWatchList(positionOfMovieToBeDeleted);
    std::cout << "Movie deleted successfully!\n";
}

void UI::runApp()
{
    this->print_admin_user_menu();
    std::string choice;
    std::cin >> choice;
    if (choice == INTERFACE::ADMIN)
        this->service.setAdminMode(true);
    else if (choice == INTERFACE::USER)
        this->service.setAdminMode(false);
    else if (choice == EXIT_APPLICATION)
    {
        return;
    }
    while (true)
    {
        if (this->service.AdminMode())
        {
            this->print_admin_menu();
            std::cout << "Please enter your choice: ";
            std::cin >> choice;
            if (choice == ADMIN::ADD_MOVIE)
                this->admin_add_movie();
            else if (choice == ADMIN::REMOVE_MOVIE)
                this->admin_remove_movie();
            else if (choice == ADMIN::UPDATE_MOVIE)
                this->admin_update_movie();
            else if (choice == ADMIN::PRINT_ALL_MOVIES)
                this->print_all_movies();
            else if (choice == ADMIN::SWITCH_TO_USER_INTERFACE)
                this->service.setAdminMode(false);
            else if (choice == ADMIN::EXIT)
                break;
        }
        else
        {
            this->print_user_menu();
            std::cout << "Please enter your choice: ";
            std::cin >> choice;
            if (choice == "1")
                this->user_get_movies_by_genre();
            else if (choice == "2")
                this->user_display_movies_from_watchlist();
            else if (choice == "3")
                this->user_delete_movies_from_watchlist();
            else if (choice == "4")
                this->service.setAdminMode(true);
            else if (choice == "5")
                break;
        }
    }
}
