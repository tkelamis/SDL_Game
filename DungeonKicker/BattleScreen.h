#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "Glob.h"
#include "Hero.h"
#include "Mimic.h"
#include <list>

class BattleScreen
{
public:
	BattleScreen(SDL_Renderer* renderer,Hero* hero,int* items);
	~BattleScreen();

	void Update();
	void Draw();

	bool quit;
private:
	SDL_Renderer* renderer;
	SDL_Texture* backroundTexture;
	Hero* hero;
	int* items;
	Character* enemy;
	bool battleFinished;
	
	bool heroesTurn;




};
