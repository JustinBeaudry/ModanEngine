#ifndef MODANENGINE_MAP_H
#define MODANENGINE_MAP_H

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

#endif //MODANENGINE_MAP_H
