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

int currentGraphicalWindow = -1;

namespace AEQUUS {
	vector<WINDOW> graphicalWindows;
	WINDOW* window;
	FONT defaultFont;
}

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
	}
	else {
		LOGGING::LogSuccess("Initialized image loading", "Aequus Core.cpp/AEQUUS/InitializeImageLoading");
	}
}

void AEQUUS::InitializeTTF()
{
	if (TTF_Init() == -1) {
		LOGGING::LogError("Failed to initialize TTF", "Aequus Core.cpp/AEQUUS/InitializeTTF");
	}
	else {
		LOGGING::LogSuccess("Initialized TTF", "Aequus Core.cpp/AEQUUS/InitializeTTF");
	}
}

/*>>>>>-----COMPLEATE-----<<<<<*/

void AEQUUS::InitializeAequus()
{
	InitializeSDL();
	SetTextureFiltering();
	InitializeImageLoading();
	InitializeTTF();
	TTF::SetDefaultFont("Fonts");
	window = NULL;
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
	return(-1);
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

bool AEQUUS::BindWindow(int pointer)
{
	if (pointer > graphicalWindows.size()) {
		return(false);
	}
	else {
		window = &graphicalWindows[pointer];
	}
	return(true);
}

bool AEQUUS::SelectCurrentWindow(int pointer)
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

bool AEQUUS::BindWindowName(string name)
{
	return(BindWindow(FindWindowPointer(name)));
}

bool AEQUUS::FSelectCurrentWindow(string name)
{
	return SelectCurrentWindow(FindWindowPointer(name));
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

/*>>>>>-----TEXTURES-----<<<<<*/

/*>>>>>-----Loading-----<<<<<*/

/*-----TEXTURES-----*/

void AEQUUS::NewTexture(string filePath)
{
	TEXTURE newTexture;
	int index = window->textures.size();
	window->textures.push_back(newTexture);
	window->textures[index].SetRenderer(window->rendererPointer);
	window->textures[index].LoadTexture(filePath);
}

/*-----TEXT-----*/

void AEQUUS::NewText(string text)
{
	TEXTURE newTexture;
	int index = window->textures.size();
	window->textures.push_back(newTexture);
	window->textures[index].SetRenderer(window->rendererPointer);
	window->textures[index].SetFont(0);
	window->textures[index].LoadText(text, 0.0, 0.0, 0.0);
}

/*-----BUTTON-----*/

void AEQUUS::NewButton(string text, string filePath, int width, int height)
{
	TEXTURE newTexture;
	int index = window->textures.size();
	window->textures.push_back(newTexture);
	window->textures[index].SetRenderer(window->rendererPointer);
	window->textures[index].SetFont(0);
	window->textures[index].LoadButton(text, filePath, 255, 255, 255, width, height, false);
}

/*>>>>>-----Manipulation-----<<<<<*/

void AEQUUS::SetPositional(int pointer, int x, int y, double scaleWidth, double scaleHeight, double angle, int flip)
{
	window->textures[pointer].SetPos(x, y);
	window->textures[pointer].Scale(scaleWidth, scaleHeight);
	window->textures[pointer].Rotate(angle);
	window->textures[pointer].Flip(flip);
}

void AEQUUS::SetColor(int pointer, double red, double green, double blue, double alpha, int blend)
{
	window->textures[pointer].Blend(blend);
	window->textures[pointer].SetColor(red, green, blue, alpha);
}

void AEQUUS::SetTextColor(int pointer, double red, double green, double blue)
{
	window->textures[pointer].SetTextColor(red, green, blue);
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