#include <iostream>
#include "Conscientia Files\Conscientia Headers.h"
#include "Aequus Files\Aequus Headers.h"
#include "Aequus Files\Aequus Core.h"
using namespace std;
using namespace AEQUUS;

int main(int argc, char* argv[]) {
	LOGGING::InitializeLogging();
	FullStatup();
	/*Pre Main Loop Code Goes Here*/
	int width = window->windowWidth;
	int height = window->windowHeight;
	NewButton("Quit?", "Button.png", width / 2, height / 5);
	SetPositional(0, window->windowWidth / 4, (window->windowHeight / 5) * 2, 1, 1, 0, 0);
	while (mainLoopQuit == false) {
		/*Main Loop Code Goes Here*/

		for (unsigned a = 0; a < objectEvent.size(); a++) {
			if (objectEvent[a].windowPointer == 0 && objectEvent[a].TexturePointer == 0 && objectEvent[a].value == 1) {
				mainLoopQuit = true;
			}
		}
		while (SDL_PollEvent(&Event) != 0) {
		}
		Frame();
	}
	FullShutDown();
	LOGGING::TerminateLogging();
	return(1);
}