#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

class Animation1
{
public:

	void Setup(std::string spriteSheetFileName, SDL_Renderer* renderer, int numberOfFrames,float frameDuration,
	int offsetX,int offsetY);
	~Animation();

	void Draw(int frame, int x, int y);
	float frameDuration;


	int numbrerOfFrames;
	int frameWidth, frameHeight;
	int offsetX, offsetY;
	
	SDL_Texture* spriteSheet;
	SDL_Renderer* renderer;

};

