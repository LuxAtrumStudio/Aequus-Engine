#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include "SDL Headers.h"
using namespace std;

struct EVENTPOINTER {
	int windowPointer, TexturePointer;
};

class WINDOW
{
public:
	vector<TEXTURE> textures;
	string windowName;
	WINDOW();
	~WINDOW();
	void GenorateWindow(int posX, int posY, int width, int height);
	vector<EVENTPOINTER> HandleEvent(SDL_Event& SDLEvent);
	void Focus();
	void Render();
	void TerminateWindow();

	void GetSize(int& width, int& height);
	bool GetBool(int value);

	SDL_Window* windowPointer;
	SDL_Renderer* rendererPointer;

private:
	int windowID;
	int windowWidth, windowHeight;
	bool mouseFocus, keyboardFocus, fullScreen, minimized, shown;
};