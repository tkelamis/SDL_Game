#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>


class InfoBox
{
public:
	bool visible = true;
	InfoBox();
	~InfoBox();

	void Setup(SDL_Renderer* renderer);
	void SetText(std::string text);
	void Draw();


	
private:
	SDL_Renderer* renderer;
	TTF_Font* font;
	std::string text;
	SDL_Texture* textTexture = NULL;
	SDL_Rect textRect;
	SDL_Rect boxRect;

};

