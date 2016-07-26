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

WINDOW::WINDOW()
{
}

WINDOW::~WINDOW()
{
}

void WINDOW::GenorateWindow(int posX, int posY, int width, int height)
{
	windowPointer = SDL_CreateWindow("SDL Tutorial", posX, posY, width, height, SDL_WINDOW_SHOWN);
	if (windowPointer == NULL) {
		LOGGING::LogError("Unable to genorate window " + windowName, "Window.cpp/WINDOW/GenorateWindow");
	}
	else {
		LOGGING::LogSuccess("Genorated window " + windowName, "Window.cpp/WINDOW/GenorateWindow");
	}
}

void WINDOW::GetScreenSurface()
{
	screenSurface = SDL_GetWindowSurface(windowPointer);
	if (screenSurface == NULL) {
		LOGGING::LogError("Unable to load screen surface for " + windowName, "Window.cpp/WINDOW/GetScreenSurface");
	}
	else {
		LOGGING::LogSuccess("Loaded screen surface for " + windowName, "Window.cpp/WINDOW/GetScreenSurface");
	}
}

void WINDOW::TerminateWindow()
{
	SDL_DestroyWindow(windowPointer);
	windowPointer = NULL;
}