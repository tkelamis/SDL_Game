#include "Animation.h"

void Animation::Setup(std::string spriteSheetFileName, SDL_Renderer* renderer,
	int numberOfFrames, float frameDuration, int offsetX, int offsetY)
{
	this->renderer = renderer;
	this->spriteSheet = IMG_LoadTexture(renderer, spriteSheetFileName.c_str());

	int w, h;
	SDL_QueryTexture(spriteSheet, NULL, NULL, &w, &h);
	frameWidth = w / numberOfFrames;
	frameHeight = h;

	this->numbrerOfFrames = numberOfFrames;
	this->frameDuration = frameDuration;
	this->offsetX = offsetX;
	this->offsetY = offsetY;

}

Animation::~Animation()
{
	if (spriteSheet != NULL)
	{
		SDL_DestroyTexture(spriteSheet);
	}
}

void Animation::Draw(int frame, int x, int y)
{
	SDL_Rect clip;
	clip.x = frame * frameWidth;
	clip.y = 0;
	clip.w = frameWidth;
	clip.h = frameHeight;

	SDL_Rect destinationRect = { x - offsetX,y - offsetY,frameWidth,frameHeight };
	SDL_RenderCopy(renderer, spriteSheet, &clip, &destinationRect);
}
