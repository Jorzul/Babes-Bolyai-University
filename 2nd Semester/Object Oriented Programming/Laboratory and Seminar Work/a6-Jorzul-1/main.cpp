//
// Created by User on 5/4/2023.
//
#include <crtdbg.h>
#include "ui/ui.h"
#include "Tests/test.h"

int main()
{
    TestAll();

    Repository movieRepository;

    Repository watchListRepository;

    Service movieService{ movieRepository };

    Service watchListService{ watchListRepository };

    Console console{ movieService, watchListService };

    console.menu();

    printf("Memory Leaks : %d", _CrtDumpMemoryLeaks());

    return 0;
}