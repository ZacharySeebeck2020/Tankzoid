#pragma once
#include <iostream>
#include <SDL.h>
#include <map>

static std::map<std::string, SDL_Point> Sprites {
	{ "PlayerTankBase", {0,0} },
	{ "PlayerTankBaseAlt", {0,1} },
	{ "PlayerTankTurret", {0,2} },

	{ "LightBlueTankBase", {1,0} },
	{ "LightBlueTankBaseAlt", {1,1} },
	{ "LightBlueTankTurret", {1,2} },

	{ "DarkPurpleTankBase", {2,0} },
	{ "DarkPurpleTankBaseAlt", {2,1} },
	{ "DarkPurpleTankTurret", {2,2} },

	{ "OrangeTankBase", {3,0} },
	{ "OrangeTankBaseAlt", {3,1} },
	{ "OrangeTankTurret", {3,2} },

	{ "TealTankBase", {4,0} },
	{ "TealTankBaseAlt", {4,1} },
	{ "TealTankTurret", {4,2} },

	{ "RedTankBase", {5,0} },
	{ "RedTankBaseAlt", {5,1} },
	{ "RedTankTurret", {5,2} },

	{ "LightPurpleTankBase", {6,0} },
	{ "LightPurpleTankBaseAlt", {6,1} },
	{ "LightPurpleTankTurret", {6,2} },

	{ "DarkBlueTankBase", {7,0} },
	{ "DarkBlueTankBaseAlt", {7,1} },
	{ "DarkBlueTankTurret", {7,2} },

	{ "MaroonTankBase", {8,0} },
	{ "MaroonTankBaseAlt", {8,1} },
	{ "MaroonTankTurret", {8,2} },

	{ "YellowAmmo", {4,0} },
	{ "BlueAmmo", {4,1} },
	{ "PinkAmmo", {4,2} },
	{ "GreenAmmo", {4,3} }
};