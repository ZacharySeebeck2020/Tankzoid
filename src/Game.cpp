#include "Game.hpp"
#include "Logger.h"
#include "Entity.hpp"
#include "Sprite.hpp"

Game::Game() {}
Game::~Game() {}

void Game::Init(int width, int height, const std::string title) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
		Logger::getInstance().log("SDL_Init Error: " + std::string(SDL_GetError()), LogLevel::LOG_FATAL);
		exit(1);
	}

	if (!IMG_Init(IMG_INIT_PNG)) {
		Logger::getInstance().log("IMG_Init Error: " + std::string(IMG_GetError()), LogLevel::LOG_FATAL);
		exit(1);
	}

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		Logger::getInstance().log("Failed to create window", LogLevel::LOG_FATAL);
		Logger::getInstance().log("SDL_CreateWindow Error: " + std::string(SDL_GetError()), LogLevel::LOG_FATAL);
		exit(-1);
	}
	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED || SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL) {
		Logger::getInstance().log("Failed to create renderer", LogLevel::LOG_FATAL);
		Logger::getInstance().log("SDL_CreateRenderer Error: " + std::string(SDL_GetError()), LogLevel::LOG_FATAL);
		exit(1);
	}

	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);

	isRunning = true;
}

void Game::HandleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		
		default:
			break;
	}
}

void Game::Update() {}

void Game::Render() {
	SDL_RenderClear(renderer);

	Entity playerTank = {"Player", Sprites["PlayerTankBase"], {32,32}};
	playerTank.Draw(window);

	SDL_UpdateWindowSurface(window);
}

void Game::Clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	Logger::getInstance().log("Goodbye! :) ", LogLevel::LOG_INFO);
}

