#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

SDL_Texture* LoadPNG(std::string p_path, SDL_Renderer* p_renderer);
