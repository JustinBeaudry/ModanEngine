#pragma once

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* fileName);
    static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
};
