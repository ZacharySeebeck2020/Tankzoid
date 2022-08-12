#pragma once
#include <iostream>
#include <SDL.h>
#include "Spritesheet.hpp"

class Entity
{
private:
	std::string name;
	SDL_Rect screenPosition; 
	SDL_Point activeSprite;
	Spritesheet spritesheet;

public:
	Entity(std::string p_name, SDL_Point p_activeSprite, SDL_Rect p_screenPosition);
	~Entity();

	void Draw(SDL_Window* p_window);

};