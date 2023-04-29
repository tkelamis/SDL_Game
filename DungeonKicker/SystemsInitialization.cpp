#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include <string>


int Initialize_Systems()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "SDL Init Error: " << SDL_GetError() << std::endl;
		system("pause");
		return 1;
	}

	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		std::cout << "SDL IMG Init Error: " << IMG_GetError() << std::endl;
		system("pause");
		return 1;
	}

	if (TTF_Init() != 0)
	{
		std::cout << "TTF Init Error: " << TTF_GetError() << std::endl;
		system("pause");
		return 1;
	}

	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		std::cout << "Mixer Init Error: " << Mix_GetError() << std::endl;
		system("pause");
		return 1;
	}
}