#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

namespace AEQUUS {
	/*=====>>>>>-----CORE FUNCTIONS-----<<<<<=====*/
	/*=====>>>>>-----Initialization-----<<<<<=====*/
	/*>>>>>-----INDIVIDUAL-----<<<<<*/
	void InitializeSDL();
	/*>>>>>-----COMPLEATE-----<<<<<*/
	void InitializeAequus();
	/*=====>>>>>-----Run Time-----<<<<<=====*/
	/*>>>>>-----WINDOWS-----<<<<<*/
	/*>>>>>-----Initialization-----<<<<<*/
	void InitializeNewWindow(string name);
	/*-----POINTER-----*/
	void GenorateWindow(int pointer, int posX, int posY, int width, int height);
}