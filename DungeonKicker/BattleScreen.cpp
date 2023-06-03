#include "BattleScreen.h"
#include <vector>

BattleScreen::BattleScreen(SDL_Renderer* renderer, Hero* hero, std::vector<int> inventory)
{
	this->renderer = renderer;
	this->hero = hero;
	this->inventory = inventory;

	backroundTexture = IMG_LoadTexture(renderer, "assets/bg.png");

	TTF_Font* font=TTF_OpenFont("assets/vermin_vibes_1989.ttf", 16);
	SDL_Color textColor = { 0,0,0,0 };
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, hero->getName().c_str(), textColor);
	nameTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);
	TTF_CloseFont(font);

	nameRect.x = 90;
	nameRect.y = 180;
	SDL_QueryTexture(nameTexture, NULL, NULL, &nameRect.w, &nameRect.h);

	heroAnimationSet.Setup(renderer, 47, 181, heroType);
}

BattleScreen::~BattleScreen()
{
	SDL_DestroyTexture(backroundTexture);
	SDL_DestroyTexture(nameTexture);
}

void BattleScreen::Update()
{
	float dt = 0;
	Uint32 lastUpdate = SDL_GetTicks();

	while (battleFinished == false)
	{
		Uint32 timeDiff = SDL_GetTicks() - lastUpdate;
		dt = timeDiff / 1000.0f;
		lastUpdate = SDL_GetTicks();

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

 		heroAnimationSet.Update(dt);

		Draw();
	}
}

void BattleScreen::Draw()
{
	SDL_RenderCopy(renderer, backroundTexture, NULL, NULL);
	heroAnimationSet.Draw();

	SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
	SDL_Rect bottomUIBar = { 0,180,320,60 };
	SDL_RenderFillRect(renderer, &bottomUIBar);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &bottomUIBar);
	SDL_RenderCopy(renderer, nameTexture, NULL, &nameRect);
	SDL_RenderPresent(renderer);

}
