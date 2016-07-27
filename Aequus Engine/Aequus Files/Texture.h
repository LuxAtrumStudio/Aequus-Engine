#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include "SDL Headers.h"
using namespace std;

class TEXTURE
{
public:
	TEXTURE();
	~TEXTURE();
	bool LoadTexture(string filePath);
	void TerminateTexture();
	void SetColor(Uint8 red, Uint8 green, Uint8 blue);
	void RenderSet(int x, int y, SDL_Rect* clip = NULL);
	void Render();
	void GetSize(int & width, int & height);
	void SetRenderer(SDL_Renderer* pointer);
	void SetPos(int x, int y);
	void SetClip(SDL_Rect* clip);
private:
	SDL_Texture* texturePointer;
	int textureWidth, textureHeight;
	SDL_Renderer* rendererPointer;
	int posX, posY;
	SDL_Rect* renderClip;
};