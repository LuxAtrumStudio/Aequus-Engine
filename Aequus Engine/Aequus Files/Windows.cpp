#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <ctime>
#include "SDL Headers.h"
#include "../Conscientia Files/Conscientia Headers.h";
#include "Aequus Headers.h"
using namespace std;

bool WINDOW::GenorateWindow(int positionX, int positionY, int width, int height)
{
	bool successReturn = true;
	windowPointer = SDL_CreateWindow(windowName.c_str(), positionX, positionY, width, height, SDL_WINDOW_SHOWN);
	if (windowPointer == NULL) {
		successReturn = false;
		LOGGING::LogError("Failed to genorate: " + windowName, "Windows.cpp/WINDOW/GenorateWindow");
	}
	else {
		LOGGING::LogSuccess("Genorated: " + windowName, "Windows.cpp/WINDOW/GenorateWindow");
	}
	return(successReturn);
}

void WINDOW::GetWindowSurface()
{
	windowScreenSurfacePointer = SDL_GetWindowSurface(windowPointer);
}