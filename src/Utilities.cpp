#include "Utilities.hpp"

SDL_Surface* LoadPNG(std::string path) {
    SDL_Surface *image_surface = IMG_Load(path.c_str());

    if(!image_surface)
        return 0;

    return image_surface;
}