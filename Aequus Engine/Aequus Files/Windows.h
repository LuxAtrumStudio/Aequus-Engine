#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include "SDL Headers.h"
using namespace std;

class WINDOW
{
public:
	string windowName;
	WINDOW();
	~WINDOW();
	void GenorateWindow(int posX, int posY, int width, int height);
	void HandleEvent(SDL_Event& SDLEvent);
	void Focus();
	void Render();
	void TerminateWindow();

	void GetSize(int& width, int& height);
	bool GetBool(int value);
private:
	SDL_Window* windowPointer;
	SDL_Renderer* rendererPointer;
	int windowID;
	int windowWidth, windowHeight;
	bool mouseFocus, keyboardFocus, fullScreen, minimized, shown;
};