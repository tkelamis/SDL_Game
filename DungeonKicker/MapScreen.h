#pragma once
#include "Hero.h"
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <fstream>
#include "MapObject.h"
#include <list>
#include"InfoBox.h"
#include <stdlib.h>
#include <time.h>
#include "BattleScreen.h";

class MapScreen
{
public:
	inline bool IsQuit() { return quit; }
	MapScreen(SDL_Renderer* renderer, Hero* hero,int* items);
	~MapScreen();

	void ItemFound();
	void update();
	void draw();
	

private:
	void ScreenMapAndRender();
	Hero* hero;
	SDL_Renderer* renderer;
	
	bool doorLocked = true;
	bool escaped = false;
	bool quit = false;

	int* items;
	int Map[10][10];
	MapObject heroObj;
	MapObject door;
	std::list<MapObject> mapObjects;
	SDL_Texture* heroTexture, * doorTexture, * globTexture, * chestTexture,*rocktileTexture;
	InfoBox infoBox;
};

