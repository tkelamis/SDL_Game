#include <iostream>
#include <string>
#include <Windows.h>
#include "Puzzles.h"
#include "Character.h"
#include "Glob.h"
#include "Hero.h"
#include "Mimic.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include"MapScreen.h"
#include "CharacterQuiz.h"
#include "SystemsInitialization.h"
#include "CheckIfNULL.h"
#include"InfoBox.h"
#include <vector>




int main(int argc,char** argv)
{
	Quiz();
	Setup();
	Initialize_Systems();

	SDL_Window* window = SDL_CreateWindow("Dungeon Kicker",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		640, 480, SDL_WINDOW_SHOWN);
	CheckifWindowIsNULL(window);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	CheckifRendererIsNULL(renderer);

	SDL_RenderSetLogicalSize(renderer,320,240);

	Hero Elanis;
	Elanis.SetHP(100);
	Elanis.displayStats();
	std::vector<int> items(10,0);
	
	MapScreen mapScreen(renderer, &Elanis, items);

	bool keepRunning = true;
	while (keepRunning)
	{
		mapScreen.update();
		if (mapScreen.IsQuit())
			keepRunning = false;

		mapScreen.draw();
		
		SDL_RenderPresent(renderer);
	}
	

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer); 
	SDL_Quit();

	system("pause");
	return 0;
}

