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
	//Quiz();
	//Setup();
	Initialize_Systems();

	Hero Elanis;

	Elanis.SetHP(100);
	std::cout << Elanis.getName() << std::endl;
	Glob Globbertroter;
	std::cout << Elanis.getName() << std::endl;
	Elanis.takeDamage(Globbertroter.getDamage());
	Globbertroter.takeDamage(Elanis.getDamage());	Elanis.displayStats();
	Globbertroter.displayStats();


	SDL_Window* window = SDL_CreateWindow("Dungeon Kicker",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		640, 480, SDL_WINDOW_SHOWN);
	CheckifWindowIsNULL(window);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	CheckifRendererIsNULL(renderer);

	SDL_RenderSetLogicalSize(renderer,320,240);

	SDL_Texture* testImage = IMG_LoadTexture(renderer, "assets/girlIdle.png");
	CheckifImageIsNULL(testImage);


	
	std::vector<int> items(10,0);
	for (int i = 0; i <= 9; i++)
		std::cout << "Item in slot "<<i+1<<" is " << items[i] << std::endl;

	MapScreen mapScreen(renderer, &Elanis, items);

	bool keepRunning = true;
	Elanis.displayStats();
	while (keepRunning)
	{
		SDL_SetRenderDrawColor(renderer, 21, 209, 249, 255);
		SDL_RenderClear(renderer);

		SDL_Rect source_Rectangle;
		source_Rectangle.x = 0;
		source_Rectangle.y = 0;
		source_Rectangle.h = 137;
		source_Rectangle.w = 107;

		SDL_Rect dest_Rectangle;
		dest_Rectangle.x = 70;
		dest_Rectangle.y = 30;
		dest_Rectangle.h = 70;
		dest_Rectangle.w = 50;

		SDL_RenderCopy(renderer, testImage, &source_Rectangle, &dest_Rectangle);

		mapScreen.update();
		if (mapScreen.IsQuit())
			keepRunning = false;

		mapScreen.draw();
		

		SDL_RenderPresent(renderer);
	}
	

	SDL_DestroyTexture(testImage); SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer); SDL_Quit();

	system("pause");
	return 0;
}

