#include "Service.h"

Service::Service(Repository& repository)
{
	_repository = &repository;
}

Service::~Service()
{

}

int Service::AddMovie(const char title[], const char genre[], unsigned int year, unsigned int likes, const char trailer[])
{
	// Getting all the movies and checking whether the movie exists or not.
	int size = -1;
	Movie* allMovies = GetAllMovies(size);

	// Searching for the title and returning 0 in case we find it.
	for (int i = 0; i < size; i++)
		if (strcmp(allMovies[i].GetTitle(), title) == 0)
			return 0;

	// Creating the movie object.
	Movie movieToAdd(title, genre, year, likes, trailer);

	// Calling the corresponding method to add the entity.
	_repository->AddEntity(movieToAdd);

	// Returning 1.
	return 1;
}

int Service::DeleteMovie(char title[])
{
	// Getting all the movies and checking whether the movie exists or not.
	int size = -1;
	Movie* allMovies = GetAllMovies(size);

	// Searching for the title and returning 0 in case we find it.
	for (int i = 0; i < size; i++)
	{
		// Skipping the movies that do not match our title.
		if (strcmp(allMovies[i].GetTitle(), title) != 0) continue;

		// Calling the repository method to delete the entity at index {i}.
		_repository->DeleteEntityAt(i);

		// Returning 1, meaning the operation was performed succesfully.
		return 1;
	}
	
	// Returning 0 In case we didn't find the target movie.
	return 0;
}

int Service::UpdateMovie(char title[], char newTitle[], char newGenre[], unsigned int newYear, unsigned int newLikes, char newTrailer[])
{
	// Getting all the movies and checking whether the movie exists or not.
	int size = -1;
	Movie* allMovies = GetAllMovies(size);
	
	// Searching for the title and returning 0 in case we find it.
	for (int i = 0; i < size; i++)
	{
		// Skipping the movies that do not match our title.
		if (strcmp(allMovies[i].GetTitle(), title) != 0) continue;

		// Creating the movie object.
		Movie newMovie{ newTitle, newGenre, newYear, newLikes, newTrailer };

		// Calling the repository method to update the entity at index {i}.
		_repository->UpdateEntityAt(i, newMovie);

		// Returning 1, meaning the operation was performed succesfully.
		return 1;
	}

	// Returning 0 In case we didn't find the target movie.
	return 0;
}

Movie* Service::GetAllMovies(int& size)
{
	size = _repository->GetSize();
	return _repository->GetAllEntities();
}

Movie* Service::GetAllMoviesOfGenre(char genre[], int &size)
{
	int initialSize = _repository->GetSize();
	Movie* allMovies = _repository->GetAllEntities();

	// Initially we consider that no elements ahve the same genre as the given one.
	size = 0;

	// Counting the number of movies that have the same genre as the given one.
	for (int i = 0; i < initialSize; i++)
		if (strcmp(allMovies[i].GetGenre(), genre) == 0 || strcmp("", genre) == 0) 
			size++;

	// Allocating memory to a new area.
	Movie* allMoviesOfGenre = (Movie*)(malloc(size * sizeof(Movie)));

	// Initializing the current index.
	int currentIndex = 0;

	// Going through all the movies.
	for (int i = 0; i < initialSize; i++)
	{
		// Adding the movies that have the same genre as the given one to the array.
		if (strcmp(allMovies[i].GetGenre(), genre) == 0 || strcmp("", genre) == 0)
			allMoviesOfGenre[currentIndex++] = allMovies[i];
	}

	// Returning the array of all movies of a given genre.
	return allMoviesOfGenre;
}