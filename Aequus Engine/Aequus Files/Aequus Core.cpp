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
vector<WINDOW> graphicalWindows;
int currentGraphicalWindow = -1;
/*=====>>>>>-----CORE FUNCTIONS-----<<<<<=====*/
/*=====>>>>>-----Initialization-----<<<<<=====*/
/*>>>>>-----INDIVIDUAL-----<<<<<*/
void AEQUUS::InitializeSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		LOGGING::LogError("Unable to initialize SDL", "Aequus Core.cpp/AEQUUS/InitializeSDL");
	}
	else {
		LOGGING::LogSuccess("Initialized SDL", "Aequus Core.cpp/AEQUUS/InitializeSDL");
	}
}

void AEQUUS::SetTextureFiltering()
{
	if (SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1") == true) {
		LOGGING::LogSuccess("Set texture filtering to linear", "Aequus Core.cpp/AEQUUS/SetTextureFiltering");
	}
	else {
		LOGGING::LogError("Failed to set texture filtering to linear", "Aequus Core.cpp/AEQUUS/SetTextureFiltering");
	}
}
void AEQUUS::InitializeImageLoading()
{
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		LOGGING::LogError("Failed to initialize image loading", "Aequus Core.cpp/AEQUUS/InitializeImageLoading");
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}
	else {
		LOGGING::LogSuccess("Initialized image loading", "Aequus Core.cpp/AEQUUS/InitializeImageLoading");
	}
}
/*>>>>>-----COMPLEATE-----<<<<<*/
void AEQUUS::InitializeAequus()
{
	InitializeSDL();
	SetTextureFiltering();
	InitializeImageLoading();
}
/*=====>>>>>-----Run Time-----<<<<<=====*/
/*>>>>>-----WINDOWS-----<<<<<*/
/*>>>>>-----Management-----<<<<<*/
int AEQUUS::FindWindowPointer(string name)
{
	for (unsigned int a = 0; a < graphicalWindows.size(); a++) {
		if (graphicalWindows[a].windowName == name) {
			return(a);
		}
	}
	return(0);
}

int AEQUUS::WindowCount()
{
	return graphicalWindows.size();
}
/*>>>>>-----Initialization-----<<<<<*/
void AEQUUS::InitializeNewWindow(string name)
{
	WINDOW windowDefintion;
	windowDefintion.windowName = name;
	graphicalWindows.push_back(windowDefintion);
	LOGGING::LogSuccess("Initialized window " + name, "Aequus Core.cpp/AEQUUS/InitializeNewWindow");
}
/*-----POINTER-----*/
bool AEQUUS::BindCurrentWindow(int pointer)
{
	if (graphicalWindows.size() < pointer) {
		return(false);
	}
	else {
		currentGraphicalWindow = pointer;
	}
	return(true);
}

void AEQUUS::GenorateWindow(int pointer, int posX, int posY, int width, int height)
{
	graphicalWindows[pointer].GenorateWindow(posX, posY, width, height);
}
/*-----CURRENT-----*/
void AEQUUS::CGenorateWindow(int posX, int posY, int width, int height)
{
	GenorateWindow(currentGraphicalWindow, posX, posY, width, height);
}
/*-----FIND-----*/
bool AEQUUS::FBindCurrentWindow(string name)
{
	return BindCurrentWindow(FindWindowPointer(name));
}

void AEQUUS::FGenorateWindow(string name, int posX, int posY, int width, int height)
{
	GenorateWindow(FindWindowPointer(name), posX, posY, width, height);
}
/*>>>>>-----Run Time-----<<<<<*/
/*-----SINGLE-----*/
void AEQUUS::UpdateWindow(int pointer)
{
	graphicalWindows[pointer].Render();
}

bool AEQUUS::CheckWindow(int pointer)
{
	if (graphicalWindows[pointer].GetBool(5) == true) {
		return(true);
	}
	else {
		return(false);
	}
}

void AEQUUS::EventHandleWindow(int pointer, SDL_Event& SDLEvent)
{
	graphicalWindows[pointer].HandleEvent(SDLEvent);
}
/*-----ALL-----*/
void AEQUUS::UpdateAllWindows()
{
	for (unsigned int a = 0; a < graphicalWindows.size(); a++) {
		UpdateWindow(a);
	}
}

bool AEQUUS::CheckAllWindows()
{
	bool allWindowsClosed = true;
	for (unsigned int a = 0; a < graphicalWindows.size(); a++) {
		if (CheckWindow(a) == true) {
			allWindowsClosed = false;
			break;
		}
	}
	return(allWindowsClosed);
}

void AEQUUS::EventHandleAllWindows(SDL_Event& SDLEvent)
{
	for (unsigned int a = 0; a < graphicalWindows.size(); a++) {
		EventHandleWindow(a, SDLEvent);
	}
}
/*=====>>>>>-----Termination-----<<<<<=====*/
/*>>>>>-----INDIVIDUAL-----<<<<<*/
void AEQUUS::TerminateSDL()
{
	for (unsigned int a = 0; a < graphicalWindows.size(); a++) {
		graphicalWindows[a].TerminateWindow();
	}
	graphicalWindows.clear();
	SDL_Quit();
}
/*>>>>>-----COMPLEATE-----<<<<<*/
void AEQUUS::TerminateAequus()
{
	TerminateSDL();
}