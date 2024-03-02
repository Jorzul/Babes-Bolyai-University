//
// Created by User on 5/17/2023.
//

#ifndef A7_JORZUL_1_STRINGUTILITIES_H
#define A7_JORZUL_1_STRINGUTILITIES_H

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class StringUtilities
{
public:
    void trim_whitespaces_of_string(std::string &stringToTrim);
    std::vector<std::string> tokenizeString(std::string &stringToTokenize, char delimiter);
};

#endif //A7_JORZUL_1_STRINGUTILITIES_H
