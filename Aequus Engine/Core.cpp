#include <iostream>
#include "Conscientia Files\Conscientia Headers.h"
#include "Aequus Files\Aequus Headers.h"
using namespace std;

int main(int argc, char* argv[]) {
	LOGGING::InitializeLogging();
	AEQUUS::InitializeAequus();
	AEQUUS::InitializeNewWindow("Main");
	AEQUUS::GenorateWindow(0, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600);
	TEXTURE newTexture;
	graphicalWindows[0].textures.push_back(newTexture);
	graphicalWindows[0].textures[0].SetRenderer(graphicalWindows[0].rendererPointer);
	graphicalWindows[0].textures[0].LoadTexture("Test.png");
	bool quit = false;
	SDL_Event SDLEvent;
	while (quit == false) {
		while (SDL_PollEvent(&SDLEvent) != 0) {
			if (SDLEvent.type == SDL_QUIT) {
				quit = true;
				AEQUUS::EventHandleAllWindows(SDLEvent);
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