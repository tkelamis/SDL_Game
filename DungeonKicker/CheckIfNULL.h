#include <iostream>
#include <string>
#include <Windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#pragma once

int CheckifRendererIsNULL(SDL_Renderer* renderer);
int CheckifWindowIsNULL(SDL_Window* window);
int CheckifImageIsNULL(SDL_Texture* Image);