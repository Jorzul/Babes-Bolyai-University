//
// Created by User on 5/4/2023.
//

#ifndef A6_JORZUL_1_MOVIE_H
#define A6_JORZUL_1_MOVIE_H

#ifndef MOVIE_H
#define MOVIE_H

#include <cstring>

class Movie {
private:
    char _title[101]{};
    char _genre[101]{};
    unsigned int _year;
    unsigned int _likes;
    char _trailer[101]{};

public:
    Movie();

    Movie(const char title[], const char genre[], unsigned int year, unsigned int likes, const char trailer[]);

    char* get_title();

    char* get_genre();

    unsigned int get_year() const;

    unsigned int get_likes() const;

    char* get_trailer();

    ~Movie();
};

#endif


#endif //A6_JORZUL_1_MOVIE_H
