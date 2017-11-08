#pragma once

#include <SDL2/SDL.h>

class GameObject {

public:
    GameObject(const char* texturesheet, int x = 0, int y = 0);
    ~GameObject();

    void Update();
    void Render();
    void Clean();

private:

    int xpos;
    int ypos;

    SDL_Texture* texture;
    SDL_Rect srcRect;
    SDL_Rect destRect;
    SDL_Renderer* renderer;
};
