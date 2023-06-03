#include "CharacterAnimationSet.h"

void CharacterAnimationSet::Setup(SDL_Renderer* renderer, int x, int y, CharacterType type)
{
	this->renderer = renderer;
	this->x = x;
	this->y = y;

	if (type == heroType)
	{
		idle.Setup("assets/girlIdle.png", renderer, 1, 1, 40, 132);
		idle.Setup("assets/girlPunch.png", renderer, 3, 0.1f, 69, 155);
		hit.Setup("assets/girlHit.png", renderer, 2, 0.1f, 47, 145);
	}
	else if (type == globType)
	{
		idle.Setup("assets/globIdle.png", renderer, 1, 1, 36, 105);
		idle.Setup("assets/globBite.png", renderer, 3, 0.1f, 93, 123);
		hit.Setup("assets/globHit.png", renderer, 2, 0.1f, 62, 150);
	}
	else if (type == mimicType)
	{
		idle.Setup("assets/mimicIdle.png", renderer, 1, 1, 36, 105);
		idle.Setup("assets/mimicAttack.png", renderer, 4, 0.1f, 151, 113);
		hit.Setup("assets/mimicHit.png", renderer, 2, 0.1f, 45, 69);
	}


	doIdle();

}

void CharacterAnimationSet::doIdle()
{
	animationManager.changeAnimation(&idle);
	animationManager.setAnimationLooping(true);
	doAction = false;
}

void CharacterAnimationSet::doAttack()
{
	animationManager.changeAnimation(&attack);
	animationManager.setAnimationLooping(false);
	doAction = true;
}

void CharacterAnimationSet::doHit()
{
	animationManager.changeAnimation(&hit);
	animationManager.setAnimationLooping(false);
	doAction = true;
}

void CharacterAnimationSet::Update(float dt)
{
	animationManager.Update(dt);
	if (animationManager.animationEnded && doAction)
	{
		doIdle();
	}
}

void CharacterAnimationSet::Draw()
{
	animationManager.Draw(x, y);
}


