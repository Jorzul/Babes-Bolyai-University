#include <crtdbg.h>
#include "Console.h"

void DriverCode()
{
	// Text Filename For Repository Constructor.
	Repository movieRepository;

	Repository watchListRepository;

	Service movieService{ movieRepository };

	Service watchListService{ watchListRepository };

	Console console{ movieService, watchListService };

	console.RunConsole();
}

int main()
{
    DriverCode();

	printf("Memory Leaks : %d", _CrtDumpMemoryLeaks());

	return 0;
}