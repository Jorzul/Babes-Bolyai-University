#include "Console.h"

#include<stdio.h>
#include<string.h>
#include <windows.h>
#include <shellapi.h>

Console::Console(Service &movieService, Service& watchListService)
{
	_movieService = &movieService;
	_watchListService = &watchListService;
}

Console::~Console()
{

}

static bool YearIsValid(int year)
{
	if (year < 0)
		return false;
	return true;
}

static bool LikesAreValid(int likes)
{
	if (likes < 0)
		return false;
	return true;
}

static void RemoveLastCharacter(char* str)
{
	// Only removing the last character if there is at least one character and it is '\n'. 
	if (strlen(str) > 0 && str[strlen(str) - 1] == '\n')
		str[strlen(str) - 1] = '\0';
}

static void PrintAdministratorOptions()
{
	printf("\nChoose one of the following options :\n");
	printf("0. Exit administrator mode.\n");
	printf("1. Add a movie.\n");
	printf("2. Delete a movie.\n");
	printf("3. Update movie.\n");
	printf("4. Display all movies.\n");
}

static void PrintUserOptions()
{
	printf("\nChoose one of the following options :\n");
	printf("0. Exit user mode.\n");
	printf("1. Display all movies of genre.\n");
	printf("2. Delete movie from watch list.\n");
	printf("3. Display the watch list.\n");
}


void Console::AddTenMovies()
{
	_movieService->AddMovie("Harry Potter", "SF", 2005, 214151, "https://www.youtube.com/watch?v=fFGS4zZWGoA&ab_channel=HBOMax");
	_movieService->AddMovie("Pirates of the Caribbean", "Action", 2016, 5361, "https://www.youtube.com/watch?v=Hgeu5rhoxxY&ab_channel=WaltDisneyStudios");
	_movieService->AddMovie("Lord of the Rings", "Adventure", 2002, 31362, "https://www.youtube.com/watch?v=x8UAUAuKNcU&ab_channel=PrimeVideo");
	_movieService->AddMovie("The Hobbit", "Adeventure", 2008, 532632, "https://www.youtube.com/watch?v=SDnYMbYB-nU&ab_channel=WarnerBros.Pictures");
}

void Console::AddMovie()
{
	// Printing a guiding message.
	printf("Adding a movie. Please specify the following :\n");

	// Declaring the Movie data.
	char title[101];
	char genre[101];
	int year;
	int likes;
	char trailer[101];

	// Reading the title.
	printf("Title : ");
	fgets(title, 100, stdin);

	// Removing the '\n'.
	RemoveLastCharacter(title);

	// Reading the genre.
	printf("Genre : ");
	fgets(genre, 100, stdin);

	// Removing the '\n'.
	RemoveLastCharacter(genre);



	// Reading the year.
	printf("Year : ");
	int yearReadStatus = scanf("%d", &year);

	// Consume and discard the invalid input.
	int c;
	while ((c = getchar()) != '\n' && c != EOF);

	// If the value read was not a float we print a guiding message.
	if (yearReadStatus != 1)
	{
		printf("The year should be an unsigned integer number.");
		return;
	}

	// Checking if the year is a negative number.
	if (!YearIsValid(year))
	{
		printf("The year cannot be a negative number.");
		return;
	}

	// Reading the likes.
	printf("Likes : ");
	int likesReadStatus = scanf("%d", &likes);

	// Consume and discard the invalid input.
	while ((c = getchar()) != '\n' && c != EOF);

	// If the value read was not an unsigned integer we print a guiding message.
	if (likesReadStatus != 1)
	{
		printf("The likes should be an unsigned integer number.");
		return;
	}

	// Checking if the number of likes is negative.
	if (!LikesAreValid(likes))
	{
		printf("The number of likes cannot be negative.");
		return;
	}


	// Reading the trailer.
	printf("Trailer : ");
	fgets(trailer, 100, stdin);

	// Removing the '\n'.
	RemoveLastCharacter(trailer);

	if (_movieService->AddMovie(title, genre, year, likes, trailer) == 1)
		printf("Movie added.\n");
	else printf("There is another movie with the same title. Operation canceled.\n");
}

void Console::DeleteMovie()
{
	// Printing a guiding message.
	printf("Deleting a movie. Please specify the following :\n");

	// Declaring the Movie data.
	char title[101];

	// Reading the title.
	printf("Title : ");
	fgets(title, 100, stdin);

	// Removing the '\n'.
	RemoveLastCharacter(title);

	if (_movieService->DeleteMovie(title) == 1)
		printf("Movie deleted.\n");
	else printf("There is no movie with the given title. Operation canceled.\n");
}

