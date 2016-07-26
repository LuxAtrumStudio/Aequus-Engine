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
	LOGGING::LogData("1", "DEV");
	WINDOW windowDefintion;
	LOGGING::LogData("2", "DEV");
	windowDefintion.windowName = name;
	LOGGING::LogData("3", "DEV");
	graphicalWindows.push_back(windowDefintion);
	LOGGING::LogData("4", "DEV");
	LOGGING::LogSuccess("Initialized " + name + " window", "Aequus Core.cpp/AEQUUS/InitializeNewWindow");
}

void AEQUUS::GenorateWindow(int pointer, int posX, int posY, int width, int height)
{
	graphicalWindows[pointer].GenorateWindow(posX, posY, width, height);
}