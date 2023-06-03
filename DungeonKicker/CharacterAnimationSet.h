#pragma once
#include "AnimationManager.h"
#include "CharacterType.h"


class CharacterAnimationSet
{
public:
	void Setup(SDL_Renderer* renderer, int x, int y, CharacterType type);
	void doIdle();
	void doAttack();
	void doHit();
	void Update(float dt);
	void Draw();
	
	int x, y;
	SDL_Renderer* renderer;
	Animation idle, attack, hit;
	AnimationManager animationManager;

	bool doAction;
};

