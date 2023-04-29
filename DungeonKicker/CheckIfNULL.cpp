#include "CheckIfNULL.h"

int CheckifRendererIsNULL(SDL_Renderer* renderer)
{
	if (renderer == NULL)
	{
		std::cout << "SDL renderer error" << SDL_GetError << std::endl;
		SDL_Quit();
		system("pause");
		return 1;
	}
}

int CheckifWindowIsNULL(SDL_Window* window)
{
	if (window == NULL)
	{
		std::cout << "SDL window error" << SDL_GetError << std::endl;
		SDL_Quit();
		system("pause");
		return 1;
	}
}

int CheckifImageIsNULL(SDL_Texture* Image)
{
	if (Image == NULL)
	{
		std::cout << "testImage creation did not work!!" << std::endl;
	}
	return 0;
}