void Console::UpdateMovie()
{
	// Printing a guiding message.
	printf("Updating a movie. Please specify the following :\n");

	// Declaring the Movie data.
	char oldTitle[101];
	char newTitle[101];
	char newGenre[101];
	int newYear;
	int newLikes;
	char newTrailer[101];

	// Reading the title.
	printf("Old Title : ");
	fgets(oldTitle, 100, stdin);

	// Removing the '\n'.
	RemoveLastCharacter(oldTitle);

	// Reading the title.
	printf("New Title : ");
	fgets(newTitle, 100, stdin);

	// Removing the '\n'.
	RemoveLastCharacter(newTitle);

	// Reading the genre.
	printf("New Genre : ");
	fgets(newGenre, 100, stdin);

	// Removing the '\n'.
	RemoveLastCharacter(newGenre);



	// Reading the year.
	printf("New Year : ");
	int yearReadStatus = scanf("%d", &newYear);

	// Consume and discard the invalid input.
	int c;
	while ((c = getchar()) != '\n' && c != EOF);

	// If the value read was not a float we print a guiding message.
	if (yearReadStatus != 1)
	{
		printf("The year should be an unsigned integer number.");
		return;
	}

	// Checking if the year is a negative number.
	if (!YearIsValid(newYear))
	{
		printf("The year cannot be a negative number.");
		return;
	}

	// Reading the likes.
	printf("New Likes : ");
	int likesReadStatus = scanf("%d", &newLikes);

	// Consume and discard the invalid input.
	while ((c = getchar()) != '\n' && c != EOF);

	// If the value read was not an unsigned integer we print a guiding message.
	if (likesReadStatus != 1)
	{
		printf("The likes should be an unsigned integer number.");
		return;
	}

	// Checking if the number of likes is negative.
	if (!LikesAreValid(newLikes))
	{
		printf("The number of likes cannot be negative.");
		return;
	}

	// Reading the trailer.
	printf("New Trailer : ");
	fgets(newTrailer, 100, stdin);

	// Removing the '\n'.
	RemoveLastCharacter(newTrailer);

	if (_movieService->UpdateMovie(oldTitle, newTitle, newGenre, newYear, newLikes, newTrailer) == 1)
		printf("Movie updated.\n");
	else printf("There is no movie with the given old title. Operation canceled.\n");
}

void Console::DisplayAllMovies()
{
	// Printing a guiding message.
	printf("Displaying all the movies :\n");

	// Getting the list of all movies.
	int size = -1;
	Movie* allMovies = _movieService->GetAllMovies(size);
	
	// Informing the admin if there are no movies added yet.
	if (size == 0)
	{
		printf("No movies yet.\n");
		
		// Returning out of the function.
		return;
	}

	// Printing each movie one by one.
	for (int i = 0; i < size; i++)
		printf("%d. Title: %s ; Genre : %s ; Year : %u ; Likes : %u ; Trailer : %s\n",
			(i+1), allMovies[i].GetTitle(), allMovies[i].GetGenre(), allMovies[i].GetYear(), allMovies[i].GetLikes(), allMovies[i].GetTrailer());
}

