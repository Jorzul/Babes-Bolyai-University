//
// Created by User on 5/4/2023.
//

#include "test.h"
#include "../Domain/Movie.h"
#include "../Repository/Repository.h"
#include "../Service/Service.h"
#include <cassert>

void Test_Domain()
{
    char title[50] = "Titanic";
    char genre[50] = "Drama";
    int year = 2016;
    int likes = 1000;
    char trailer[100] = "www.youtube.com";

    Movie movie(title, genre, year, likes, trailer);

    Movie movie1;

    assert(strcmp(movie.get_title(), "Titanic") == 0);
    assert(strcmp(movie.get_genre(), "Drama") == 0);
    assert(movie.get_likes() == 1000);
    assert(movie.get_year() == 2016);
    assert(strcmp(movie.get_trailer(), "www.youtube.com") == 0);
}

void Test_Repository()
{
    Repository movie_repo;
    assert(movie_repo.get_size() == 0);

    char title[50] = "Titanic";
    char genre[50] = "Drama";
    int year = 2016;
    int likes = 1000;
    char trailer[100] = "www.youtube.com";

    Movie movie(title, genre, year, likes, trailer);

    movie_repo.add_entity(movie);
    assert(movie_repo.get_size() == 1);

    movie_repo.delete_entity_at(0);
    assert(movie_repo.get_size() == 0);

    char title2[50] = "Titanic";
    Movie movie1(title2, genre, year, likes, trailer);
    movie_repo.add_entity(movie);

    movie_repo.update_entity_at(0, movie1);
    assert(movie_repo.get_all_entities()[0].get_likes() == likes);
}

void Test_Service()
{
    Repository movie_repo;
    Service movie_service(movie_repo);

    char title[50] = "Titanic";
    char genre[50] = "Drama";
    int year = 2016;
    int likes = 1000;
    char trailer[100] = "www.youtube.com";

    assert(movie_service.add_movie(title, genre, year, likes, trailer) == 1);
    assert(movie_service.add_movie(title, genre, year, likes, trailer) == 0);

    assert(movie_service.delete_movie(title) == 1);
    assert(movie_service.delete_movie(title) == 0);

    assert(movie_service.add_movie(title, genre, year, likes, trailer) == 1);
    char title2[50] = "Titanic 2";
    assert(movie_service.update_movie(title, title2, genre, year, likes, trailer) == 1);
    assert(movie_service.update_movie(title, title2, genre, year, likes, trailer) == 0);

    int size = -1;
    assert(movie_service.get_all_movies(size)[0].get_likes() == likes);
    assert(size == 1);

    assert(movie_service.get_all_movies_of_genres(genre, size)[0].get_likes() == likes);
    
}

void TestAll()
{
    Test_Domain();
    Test_Repository();
    Test_Service();
}