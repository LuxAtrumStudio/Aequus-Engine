#include <iostream>
#include "Conscientia Files\Conscientia Headers.h"
#include "Aequus Files\Aequus Headers.h"
#include "Aequus Files\Aequus Core.h"
using namespace std;

int main(int argc, char* argv[]) {
	LOGGING::InitializeLogging();
	AEQUUS::InitializeAequus();
	AEQUUS::InitializeNewWindow("Main");
	AEQUUS::GenorateWindow(0, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600);
	AEQUUS::BindWindow(0);
	AEQUUS::SetDefaultFont("AlegreyaSans", "", 32, 3, false);
	AEQUUS::NewButton("Hello World!", "Button.png", 200, 100);
	bool quit = false;
	int index = 0;
	SDL_Event SDLEvent;
	while (quit == false) {
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
	AEQUUS::TerminateAequus();
	LOGGING::TerminateLogging();
	return(1);
}