#pragma once
#include <iostream>
#include <SDL.h>
#include "Utilities.hpp"

class Spritesheet {
private: 
	SDL_Rect clip;
	SDL_Surface *spritesheetImage;

public:
	Spritesheet(std::string p_path, int p_rows, int p_columns);
	~Spritesheet();

	void SelectActiveSprite(SDL_Point p_location);
	void DrawSelectedSprite(SDL_Surface* p_windowSurface, SDL_Rect* p_position);
};