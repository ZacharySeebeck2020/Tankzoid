#include "Spritesheet.hpp"
#include "Logger.h"

void Spritesheet::LoadSpritesheet(std::string p_path, int p_rows, int p_columns, SDL_Renderer* p_renderer) {
	spritesheetImage = LoadPNG(p_path, p_renderer);

	if (spritesheetImage == 0) {
		Logger::getInstance().log("Unable to load spritesheet at: " + p_path, LogLevel::LOG_FATAL);	
		exit(-1);	
	}

	SDL_Point spritesheetSize;
	SDL_QueryTexture(spritesheetImage, NULL, NULL, &spritesheetSize.x, &spritesheetSize.y);
	clip.w = spritesheetSize.x / p_columns;
	clip.h = spritesheetSize.y / p_rows;
}

void Spritesheet::SelectActiveSprite(SDL_Point p_location) {
	clip.x = p_location.x * clip.w;
	clip.y = p_location.y * clip.h;
}

void Spritesheet::DrawSelectedSprite(SDL_Renderer* p_renderer, SDL_Rect* p_position, double p_angle) {
	SDL_RenderCopyEx(p_renderer, spritesheetImage, &clip, p_position, p_angle, NULL, SDL_FLIP_NONE);
}