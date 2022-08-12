#include "Spritesheet.hpp"
#include "Logger.h"

Spritesheet::Spritesheet(std::string p_path, int p_rows, int p_columns) {
	spritesheetImage = LoadPNG(p_path);

	if (spritesheetImage == 0) {
		Logger::getInstance().log("Unable to load spritesheet at: " + p_path, LogLevel::LOG_FATAL);	
		exit(-1);	
	}

	clip.w = spritesheetImage->w / p_columns;
	clip.h = spritesheetImage->h / p_rows;
}

Spritesheet::~Spritesheet() {
	SDL_FreeSurface(spritesheetImage);
}

void Spritesheet::SelectActiveSprite(SDL_Point p_location) {
	clip.x = p_location.x * clip.w;
	clip.y = p_location.y * clip.h;
}

void Spritesheet::DrawSelectedSprite(SDL_Surface* p_windowSurface, SDL_Rect* p_position) {
	SDL_BlitSurface(spritesheetImage, &clip, p_windowSurface, p_position);
}