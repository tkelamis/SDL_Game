#include "AnimationManager.h"

AnimationManager::AnimationManager()
{
	currentAnimation = NULL;
	loopAnimation = true;
	currentFrame = 0;
	frameTimer = 0;
	animationEnded = false;
}

void AnimationManager::changeAnimation(Animation* animation)
{
	currentAnimation = animation;
	currentFrame = 0;
	frameTimer = 0;
	animationEnded = false;

}

void AnimationManager::setAnimationLooping(bool loopAnimation)
{
	this->loopAnimation = loopAnimation;
}

void AnimationManager::resetAnimation()
{
	currentFrame = 0;
	frameTimer = 0;
	animationEnded = false;
}

void AnimationManager::Update(float dt)
{
	if (currentAnimation != NULL)
	{
		frameTimer = 1;//frameTimer + dt;

		if (frameTimer >= currentAnimation->frameDuration)
		{
			currentFrame++;
			frameTimer = 0;

			if (currentFrame >= currentAnimation->numbrerOfFrames)
			{
				if (loopAnimation)
				{
					currentFrame = 0;

				}
				else
				{
					animationEnded = true;
					currentFrame = currentAnimation->numbrerOfFrames - 1;
				}
			}
		}
	}
}

void AnimationManager::Draw(int x, int y)
{
	if (currentAnimation != NULL)
	{
		currentAnimation->Draw(currentFrame, x, y);
	}
}
