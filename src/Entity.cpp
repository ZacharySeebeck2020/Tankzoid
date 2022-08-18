#include "Entity.hpp"
#include "Logger.h"

Entity::Entity(std::string p_name, SDL_Point p_activeSprite, SDL_Rect p_screenPosition, SDL_Renderer* p_renderer)
{
	name = p_name; activeSprite = p_activeSprite; screenPosition = p_screenPosition; renderer = p_renderer; spritesheet = Spritesheet::getInstance();
	
}

Entity::~Entity()
{
}

void Entity::HandleEvents(SDL_Event event)
{

}

void Entity::Update() {

}

void Entity::Draw() {
	SDL_Renderer* tstRenderer = renderer;
	spritesheet->SelectActiveSprite(activeSprite);
	spritesheet->DrawSelectedSprite(renderer, &screenPosition);
}