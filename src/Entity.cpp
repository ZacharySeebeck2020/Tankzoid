#include "Entity.hpp"
#include "Logger.h"

Entity::Entity(std::string p_name, SDL_Point p_activeSprite, SDL_Rect p_screenPosition): spritesheet("./assets/default_spritesheet1.png", 16, 16)
{
	name = p_name; activeSprite = p_activeSprite; screenPosition = p_screenPosition;
}

Entity::~Entity()
{
}

void Entity::Draw(SDL_Window* p_window) {
	Logger logger = Logger::getInstance();
	logger.log(std::to_string(screenPosition.h));
	logger.log(std::to_string(screenPosition.w));
	logger.log(std::to_string(screenPosition.x));
	logger.log(std::to_string(screenPosition.y));

	SDL_Surface* windowSurface = SDL_GetWindowSurface(p_window);
	spritesheet.SelectActiveSprite(activeSprite);
	spritesheet.DrawSelectedSprite(windowSurface, &screenPosition);
}