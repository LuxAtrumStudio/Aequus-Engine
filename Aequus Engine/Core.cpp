#include <iostream>
#include "Conscientia Files\Conscientia Headers.h"
#include "Aequus Files\Aequus Headers.h"
using namespace std;

int main(int argc, char* argv[]) {
	LOGGING::InitializeLogging();
	AEQUUS::InitializeAequus();
	AEQUUS::InitializeNewWindow("Main");
	AEQUUS::GenorateWindow(0, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600);
	bool quit = false;
	SDL_Event SDLEvent;
	while (quit == false) {
		while (SDL_PollEvent(&SDLEvent) != 0) {
			if (SDLEvent.type == SDL_QUIT) {
				quit = true;
				AEQUUS::EventHandleAllWindows(SDLEvent);
			}
			if (SDLEvent.type == SDL_KEYDOWN) {
				switch (SDLEvent.key.keysym.sym) {
				case SDLK_n:
					AEQUUS::InitializeNewWindow("YAY");
					AEQUUS::GenorateWindow(AEQUUS::WindowCount() - 1, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600);
				}
			}
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