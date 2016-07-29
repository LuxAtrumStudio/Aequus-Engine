#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include "SDL Headers.h"
using namespace std;

struct FONT {
	string fontPath, fontName;
	int point, weight;
	bool italic;
};

class TEXTURE
{
public:
	/*=====>>>>>-----PUBLIC-----<<<<<=====*/
	/*=====>>>>>-----Funcitons-----<<<<<=====*/
	/*>>>>>-----INITIALIZATION-----<<<<<*/
	TEXTURE();
	~TEXTURE();
	bool LoadTexture(string filePath);
	bool LoadText(string text, double red, double green, double blue);
	void SetRenderer(SDL_Renderer* pointer);
	/*>>>>>-----Text Initialization-----<<<<<*/
	void LoadFontDirect(string fontPath, int point);
	void SetWeight(int weight);
	void SetItalic(bool italic);
	void SetPoint(int point);
	void SetPath(string path);
	void SetName(string name);
	void LoadFontFull(string fontName, string path, int weigth, bool italic, int point);
	void LoadFont();
	/*>>>>>-----MANIPULATION-----<<<<<*/
	void SetCheck(int check, bool setting);
	/*>>>>>-----Translation-----<<<<<*/
	void Translate(int x, int y);
	void SetPos(int x, int y);
	/*>>>>>-----Scaling-----<<<<<*/
	void Scale(double scaleWidth, double scaleHeight);
	void SetClip(int posX, int posY, int width, int heigth);
	/*>>>>>-----Rotation-----<<<<<*/
	void Rotate(double angle);
	void Flip(int type);
	void SetRotationPoint(int x, int y);
	/*>>>>>-----Color Manipulation-----<<<<<*/
	void SetColor(double red, double green, double blue, double alpha);
	void SetTextColor(double red, double green, double blue);
	void Blend(int type);
	/*>>>>>-----DATA RETURN-----<<<<<*/
	void GetSize(int & width, int & height);
	/*>>>>>-----DISPLAY-----<<<<<*/
	void Render();
	/*>>>>>-----TERMINATION-----<<<<<*/
	void TerminateTexture();
private:
	/*=====>>>>>-----PUBLIC-----<<<<<=====*/
	/*=====>>>>>-----Funcitons-----<<<<<=====*/
	/*=====>>>>>-----Data-----<<<<<=====*/
	/*>>>>>-----ACTIVE MANIPULATIONS-----<<<<<*/
	bool scaleCheck, rotateCheck, flipCheck, colorCheck, clipCheck;
	/*>>>>>-----SDL POINTERS-----<<<<<*/
	SDL_Texture* texturePointer;
	SDL_Renderer* rendererPointer;
	/*>>>>>-----TEXTURE DATA-----<<<<<*/
	string textureFilePath, textStr;
	int textureWidth, textureHeight;
	int posX, posY;
	double textureScaleWidth, textureScaleHeight, textureAngle;
	Uint8 textureRed, textureGreen, textureBlue, textureAlpha;
	bool textUpdate;
	/*>>>>>-----FONT DATA-----<<<<<*/
	string fontNameStr, fontWeightStr, fontPathStr;
	int fontWeight, fontPoint;
	bool fontItalic;
	/*>>>>>-----SDL DATA-----<<<<<*/
	SDL_Rect* textureClip;
	SDL_Rect clip;
	SDL_RendererFlip textureFlip;
	SDL_Point* textureCenter;
	TTF_Font* textureFont;
};