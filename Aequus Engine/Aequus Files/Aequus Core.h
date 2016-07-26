#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include "SDL Headers.h"
using namespace std;

namespace AEQUUS {
	/*=====>>>>>-----CORE FUNCTIONS-----<<<<<=====*/
	/*=====>>>>>-----Initialization-----<<<<<=====*/
	/*>>>>>-----INDIVIDUAL-----<<<<<*/
	void InitializeSDL();
	void SetTextureFiltering();
	/*>>>>>-----COMPLEATE-----<<<<<*/
	void InitializeAequus();
	/*=====>>>>>-----Run Time-----<<<<<=====*/
	/*>>>>>-----WINDOWS-----<<<<<*/
	/*>>>>>-----Management-----<<<<<*/
	int FindWindowPointer(string name);
	int WindowCount();
	/*>>>>>-----Initialization-----<<<<<*/
	void InitializeNewWindow(string name);
	/*-----POINTER-----*/
	bool BindCurrentWindow(int pointer);
	void GenorateWindow(int pointer, int posX, int posY, int width, int height);
	/*-----CURRENT-----*/
	void CGenorateWindow(int posX, int posY, int width, int height);
	/*-----FIND-----*/
	bool FBindCurrentWindow(string name);
	void FGenorateWindow(string name, int posX, int posY, int width, int height);
	/*>>>>>-----Run Time-----<<<<<*/
	/*-----SINGLE-----*/
	void UpdateWindow(int pointer);
	bool CheckWindow(int pointer);
	void EventHandleWindow(int pointer, SDL_Event& SDLEvent);
	/*-----ALL-----*/
	void UpdateAllWindows();
	bool CheckAllWindows();
	void EventHandleAllWindows(SDL_Event& SDLEvent);
	/*=====>>>>>-----Termination-----<<<<<=====*/
	/*>>>>>-----INDIVIDUAL-----<<<<<*/
	void TerminateSDL();
	/*>>>>>-----COMPLEATE-----<<<<<*/
	void TerminateAequus();
}