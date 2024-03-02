//
// Created by User on 5/17/2023.
//

#include "FileWatchList.h"
#include <fstream>
#include <windows.h>
#include <shellapi.h>

void FileWatchList::openInApp() const
{
    this->writeToFile();
    std::string commandToOpenFile = this->fileName;
    // system(commandToOpenFile.c_str());
    ShellExecuteA(nullptr, "open", this->fileName.c_str(), nullptr, nullptr, SW_SHOWNORMAL);

}
