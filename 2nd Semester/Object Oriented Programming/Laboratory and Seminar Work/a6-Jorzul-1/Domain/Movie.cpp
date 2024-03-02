//
// Created by User on 5/4/2023.
//

#include "Movie.h"

Movie::Movie()
/*
* Default constructor that initializes a movie with empty strings and zero values for the year and likes.
*/
{
    strcpy(_title, "");
    strcpy(_genre, "");
    _year = 0;
    _likes = 0;
    strcpy(_trailer, "");
}

Movie::Movie(const char title[], const char genre[], unsigned int year, unsigned int likes, const char trailer[])
/*
* Constructor that initializes a movie with the given parameters.
*
* parameters: title: The title of the movie, genre: The genre of the movie, year: The year of the release of the movie,
*              likes: The number of likes of the movie, trailer: The link to the movie trailer.
*/
{
    strcpy(_title, title);
    strcpy(_genre, genre);
    _year = year;
    _likes = likes;
    strcpy(_trailer, trailer);
}

char* Movie::get_title()
/*
* Returns a pointer to the title of the movie.
*
* return: A pointer to the title of the movie.
*/
{
    return _title;
}

char* Movie::get_genre()
/*
* Returns a pointer to the genre of the movie.
*
* return: A pointer to the genre of the movie.
*/
{
    return _genre;
}

unsigned int Movie::get_year() const
/*
* Returns the year the movie was released.
*
* return: An unsigned integer representing the year the movie was released.
*/
{
    return _year;
}

unsigned int Movie::get_likes() const
/*
* Returns the number of likes the movie has.
*
* return: An unsigned integer representing the number of likes the movie has.
*/
{
    return _likes;
}

char* Movie::get_trailer()
/*
* Returns a pointer to the URL of the movie's trailer.
*
* @return A pointer to the URL of the movie's trailer.
*/
{
    return _trailer;
}

Movie::~Movie()
= default;
/*
* Destructor that cleans up any dynamically allocated memory.
*/
