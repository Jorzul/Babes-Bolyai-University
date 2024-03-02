//
// Created by User on 5/17/2023.
//

#include "Exceptions.h"

FileException::FileException(const std::string &message)
{
    this->message = message;
}

const char *FileException::what()
{
    return this->message.c_str();
}

RepositoryException::RepositoryException() : std::exception()
{
    this->message = "";
}

const char *RepositoryException::what()
{
    return this->message.c_str();
}

const char *DuplicateMovieException::what()
{
    return "The movie is already in the repository!";
}

const char *InvalidPositionException::what()
{
    return "The position of the movie is invalid!";
}
