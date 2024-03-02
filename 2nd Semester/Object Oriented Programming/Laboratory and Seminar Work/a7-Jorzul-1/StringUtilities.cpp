//
// Created by User on 5/17/2023.
//

#include "StringUtilities.h"

void StringUtilities::trim_whitespaces_of_string(std::string &stringToTrim)
{
    while (!stringToTrim.empty() && stringToTrim[0] == ' ')
        stringToTrim.erase(0, 1);
    while (!stringToTrim.empty() && stringToTrim[stringToTrim.size() - 1] == ' ')
        stringToTrim.erase(stringToTrim.size() - 1, 1);
}

std::vector<std::string> StringUtilities::tokenizeString(std::string &stringToTokenize, char delimiter)
{
    std::vector<std::string> tokens;
    std::istringstream tokenStream(stringToTokenize);
    std::string token;
    while (getline(tokenStream, token, delimiter))
    {
        trim_whitespaces_of_string(token);
        tokens.push_back(token);
    }
    return tokens;
}
