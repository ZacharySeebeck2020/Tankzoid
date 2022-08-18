#include "Utilities.hpp"

SDL_Texture* LoadPNG(std::string p_path, SDL_Renderer* p_renderer) {
    SDL_Texture *image_surface = IMG_LoadTexture(p_renderer, p_path.c_str());

    if(!image_surface)
        return 0;

    return image_surface;
}