#pragma once

#include "Game.h"

class Map {
public:

    Map();
    ~Map();


    void Load(int arr[20][25]);
    void Draw();

private:

    SDL_Rect src;
    SDL_Rect dest;

    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;

    int map[20][25];
};
