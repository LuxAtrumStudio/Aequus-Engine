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
	windowPointer = NULL;
	rendererPointer = NULL;
	mouseFocus = false;
	keyboardFocus = false;
	fullScreen = false;
	shown = false;
	windowID = -1;
	windowWidth = 0;
	windowHeight = 0;
}

WINDOW::~WINDOW()
{
}

void WINDOW::GenorateWindow(int posX, int posY, int width, int height)
{
	windowPointer = SDL_CreateWindow("SDL Tutorial", posX, posY, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (windowPointer == NULL) {
		LOGGING::LogError("Unable to genorate window " + windowName, "Window.cpp/WINDOW/GenorateWindow");
	}
	else {
		LOGGING::LogSuccess("Genorated window " + windowName, "Window.cpp/WINDOW/GenorateWindow");
		mouseFocus = true;
		keyboardFocus = true;
		windowWidth = width;
		windowHeight = height;
		rendererPointer = SDL_CreateRenderer(windowPointer, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (rendererPointer = NULL) {
			LOGGING::LogError("Could not create renderer for " + windowName, "Windows.cpp/WINDOW/GenorateWindow");
			SDL_DestroyWindow(windowPointer);
			windowPointer = NULL;
		}
		else {
			LOGGING::LogSuccess("Created renderer for " + windowName, "Window.cpp/WINDOW/GenorateWindow");
			SDL_SetRenderDrawColor(rendererPointer, 0xFF, 0xFF, 0xFF, 0xFF);
			windowID = SDL_GetWindowID(windowPointer);
			shown = true;
		}
	}
}

void WINDOW::HandleEvent(SDL_Event & SDLEvent)
{
	if (SDLEvent.type == SDL_WINDOWEVENT && SDLEvent.window.windowID == windowID) {
		bool updateCaption = false;
		switch (SDLEvent.window.event) {
			//Window appeared
		case SDL_WINDOWEVENT_SHOWN:
			shown = true;
			break;

			//Window disappeared
		case SDL_WINDOWEVENT_HIDDEN:
			shown = false;
			break;

			//Get new dimensions and repaint
		case SDL_WINDOWEVENT_SIZE_CHANGED:
			windowWidth = SDLEvent.window.data1;
			windowHeight = SDLEvent.window.data2;
			SDL_RenderPresent(rendererPointer);
			break;

			//Repaint on expose
		case SDL_WINDOWEVENT_EXPOSED:
			SDL_RenderPresent(rendererPointer);
			break;

			//Mouse enter
		case SDL_WINDOWEVENT_ENTER:
			mouseFocus = true;
			updateCaption = true;
			break;

			//Mouse exit
		case SDL_WINDOWEVENT_LEAVE:
			mouseFocus = false;
			updateCaption = true;
			break;

			//Keyboard focus gained
		case SDL_WINDOWEVENT_FOCUS_GAINED:
			keyboardFocus = true;
			updateCaption = true;
			break;

			//Keyboard focus lost
		case SDL_WINDOWEVENT_FOCUS_LOST:
			keyboardFocus = false;
			updateCaption = true;
			break;

			//Window minimized
		case SDL_WINDOWEVENT_MINIMIZED:
			minimized = true;
			break;

			//Window maxized
		case SDL_WINDOWEVENT_MAXIMIZED:
			minimized = false;
			break;

			//Window restored
		case SDL_WINDOWEVENT_RESTORED:
			minimized = false;
			break;
			//Hide on close
		case SDL_WINDOWEVENT_CLOSE:
			SDL_HideWindow(windowPointer);
			break;
		}
		if (updateCaption == true) {
			stringstream caption;
			caption << windowName << windowID << " MouseFocus:" << ((mouseFocus) ? "On" : "Off") << " KeyboardFocus:" << ((keyboardFocus) ? "On" : "Off");
			SDL_SetWindowTitle(windowPointer, caption.str().c_str());
		}
	}
}

void WINDOW::Focus()
{
	if (shown == false) {
		SDL_ShowWindow(windowPointer);
	}
	SDL_RaiseWindow(windowPointer);
}

void WINDOW::Render()
{
	if (minimized == true) {
		SDL_SetRenderDrawColor(rendererPointer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(rendererPointer);
		SDL_RenderPresent(rendererPointer);
	}
}

void WINDOW::TerminateWindow()
{
	if (windowPointer != NULL) {
		SDL_DestroyWindow(windowPointer);
	}
	windowPointer = NULL;
	mouseFocus = false;
	keyboardFocus = false;
	windowWidth = 0;
	windowHeight = 0;
}

void WINDOW::GetSize(int & width, int & height)
{
	width = windowWidth;
	height = windowHeight;
}

bool WINDOW::GetBool(int value)
{
	if (value == 1) {
		return(mouseFocus);
	}
	else if (value == 2) {
		return(keyboardFocus);
	}
	else if (value == 3) {
		return(fullScreen);
	}
	else if (value == 4) {
		return(minimized);
	}
	else if (value == 5) {
		return(shown);
	}
	else {
		return(false);
	}
}