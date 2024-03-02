#ifndef MOVIE_H
#define MOVIE_H

#include <string.h>

class Movie {
private:
    char _title[101];
    char _genre[101];
    unsigned int _year;
    unsigned int _likes;
    char _trailer[101];

public:
    /**
     * Default constructor that initializes a movie with empty strings and zero values for the year and likes.
     */
    Movie();

    /**
     * Constructor that initializes a movie with the given parameters.
     *
     * @param title The title of the movie.
     * @param genre The genre of the movie.
     * @param year The year the movie was released.
     * @param likes The number of likes the movie has.
     * @param trailer The URL of the movie's trailer.
     */
    Movie(const char title[], const char genre[], unsigned int year, unsigned int likes, const char trailer[]);

    /**
     * Returns a pointer to the title of the movie.
     *
     * @return A pointer to the title of the movie.
     */
    char* GetTitle();

    /**
     * Returns a pointer to the genre of the movie.
     *
     * @return A pointer to the genre of the movie.
     */
    char* GetGenre();

    /**
     * Returns the year the movie was released.
     *
     * @return An unsigned integer representing the year the movie was released.
     */
    unsigned int GetYear();

    /**
     * Returns the number of likes the movie has.
     *
     * @return An unsigned integer representing the number of likes the movie has.
     */
    unsigned int GetLikes();

    /**
     * Returns a pointer to the URL of the movie's trailer.
     *
     * @return A pointer to the URL of the movie's trailer.
     */
    char* GetTrailer();

    /**
     * Destructor that cleans up any dynamically allocated memory.
     */

    void SetTitle(const char title[]);

    void SetGenre(const char genre[]);

    void SetYear(unsigned int year);

    void SetLikes(unsigned int likes);

    void SetTrailer(const char trailer[]);

    ~Movie();
};

#endif
