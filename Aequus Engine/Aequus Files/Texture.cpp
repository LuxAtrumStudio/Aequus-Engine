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

/*=====>>>>>-----PUBLIC-----<<<<<=====*/

/*=====>>>>>-----Funcitons-----<<<<<=====*/

/*>>>>>-----INITIALIZATION-----<<<<<*/

TEXTURE::TEXTURE()
{
	texturePointer = NULL;
	textureWidth = 0;
	textureHeight = 0;
	posX = 0;
	posY = 0;
	textureScaleWidth = 1;
	textureScaleHeight = 1;
	textureAngle = 0;
	textureRed = 255;
	textureGreen = 255;
	textureBlue = 255;
	textureAlpha = 255;
	textureClip = NULL;
	textureCenter = NULL;
	textureFlip = SDL_FLIP_NONE;
	textureFont = NULL;
	scaleCheck = false;
	rotateCheck = false;
	flipCheck = false;
	colorCheck = false;
	clipCheck = false;
	textUpdate = false;
}

TEXTURE::~TEXTURE()
{
}

bool TEXTURE::LoadTexture(string filePath)
{
	TerminateTexture();
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(filePath.c_str());
	if (loadedSurface == NULL) {
		LOGGING::LogError("Unable to load image " + filePath, "Texture.cpp/TEXTURE/LoadTexture");
		return(false);
	}
	else {
		LOGGING::LogSuccess("Loaded image " + filePath, "Texture.cpp/TEXTURE/LoadTexture");
		newTexture = SDL_CreateTextureFromSurface(rendererPointer, loadedSurface);
		if (newTexture == NULL) {
			LOGGING::LogError("Failed to genorate texture from surface " + filePath, "Texture.cpp/TEXTURE/LoadTexture");
			return(false);
		}
		else {
			LOGGING::LogSuccess("Genorated texture from surface " + filePath, "Texture.cpp/TEXTURE/LoadTexture");
			textureWidth = loadedSurface->w;
			textureHeight = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
		textureFilePath = filePath;
	}
	texturePointer = newTexture;
	return(true);
}

bool TEXTURE::LoadText(string text, double red, double green, double blue)
{
	if (textUpdate == false) {
		TerminateTexture();
	}
	textStr = text;
	SDL_Color textColor;
	textColor.r = 255 * red;
	textColor.g = 255 * green;
	textColor.b = 255 * blue;
	if (textureFont == NULL) {
		LOGGING::LogWarning("Must initialize font before text", "Texture.cpp/TEXTURE/LoadText");
		return(false);
	}
	else {
		SDL_Surface* textSurface = TTF_RenderText_Solid(textureFont, text.c_str(), textColor);
		if (textSurface == NULL) {
			LOGGING::LogError("Failed to render text surface", "Texture.cpp/TEXTURE/LoadText");
			printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
		}
		else {
			LOGGING::LogSuccess("Render text surface", "Texture.cpp/TEXTURE/LoadText");
			texturePointer = SDL_CreateTextureFromSurface(rendererPointer, textSurface);
			if (texturePointer == NULL) {
				LOGGING::LogError("Failed to create texture from surface", "Texture.cpp/TEXTURE/LoadText");
			}
			else {
				LOGGING::LogSuccess("Created texture from surface", "Texture.cpp/TEXTURE/LoadText");
				textureWidth = textSurface->w;
				textureHeight = textSurface->h;
			}
			SDL_FreeSurface(textSurface);
		}
	}
	return (true);
}

void TEXTURE::SetRenderer(SDL_Renderer * pointer)
{
	rendererPointer = pointer;
}

/*>>>>>-----Text Initialization-----<<<<<*/

void TEXTURE::LoadFontDirect(string fontPath, int point)
{
	textureFont = TTF_OpenFont(fontPath.c_str(), point);
	if (textureFont == NULL) {
		LOGGING::LogError("Unable to load " + fontPath, "Texture.cpp/TEXTURE/LoadFontDirect");
	}
	else {
		LOGGING::LogSuccess("Loaded " + fontPath, "Texture.cpp/TEXTURE/LoadFontDirect");
	}
}

void TEXTURE::SetWeight(int weight)
{
	fontWeight = weight;
	if (weight == 0) {
		fontWeightStr = "Thin";
	}
	if (weight == 1) {
		fontWeightStr = "Light";
	}
	if (weight == 2) {
		fontWeightStr = "Regular";
	}
	if (weight == 3) {
		fontWeightStr = "Medium";
	}
	if (weight == 4) {
		fontWeightStr = "Bold";
	}
	if (weight == 5) {
		fontWeightStr = "ExtraBold";
	}
	if (weight == 6) {
		fontWeightStr = "Black";
	}
}

void TEXTURE::SetItalic(bool italic)
{
	fontItalic = italic;
}

void TEXTURE::SetPoint(int point)
{
	fontPoint = point;
}

void TEXTURE::SetPath(string path)
{
	fontPathStr = path;
}

void TEXTURE::SetName(string name)
{
	fontNameStr = name;
}

void TEXTURE::LoadFontFull(string fontName, string path, int weight, bool italic, int point)
{
	string fontPath = path + fontName + "/" + fontName;
	SetWeight(weight);
	SetItalic(italic);
	SetPoint(point);
	SetPath(path);
	SetName(fontName);
	if (weight == 2 || italic == true) {
		fontPath = fontPath + "-" + "Italic";
	}
	else {
		fontPath = fontPath + "-" + fontWeightStr;
		if (fontItalic == true) {
			fontPath = fontPath + "Italic";
		}
	}
	fontPath = fontPath + ".ttf";
	LoadFontDirect(fontPath, fontPoint);
}

void TEXTURE::LoadFont()
{
	string fontPath = fontPathStr + fontNameStr + "/" + fontNameStr;
	if (fontWeight == 2 && fontItalic == true) {
		fontPath = fontPath + "-" + "Italic";
	}
	else {
		fontPath = fontPath + "-" + fontWeightStr;
		if (fontItalic == true) {
			fontPath = fontPath + "Italic";
		}
	}
	fontPath = fontPath + ".ttf";
	LoadFontDirect(fontPath, fontPoint);
}

/*>>>>>-----MANIPULATION-----<<<<<*/

void TEXTURE::SetCheck(int check, bool setting)
{
	if (check == 0) {
		scaleCheck = setting;
	}
	if (check == 1) {
		rotateCheck = setting;
	}
	if (check == 2) {
		flipCheck = setting;
	}
	if (check == 3) {
		colorCheck = setting;
	}
	if (check == 4) {
		clipCheck = setting;
	}
}

/*>>>>>-----Translation-----<<<<<*/

void TEXTURE::Translate(int x, int y)
{
	posX = posX + x;
	posY = posY + y;
}

void TEXTURE::SetPos(int x, int y)
{
	posX = x;
	posY = y;
}

/*>>>>>-----Scaling-----<<<<<*/

void TEXTURE::Scale(double scaleWidth, double scaleHeigh)
{
	textureScaleWidth = scaleWidth;
	textureScaleHeight = scaleHeigh;
	if (scaleWidth != 1 || scaleHeigh != 1) {
		scaleCheck = true;
	}
	else {
		scaleCheck = false;
	}
}

void TEXTURE::SetClip(int posX, int posY, int width, int height)
{
	clip.x = posX;
	clip.y = posY;
	clip.w = width;
	clip.h = height;
	textureClip = &clip;
	if (posX != 0 || posY != 0 || width != textureWidth || height != textureHeight) {
		clipCheck = true;
	}
	else {
		clipCheck = false;
	}
}

/*>>>>>-----Rotation-----<<<<<*/

void TEXTURE::Rotate(double angle)
{
	textureAngle = angle;
	if (angle != 0) {
		rotateCheck = true;
	}
	else {
		rotateCheck = false;
	}
}

void TEXTURE::Flip(int type)
{
	if (type == 0) {
		textureFlip = SDL_FLIP_NONE;
	}
	if (type == 1) {
		textureFlip = SDL_FLIP_HORIZONTAL;
	}
	if (type == 2) {
		textureFlip = SDL_FLIP_VERTICAL;
	}
	if (type == 0) {
		rotateCheck = false;
	}
	else if (type > 0) {
		rotateCheck = true;
	}
}

void TEXTURE::SetRotationPoint(int x, int y)
{
	textureCenter->x = x;
	textureCenter->y = y;
}

/*>>>>>-----Color Manipulation-----<<<<<*/

void TEXTURE::SetColor(double red, double green, double blue, double alpha)
{
	textureRed = 255 * red;
	textureGreen = 255 * green;
	textureBlue = 255 * blue;
	textureAlpha = 255 * alpha;
	SDL_SetTextureColorMod(texturePointer, textureRed, textureGreen, textureBlue);
	SDL_SetTextureAlphaMod(texturePointer, textureAlpha);
	if (red != 1 || green != 1 || blue != 1 || alpha != 1) {
		colorCheck = true;
	}
	else {
		colorCheck = false;
	}
}

void TEXTURE::SetTextColor(double red, double green, double blue)
{
	textureRed = 255 * red;
	textureGreen = 255 * green;
	textureBlue = 255 * blue;
	LoadText(textStr, red, green, blue);
	textUpdate = true;
}

void TEXTURE::Blend(int type)
{
	if (type == 0) {
		SDL_SetTextureBlendMode(texturePointer, SDL_BLENDMODE_NONE);
	}
	if (type == 1) {
		SDL_SetTextureBlendMode(texturePointer, SDL_BLENDMODE_BLEND);
	}
	if (type == 2) {
		SDL_SetTextureBlendMode(texturePointer, SDL_BLENDMODE_ADD);
	}
	if (type == 4) {
		SDL_SetTextureBlendMode(texturePointer, SDL_BLENDMODE_MOD);
	}
}

/*>>>>>-----DATA RETURN-----<<<<<*/

void TEXTURE::GetSize(int & width, int & height)
{
	width = textureWidth;
	height = textureHeight;
}

/*>>>>>-----DISPLAY-----<<<<<*/

void TEXTURE::Render()
{
	SDL_Rect renderClip = { posX, posY, textureWidth, textureHeight };
	if (textureClip != NULL) {
		renderClip.w = textureClip->w;
		renderClip.h = textureClip->h;
	}
	renderClip.w = renderClip.w * textureScaleWidth;
	renderClip.h = renderClip.h * textureScaleHeight;
	SDL_RenderCopyEx(rendererPointer, texturePointer, textureClip, &renderClip, textureAngle, textureCenter, textureFlip);
}

/*>>>>>-----TERMINATION-----<<<<<*/

void TEXTURE::TerminateTexture()
{
	if (texturePointer != NULL) {
		SDL_DestroyTexture(texturePointer);
		texturePointer = NULL;
		textureWidth = 0;
		textureHeight = 0;
		posX = 0;
		posY = 0;
		textureScaleWidth = 1;
		textureScaleHeight = 1;
		textureAngle = 0;
		textureRed = 255;
		textureGreen = 255;
		textureBlue = 255;
		textureAlpha = 255;
		textureClip = NULL;
		textureCenter = NULL;
		textureFlip = SDL_FLIP_NONE;
		scaleCheck = false;
		rotateCheck = false;
		flipCheck = false;
		colorCheck = false;
		clipCheck = false;
	}
}