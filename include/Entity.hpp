#pragma once
#include <iostream>
#include <SDL.h>
#include "Spritesheet.hpp"

class Entity
{
protected:
	std::string name;
	SDL_Rect screenPosition; 
	SDL_Point activeSprite;
	Spritesheet* spritesheet;
	SDL_Renderer* renderer;

public:
	Entity(std::string p_name, SDL_Point p_activeSprite, SDL_Rect p_screenPosition, SDL_Renderer* p_renderer);
	~Entity();

	virtual void HandleEvents(SDL_Event event);
	virtual void Update();
	virtual void Draw();

};