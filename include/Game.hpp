#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include "Entity.hpp"
#include "EntityManager.hpp"

class Game
{
private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	EntityManager entityManager;

public:
	Game();
	~Game();

	void Init(int width, int height, const std::string title);

	void HandleEvents();
	void Update();
	void Render();
	void Clean();

	bool Running() { return isRunning; }
};