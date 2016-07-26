#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include "SDL Headers.h"
using namespace std;

class WINDOW
{
private:
public:
	string windowName = NULL;
	SDL_Window* windowPointer = NULL;
	SDL_Surface* windowScreenSurfacePointer = NULL;
	bool GenorateWindow(int positionX, int positionY, int width, int height);
	void GetWindowSurface();
};