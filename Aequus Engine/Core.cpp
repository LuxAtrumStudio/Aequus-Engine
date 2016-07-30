#include <iostream>
#include "Conscientia Files\Conscientia Headers.h"
#include "Aequus Files\Aequus Headers.h"
#include "Aequus Files\Aequus Core.h"
using namespace std;

int main(int argc, char* argv[]) {
	bool quit = false;
	LOGGING::InitializeLogging();
	AEQUUS::FullStatup();
	/*Pre Main Loop Code Goes Here*/

	SDL_Event SDLEvent;
	while (quit == false) {
		/*Main Loop Code Goes Here*/

		while (SDL_PollEvent(&SDLEvent) != 0) {
			if (SDLEvent.type == SDL_QUIT) {
				quit = true;
			}
			AEQUUS::EventHandleAllWindows(SDLEvent);
		}
		AEQUUS::UpdateAllWindows();
		if (AEQUUS::CheckAllWindows() == true) {
			quit = true;
		}
	}
	AEQUUS::FullShutDown();
	LOGGING::TerminateLogging();
	return(1);
}