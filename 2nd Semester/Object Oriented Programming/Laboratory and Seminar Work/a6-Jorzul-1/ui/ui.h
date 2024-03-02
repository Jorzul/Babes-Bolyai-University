//
// Created by User on 5/4/2023.
//

#ifndef A6_JORZUL_1_UI_H
#define A6_JORZUL_1_UI_H

#ifndef CONSOLE_H
#define CONSOLE_H

#include "../Service/Service.h"

class Console {
private:
    Service* _movieService;
    Service* _watchListService;

    void add_10_random_movies();

    void add_movie_ui();

    void delete_movie_ui();

    void update_movie_ui();

    void display_all_movies_ui();

    void display_all_movies_of_genre_ui();

    void administrator_menu();

    void user_menu();

public:
    Console(Service& movieService, Service& watchListService);

    void menu();

    void display_watchlist_ui();

    void delete_movie_from_watchlist_ui();

    ~Console();
};

#endif


#endif //A6_JORZUL_1_UI_H
