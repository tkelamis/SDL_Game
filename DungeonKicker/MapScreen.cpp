#include "MapScreen.h"
#include"InfoBox.h"


MapScreen::MapScreen(SDL_Renderer* renderer, Hero* hero,int* items)
{
	srand(time(NULL));
	this->renderer = renderer;
	this->hero = hero;
	this->items = items;

	hero->SetHP(100);

	ScreenMapAndRender();

	heroTexture = IMG_LoadTexture(renderer, "assets/girlTile.png");
	doorTexture = IMG_LoadTexture(renderer, "assets/doorTile.png");
	chestTexture = IMG_LoadTexture(renderer, "assets/chestTile.png");
	globTexture = IMG_LoadTexture(renderer, "assets/globTile.png");
	rocktileTexture=IMG_LoadTexture(renderer, "assets/rock_tile.png");

	infoBox.Setup(renderer);
	infoBox.SetText("Welcome to the Dungeon E-li-ani !");
}

MapScreen::~MapScreen()
{
	SDL_DestroyTexture(heroTexture); SDL_DestroyTexture(doorTexture);
	SDL_DestroyTexture(chestTexture);SDL_DestroyTexture(globTexture);
}



void MapScreen::ItemFound()
{
	int item = rand() % 4 + 1;
	bool freeSlotFound = true;  //κανονικά αυτό είναι false αλλά μου έβγαζε bug full.στο array items δεν γεμίζουν οι τιμές με 0. Αλέξανδρος
	//επίσης πως να δωσω αίμα στον ηρωα μοθ
	for (int i = 0; i > 10; i++) {
		if (items[i] == 0) {
			freeSlotFound = true;
			items[i] = item;
			break;
		}
	}
	if (freeSlotFound) {
		if (item == 1)
			infoBox.SetText("Found a chocolate!!");
		else if (item == 2)
			infoBox.SetText("Found a grenade!!");
		else if (item == 3)
			infoBox.SetText("Found an ATK boost candy!!");
		else if (item == 4)
			infoBox.SetText("Found a DEF boost candy!!");
	}
	else
		infoBox.SetText("You're bag is full!!");
	infoBox.visible = true;
}

void MapScreen::update()
{
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent))
	{
		if (sdlEvent.type == SDL_QUIT)
			quit = true;
		if (sdlEvent.type == SDL_KEYDOWN) {
			if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_ESCAPE) { quit = true; }
			if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_SPACE) { infoBox.visible=false; }

			if (!infoBox.visible && hero->getHP() >= 0)
			{
				int hero_x = heroObj.x;
				int hero_y = heroObj.y;
				if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_RIGHT) { hero_x++; }
				if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_LEFT) { hero_x--; }
				if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_UP) { hero_y--; }
				if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_DOWN) { hero_y++; }
				if (hero_x >= 0 && hero_x <= 9 && hero_y >= 0 && hero_y <= 9
					&& Map[hero_x][hero_y] == 1) {
					heroObj.x = hero_x;
					heroObj.y = hero_y;

					

					if (!doorLocked && !escaped && heroObj.x == door.x && heroObj.y == door.y) {
						infoBox.SetText("You escaped the Dungeon alive!!");
						infoBox.visible = true;
						escaped = true;
					}

					std::list<MapObject>::iterator it;
					for (it = mapObjects.begin(); it != mapObjects.end(); ++it) {
						if (it->active) {
							if (hero_x == it->x && hero_y == it->y) {
								it->active = false;
								if (it->type == 3)
								{
									BattleScreen battle(renderer, hero, items);
									battle.Update();
									if (battle.quit == true)
										quit = true;
								}
								else if (it->type == 2)
								{
								}
								else if (it->type == 4)
								{
									ItemFound();
								}
							}
						}
					}
				}
			}
		}
	}

	if (!infoBox.visible && doorLocked)
	{
		bool monstersAlive = false;
		for (MapObject mo : mapObjects) {
			if (mo.type == 3) {
				if (mo.active) {
					monstersAlive = true;
					break;
				}
			}
		}
		if (!monstersAlive) {
			doorLocked = false;
			infoBox.SetText("The door is unlocked!!");
			infoBox.visible = true;
		}
	}

	if (!infoBox.visible && escaped)
	{
		quit = true;
	}

}

void MapScreen::draw()
{
	SDL_Rect tileRect = { 0,0,32,32 };

	for (int x = 0; x <= 9; x++) {
		for (int y = 0; y <= 9; y++)
		{
			if (Map[x][y] == 1)
			{
				SDL_SetRenderDrawColor(renderer, 77, 55, 39, 255);
			}
			else if (Map[x][y] == 0)
			{
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			}
			tileRect.x = x * tileRect.w;
			tileRect.y = y * tileRect.h;
			SDL_RenderFillRect(renderer, &tileRect);
		}
	}

	tileRect.x = heroObj.x * tileRect.w;
	tileRect.y = heroObj.y * tileRect.h;
	SDL_RenderCopy(renderer, heroTexture, NULL, &tileRect);

	tileRect.x = door.x * tileRect.w;
	tileRect.y = door.y * tileRect.h;
	SDL_RenderCopy(renderer, doorTexture, NULL, &tileRect);

	for (MapObject mo : mapObjects)
	{
		if (mo.active)
		{
			tileRect.x = mo.x * tileRect.w;
			tileRect.y = mo.y * tileRect.h;
			if (mo.type == 3)
				SDL_RenderCopy(renderer, globTexture, NULL, &tileRect);
			if (mo.type == 4)
				SDL_RenderCopy(renderer, chestTexture, NULL, &tileRect);
			if (mo.type == 5)
				SDL_RenderCopy(renderer, rocktileTexture, NULL, &tileRect);
		}
	}
	infoBox.Draw();
}

void MapScreen::ScreenMapAndRender()
{
	for (int x = 0; x <= 9; x++) {
		for (int y = 0; y <= 9; y++)
			Map[x][y] = 0;
	}

	std::fstream mapFile("assets/map.txt");
	if (mapFile.is_open())
	{
		for (int y = 0; y <= 9; y++) {
			for (int x = 0; x <= 9; x++) {
				char grid;
				mapFile >> grid;
				if (grid == '0')
					Map[x][y] = 0;
				else
					Map[x][y] = 1;

				if (grid == 'h') {
					heroObj.type = 1; heroObj.x = x; heroObj.y = y;
				}
				else if (grid == 'd') {
					door.type = 2; door.x = x; door.y = y;
				}
				else if (grid == 'c') {
					MapObject chest;
					chest.type = 4; chest.x = x; chest.y = y;
					mapObjects.push_back(chest);
				}
				else if (grid == 'g') {
					MapObject glob;
					glob.type = 3;
					glob.x = x; glob.y = y;
					mapObjects.push_back(glob);
				}
				else if (grid == 'm') {
					MapObject mimic;
					mimic.type = 4;
					mimic.x = x; mimic.y = y;
					mapObjects.push_back(mimic);
				}
				else if (grid == '0') {
					MapObject rocks;
					rocks.type = 5;
					rocks.x = x; rocks.y = y;
					mapObjects.push_back(rocks);
				}
			}
		}
	}
	mapFile.close();
}