void Console::DisplayAllMoviesOfGenre()
{
	// Printing a guiding message.
	printf("Displaying all the movies :\n");

	// Declaring the Movie data.
	char genre[101];

	// Reading the title.
	printf("Genre : ");
	fgets(genre, 100, stdin);

	// Removing the '\n'.
	RemoveLastCharacter(genre);

	// Getting the list of all movies.
	int size = -1;
	Movie* allMovies = _movieService->GetAllMoviesOfGenre(genre, size);

	// Informing the user if there are no movies added yet.
	if (size == 0)
	{
		printf("No movies yet.\n");
		// Freeing the memory allocated to the {allMovies} array.
		free(allMovies);
		
		// Returning out of the function.
		return;
	}

	// Printing each movie one by one.
	int currentIndex = 0;
	bool watchNextMovie = true;
	
	// Initialize a character to store the invalid characters and '\n'.
	char c;
	while (watchNextMovie)
	{
		// Priniting the current movie details.
		printf("%d. Title: %s ; Genre : %s ; Year : %u ; Likes : %u\n",
			(currentIndex + 1), allMovies[currentIndex].GetTitle(), allMovies[currentIndex].GetGenre(), allMovies[currentIndex].GetYear(), allMovies[currentIndex].GetLikes());

		// Oppening the trailer in the browser.
		ShellExecuteA(NULL, "open", allMovies[currentIndex].GetTrailer(), NULL, NULL, SW_SHOWNORMAL);

		printf("Do you want to add the movie to the watch list? (y/n)");
		while (1)
		{
			// Reading the user's response.
			char response;
			scanf("%c", &response);

			// Consume and discard the invalid input.
			while ((c = getchar()) != '\n' && c != EOF);

			if (response == 'y')
			{
				if (_watchListService->AddMovie(allMovies[currentIndex].GetTitle(), allMovies[currentIndex].GetGenre(), allMovies[currentIndex].GetYear(), allMovies[currentIndex].GetLikes(), allMovies[currentIndex].GetTrailer()) == 1)
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
		while (1)
		{
			// Reading the user's response.
			char response;
			scanf("%c", &response);

			// Consume and discard the invalid input.
			while ((c = getchar()) != '\n' && c != EOF);

			if (response == 'y')
			{
				currentIndex = (currentIndex + 1) % size;
				break;
			}
			else if (response == 'n')
			{
				watchNextMovie = false;
				break;
			}
			else
				printf("Only y / n allowed.");
		}

		printf("\n");
	}

	// Freeing the memory allocated to the {allMovies} array.
	free(allMovies);
}

void Console::DeleteMovieFromWatchList()
{
	// Printing a guiding message.
	printf("Deleting a movie from the watch list. Please specify the following :\n");

	// Declaring the Movie data.
	char title[101];

	// Reading the title.
	printf("Title : ");
	fgets(title, 101, stdin);

	// Removing the '\n'.
	RemoveLastCharacter(title);

	if (_watchListService->DeleteMovie(title) == 1) {
        printf("Movie deleted.\n");

    }
	else printf("There is no movie with the given title in the watch list. Operation canceled.\n");
}

void Console::DisplayWatchList()
{
	// Printing a guiding message.
	printf("Displaying the watch list :\n");

	// Getting the list of all movies.
	int size = -1;
	Movie* allMovies = _watchListService->GetAllMovies(size);

	// Informing the admin if there are no movies added yet.
	if (size == 0)
		printf("No movies added to the watch list yet.\n");

	// Printing each movie one by one.
	for (int i = 0; i < size; i++)
		printf("%d. Title: %s ; Genre : %s ; Year : %u ; Likes : %u ; Trailer : %s\n",
			(i + 1), allMovies[i].GetTitle(), allMovies[i].GetGenre(), allMovies[i].GetYear(), allMovies[i].GetLikes(), allMovies[i].GetTrailer());
}

void Console::RunUserMenu()
{
	// Looping until the user exists the program.
	while (1)
	{
		// Printing the user options.
		PrintUserOptions();

		// Initializing the user option as -1.
		int option = -1;

		// Looping until we read a valid integer.
		while (1) {

			// Print a guiding message.
			printf("Option : ");

			// If the reading is done correctly we break out of the loop.
			if (scanf("%d", &option) == 1)
				break;

			// In case we didn't read an integer we print a guiding message.
			printf("The option should be an integer.\n");

			// Consume and discard the invalid input.
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
		}

		// Reading the '\n' after the int.
		char newLine;
		scanf("%c", &newLine);

		// Calling the corresponding method based on the option.
		if (option == 0)
			break;
		else if (option == 1)
			DisplayAllMoviesOfGenre();
		else if (option == 2)
			DeleteMovieFromWatchList();
		else if (option == 3)
			DisplayWatchList();
		else
			printf("Invalid input.");
	}
}

void Console::RunAdministratorMenu()
{
	// Looping until the user exists the program.
	while (1)
	{
		// Printing the administrator options.
		PrintAdministratorOptions();
		
		// Initializing the user option as -1.
		int option = -1;

		// Looping until we read a valid integer.
		while (1) {

			// Print a guiding message.
			printf("Option : ");

			// If the reading is done correctly we break out of the loop.
			if (scanf("%d", &option) == 1)
				break;

			// In case we didn't read an integer we print a guiding message.
			printf("The option should be an integer.\n");

			// Consume and discard the invalid input.
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
		}

		// Reading the '\n' after the int.
		char newLine;
		scanf("%c", &newLine);

		// Calling the corresponding method based on the option.
		if (option == 0)
			break;
		else if (option == 1)
			AddMovie();
		else if (option == 2)
			DeleteMovie();
		else if (option == 3)
			UpdateMovie();
		else if (option == 4)
			DisplayAllMovies();
		else
			printf("Invalid input.");
	}
}

// Run User Menu

void Console::RunConsole()
{
	// Adding 10 entries at the start of the program.
	AddTenMovies();

	// Printing a starting message.
	printf("-----------------> Local Movie Database <-----------------");

	// Looping while we read a valid mode.
	while (1)
	{
		// Print a guiding message.
		printf("\nPlease choose from the following :\n");
		printf("0. Exit application.\n");
		printf("1. Administrator.\n");
		printf("2. User.\n");
		printf("Option : ");

		// Initializing the option as -1.
		int option = -1;

		// Reading the option from the console.
		int readStatus = scanf("%d", &option);

		// Consume and discard the invalid input.
		int c;
		while ((c = getchar()) != '\n' && c != EOF);

		// If the reading was done correctly.
		if (readStatus == 1)
		{
			if (option == 0)
				break;
			else if (option == 1)
				RunAdministratorMenu();
			else if (option == 2)
				RunUserMenu();
		}
		else
		{
			// In case we didn't read an integer we print a guiding message.
			printf("The mode should be an integer (either 1 or 2).\n");
		}
	}
}