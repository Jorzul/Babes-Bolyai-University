#include "Movie.h"
#include <stdio.h>

Movie::Movie()
{
	strcpy(_title, "");
	strcpy(_genre, "");
	_year = 0;
	_likes = 0;
	strcpy(_trailer, "");
}

Movie::Movie(const char title[], const char genre[], unsigned int year, unsigned int likes, const char trailer[])
{
	strcpy(_title, title);
	strcpy(_genre, genre);
	_year = year;
	_likes = likes;
	strcpy(_trailer, trailer);
}

char* Movie::GetTitle()
{
	return _title;
}

char* Movie::GetGenre()
{
	return _genre;
}

unsigned int Movie::GetYear()
{
	return _year;
}

unsigned int Movie::GetLikes()
{
	return _likes;
}

char* Movie::GetTrailer()
{
	return _trailer;
}
void Movie::SetTitle(const char title[])
{
	strcpy(_title, title);
}

void Movie::SetGenre(const char genre[])
{
	strcpy(_genre, genre);
}

void Movie::SetYear(unsigned int year)
{
	_year = year;
}

void Movie::SetLikes(unsigned int likes) 
{
	_likes = likes;
}

void Movie::SetTrailer(const char trailer[])
{
	strcpy(_trailer, trailer);
}
Movie::~Movie()
{
	
}