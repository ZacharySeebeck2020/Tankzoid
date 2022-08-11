#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class RenderWindow
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
public:
	RenderWindow(int width, int height, const std::string title);
	void Update();
};