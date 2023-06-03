#pragma once
#include "Animation.h"


class AnimationManager
{

public:
	
	AnimationManager();
	void changeAnimation(Animation* animation);
	void setAnimationLooping(bool loopAnimation);
	void resetAnimation();
	void Update(float dt);
	void Draw(int x, int y);

	Animation* currentAnimation;
	int currentFrame;
	float frameTimer;
	bool animationEnded;
	bool loopAnimation;

private:


};

