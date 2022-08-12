#pragma once
#include <iostream>
#include <SDL.h>
#include <map>

static std::map<std::string, SDL_Point> Sprites {
	{ "PlayerTankBase", {0,0} },
	{ "PlayerTankBaseAlt", {1,0} },
	{ "PlayerTankTurret", {0,1} },

	{ "YellowAmmo", {2,0} }
};