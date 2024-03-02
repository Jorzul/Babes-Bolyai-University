//
// Created by User on 5/17/2023.
//

#ifndef A7_JORZUL_1_UI_H
#define A7_JORZUL_1_UI_H

#pragma once
#include "Service.h"
#include "FileWatchList.h"
#include <iostream>
#include <string>

namespace OPTIONS
{
    namespace STORAGE_TYPE
    {
        const std::string STORAGE_FILE_NAME = "movies.txt";
    }
    namespace INTERFACE
    {
        const std::string ADMIN = "1";
        const std::string USER = "2";
    }
    namespace ADMIN
    {
        const std::string ADD_MOVIE = "1";
        const std::string REMOVE_MOVIE = "2";
        const std::string UPDATE_MOVIE = "3";
        const std::string PRINT_ALL_MOVIES = "4";
        const std::string SWITCH_TO_USER_INTERFACE = "5";
        const std::string EXIT = "6";
    }
    const std::string EXIT_APPLICATION = "3";
}

class UI
{
private:
    Service service;

public:
    UI();
    ~UI(){};
    void choose_watchlist_filetype();
    void print_admin_user_menu();
    void print_admin_menu();
    void print_user_menu();
    void runApp();
    void print_all_movies();
    void admin_add_movie();
    void admin_remove_movie();
    void admin_update_movie();
    void user_get_movies_by_genre();
    void user_display_movies_from_watchlist();
    void user_delete_movies_from_watchlist();
};

#endif //A7_JORZUL_1_UI_H
