#include "InfoBox.h"


InfoBox::InfoBox()
{
	font = TTF_OpenFont("assets/vermin_vibes_1989.ttf", 16);
}

InfoBox::~InfoBox()
{
	if (textTexture != NULL)
		SDL_DestroyTexture(textTexture);
	TTF_CloseFont(font);
}

void InfoBox::Setup(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

void InfoBox::SetText(std::string text)
{
	if (this->text != text && text != "")
	{
		if (textTexture != NULL)
			SDL_DestroyTexture(textTexture);
		this->text = text;
	}
	SDL_Color textColor = { 0,0,0,0 };
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, text.c_str(), textColor);
	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);
	
	SDL_QueryTexture(textTexture, NULL, NULL, &textRect.w, &textRect.h);
	textRect.x = 320 / 2 - textRect.w / 2;
	textRect.y = 240 / 2 - textRect.h / 2;

	boxRect.x= textRect.x - 4;
	boxRect.y = textRect.y - 4;
	boxRect.w = textRect.w +8;
	boxRect.h = textRect.h +8;
}
void InfoBox::Draw()
{
	if (visible && textTexture != NULL && text != "")
	{
		SDL_SetRenderDrawColor(renderer, 217, 43, 90, 255);
		SDL_RenderFillRect(renderer, &boxRect);

		SDL_SetRenderDrawColor(renderer, 255,255,255,255);
		SDL_RenderDrawRect(renderer, &boxRect);

		SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
	}

}