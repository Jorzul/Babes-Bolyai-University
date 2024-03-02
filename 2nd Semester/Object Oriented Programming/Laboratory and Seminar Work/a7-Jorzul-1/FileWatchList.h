//
// Created by User on 5/17/2023.
//

#ifndef A7_JORZUL_1_FILEWATCHLIST_H
#define A7_JORZUL_1_FILEWATCHLIST_H

#pragma once
#include "WatchList.h"

class FileWatchList : public WatchList
{
protected:
    std::string fileName;

public:
    FileWatchList(const std::string &fileName) : fileName{fileName} {}
    virtual void writeToFile() const = 0;
    void openInApp() const;
    virtual ~FileWatchList(){};
};

#endif //A7_JORZUL_1_FILEWATCHLIST_H
