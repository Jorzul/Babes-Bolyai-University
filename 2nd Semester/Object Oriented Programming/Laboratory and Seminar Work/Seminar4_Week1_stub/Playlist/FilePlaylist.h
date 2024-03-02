//
// Created by User on 4/12/2023.
//

#ifndef SEMINAR4_WEEK1_STUB_FILEPLAYLIST_H
#define SEMINAR4_WEEK1_STUB_FILEPLAYLIST_H

#include "PlayList.h"

#include <utility>
#pragma once

class FilePlaylist: public PlayList
{
private:
    std::string fileName;
public:
    explicit FilePlaylist(std::string fileName = "")
    {
        this->fileName = std::move(fileName);
    }

    ~filePlaylist()
    {

    }

    virtual void writeToFile() = 0;

    virtual void displayPlaylist() = 0;
};

#endif //SEMINAR4_WEEK1_STUB_FILEPLAYLIST_H
