#include "RenderWindow.hpp"
#include "Logger.h"

RenderWindow::RenderWindow(int width, int height, const std::string title):
	window(nullptr),
	renderer(nullptr)
{
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		Logger::getInstance().log("Failed to create window", LogLevel::LOG_FATAL);	
		Logger::getInstance().log("SDL_CreateWindow Error: " + std::string(SDL_GetError()), LogLevel::LOG_FATAL);
		exit(1);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		Logger::getInstance().log("Failed to create renderer", LogLevel::LOG_FATAL);
		Logger::getInstance().log("SDL_CreateRenderer Error: " + std::string(SDL_GetError()), LogLevel::LOG_FATAL);
		exit(1);
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void RenderWindow::Update() {
	SDL_Rect rect = {0, 0, 64, 64};
	SDL_Color color = {100, 100, 100, 255};

	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer);
}