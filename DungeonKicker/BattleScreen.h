#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "Glob.h"
#include "Hero.h"
#include "Mimic.h"
#include <list>
#include <vector>
#include <SDL_ttf.h>
#include "CharacterType.h"
#include "CharacterAnimationSet.h"


class BattleScreen
{
public:
	BattleScreen(SDL_Renderer* renderer,Hero* hero, std::vector<int> inventory);
	~BattleScreen();

	void Update();
	void Draw();

	bool quit;

	CharacterAnimationSet heroAnimationSet;
	CharacterAnimationSet enemyAnimationSet;

private:
	SDL_Renderer* renderer;
	SDL_Texture* backroundTexture;
	SDL_Texture* nameTexture;
	SDL_Rect nameRect;
	Hero* hero;
	std::vector<int> inventory;
	Character* enemy;
	bool battleFinished;
	bool heroesTurn;




};
