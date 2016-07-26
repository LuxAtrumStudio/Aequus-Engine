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

void AEQUUS::InitializeSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		LOGGING::LogError("Unable to initialize SDL", "Aequus Core.cpp/AEQUUS/InitializeSDL");
	}
	else {
		LOGGING::LogSuccess("Initialized SDL", "Aequus Core.cpp/AEQUUS/InitializeSDL");
	}
}

void AEQUUS::InitializeAequus()
{
}

void AEQUUS::InitializeNewWindow(string name)
{
	WINDOW windowDefintion;
	windowDefintion.windowName = name;
	graphicalWindows.push_back(windowDefintion);
	LOGGING::LogSuccess("Initialized window " + name, "Aequus Core.cpp/AEQUUS/InitializeNewWindow");
}

void AEQUUS::GenorateWindow(int pointer, int posX, int posY, int width, int height)
{
	graphicalWindows[pointer].GenorateWindow(posX, posY, width, height);
}