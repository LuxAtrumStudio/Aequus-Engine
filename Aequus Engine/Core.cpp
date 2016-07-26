#include <iostream>
#include "Conscientia Files\Conscientia Headers.h"
#include "Aequus Files\Aequus Headers.h"
using namespace std;

int main(int argc, char* argv[]) {
	LOGGING::InitializeLogging();
	AEQUUS::InitializeSDL();
	AEQUUS::InitializeNewWindow("Main");
	AEQUUS::GenorateWindow(0, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600);
	LOGGING::TerminateLogging();
	return(1);
}