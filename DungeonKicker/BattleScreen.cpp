#include "BattleScreen.h"

BattleScreen::BattleScreen(SDL_Renderer* renderer, Hero* hero, int* items)
{
	this->renderer = renderer;
	this->hero = hero;
	this->items = items;

	backroundTexture = IMG_LoadTexture(renderer, "assets/bg.png");

}

BattleScreen::~BattleScreen()
{
	SDL_DestroyTexture(backroundTexture);
}

void BattleScreen::Update()
{
	while (!battleFinished)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					quit = true;
			}
		}
		if (quit)
			battleFinished = true;

		Draw();
	}
}

void BattleScreen::Draw()
{
	SDL_Rect tileRect = { 0,0,40,40 };
	SDL_RenderCopy(renderer, backroundTexture, NULL, NULL);
	SDL_RenderPresent(renderer);
}
