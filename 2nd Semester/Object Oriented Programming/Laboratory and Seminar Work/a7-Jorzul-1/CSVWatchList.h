//
// Created by User on 5/17/2023.
//

#ifndef A7_JORZUL_1_CSVWATCHLIST_H
#define A7_JORZUL_1_CSVWATCHLIST_H

#pragma once
#include "FileWatchList.h"

class CSVWatchList : public FileWatchList
{
public:
    CSVWatchList(const std::string &fileName) : FileWatchList{fileName} {}
    void writeToFile() const override;
};

#endif //A7_JORZUL_1_CSVWATCHLIST_H
