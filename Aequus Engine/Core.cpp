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

	double red = 0, green = 0, blue = 0;

	int row = 0;
	AEQUUS::SetDefaultFont("AlegreyaSans", "", 30, 0, false);
	for (int a = 0; a < 7; a++) {
		AEQUUS::SetWeight(a);
		AEQUUS::NewText("Hello World!");
		AEQUUS::SetPositional(AEQUUS::window->textures.size() - 1, 100, row, 1, 1, 0, 0);
		row = row + 30;
	}
	AEQUUS::SetItalic(true);
	for (int a = 0; a < 7; a++) {
		AEQUUS::SetWeight(a);
		AEQUUS::NewText("Hello World!");
		AEQUUS::SetPositional(AEQUUS::window->textures.size() - 1, 100, row, 1, 1, 0, 0);
		row = row + 30;
	}
	AEQUUS::SetName("AlegreyaSansSC");
	AEQUUS::SetItalic(false);
	row = 0;
	for (int a = 0; a < 7; a++) {
		AEQUUS::SetWeight(a);
		AEQUUS::NewText("Hello World!");
		AEQUUS::SetPositional(AEQUUS::window->textures.size() - 1, 300, row, 1, 1, 0, 0);
		row = row + 30;
	}
	AEQUUS::SetItalic(true);
	for (int a = 0; a < 7; a++) {
		AEQUUS::SetWeight(a);
		AEQUUS::NewText("Hello World!");
		AEQUUS::SetPositional(AEQUUS::window->textures.size() - 1, 300, row, 1, 1, 0, 0);
		row = row + 30;
	}

	bool quit = false;
	SDL_Event SDLEvent;
	while (quit == false) {
		for (int a = 0; a < AEQUUS::window->textures.size(); a++) {
			AEQUUS::SetTextColor(a, red, green, blue);
		}
		red = red + 0.1;
		if (red > 1) {
			red = 0.0;
			green = green + 0.1;
			if (green > 1) {
				green = 0.0;
				blue = blue + 0.1;
				if (blue > 1) {
					blue = 0.0;
				}
			}
		}
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