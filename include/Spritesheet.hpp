#pragma once
#include <iostream>
#include <SDL.h>
#include "Utilities.hpp"

class Spritesheet {
private: 
	Spritesheet() {};
	SDL_Rect clip;
	SDL_Texture *spritesheetImage;

public:
	static Spritesheet* getInstance() {
		static Spritesheet instance;
		return &instance;
	};
	
	void LoadSpritesheet(std::string p_path, int p_rows, int p_columns, SDL_Renderer* p_renderer);
	void SelectActiveSprite(SDL_Point p_location);
	void DrawSelectedSprite(SDL_Renderer* p_renderer, SDL_Rect* p_position, double p_angle = 0);
};