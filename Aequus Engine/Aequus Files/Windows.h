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
	SDL_Window* windowPointer = NULL;
	SDL_Surface* screenSurface = NULL;
	WINDOW();
	~WINDOW();
	void GenorateWindow(int posX, int posY, int width, int height);
	void GetScreenSurface();
	void TerminateWindow();
private:
};