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

TEXTURE::TEXTURE()
{
	texturePointer = NULL;
	textureWidth = 0;
	textureHeight = 0;
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
			printf("Unable to create texture from %s! SDL Error: %s\n", filePath.c_str(), SDL_GetError());
			return(false);
		}
		else {
			LOGGING::LogSuccess("Genorated texture from surface " + filePath, "Texture.cpp/TEXTURE/LoadTexture");
			textureWidth = loadedSurface->w;
			textureHeight = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
	}
	texturePointer = newTexture;
	return(true);
}

void TEXTURE::TerminateTexture()
{
	if (texturePointer != NULL) {
		SDL_DestroyTexture(texturePointer);
		texturePointer = NULL;
		textureWidth = 0;
		textureHeight = 0;
	}
}

void TEXTURE::SetColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(texturePointer, red, green, blue);
}

void TEXTURE::RenderSet(int x, int y, SDL_Rect * clip)
{
	SDL_Rect renderQuad = { x, y, textureWidth, textureHeight };
	if (clip != NULL) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopy(rendererPointer, texturePointer, clip, &renderQuad);
}

void TEXTURE::Render()
{
	RenderSet(posX, posY, renderClip);
}

void TEXTURE::GetSize(int & width, int & height)
{
	width = textureWidth;
	height = textureHeight;
}

void TEXTURE::SetRenderer(SDL_Renderer * pointer)
{
	rendererPointer = pointer;
}

void TEXTURE::SetPos(int x, int y)
{
	posX = x;
	posY = y;
}

void TEXTURE::SetClip(SDL_Rect * clip)
{
	renderClip = clip;
}