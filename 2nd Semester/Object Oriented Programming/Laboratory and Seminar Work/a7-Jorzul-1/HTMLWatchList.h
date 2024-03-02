//
// Created by User on 5/17/2023.
//

#ifndef A7_JORZUL_1_HTMLWATCHLIST_H
#define A7_JORZUL_1_HTMLWATCHLIST_H

#pragma once
#include "FileWatchList.h"

class HTMLWatchList : public FileWatchList
{
public:
    HTMLWatchList(const std::string &fileName) : FileWatchList{fileName} {}
    void writeToFile() const override;
};

#endif //A7_JORZUL_1_HTMLWATCHLIST_H
