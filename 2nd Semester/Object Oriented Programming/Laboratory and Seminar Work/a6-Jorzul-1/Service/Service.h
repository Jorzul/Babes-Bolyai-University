//
// Created by User on 5/4/2023.
//

#ifndef A6_JORZUL_1_SERVICE_H
#define A6_JORZUL_1_SERVICE_H

#ifndef SERVICE_H
#define SERVICE_H

#include "../Repository/Repository.h"

class Service {
private:
    Repository* _repository;

public:
    explicit Service(Repository& movieRepository);

    ~Service();

    int add_movie(const char title[], const char genre[], unsigned int year, unsigned int likes, const char trailer[]);

    int delete_movie(char title[]);

    int update_movie(char title[], char newTitle[], char newGenre[], unsigned int newYear, unsigned int newLikes, char newTrailer[]);

    Movie* get_all_movies(int& size);

    Movie* get_all_movies_of_genres(char genre[], int& size);
};

#endif


#endif //A6_JORZUL_1_SERVICE_H
