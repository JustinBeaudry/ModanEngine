#include "Map.h"
#include "TextureManager.h"

// Legend
// ---------
// 0 = water
// 1 = dirt
// 2 = grass
// ---------
int lvl[20][25] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,2,2,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,2,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

Map::Map() {
    water = TextureManager::LoadTexture("water.png");
    dirt = TextureManager::LoadTexture("dirt.png");
    grass = TextureManager::LoadTexture("grass.png");

    Load(lvl);

    src.x = src.y = dest.x = dest.y = 0;
    src.w = src.h = dest.w = dest.h = 32;
}

Map::~Map() {
    SDL_DestroyTexture(water);
    SDL_DestroyTexture(dirt);
    SDL_DestroyTexture(grass);
}

void Map::Load(int arr[20][25]) {
    for (int row = 0; row < 20; row++) {
        for (int column = 0; column < 25; column++) {
            map[row][column] = arr[row][column];
        }
    }
}

void Map::Draw() {
    int type = 0;

    for (int row = 0; row < 20; row++) {
        for (int column = 0; column < 25; column++) {

            type = map[row][column];

            dest.x = column * 32;
            dest.y = row * 32;

            switch(type) {
                case 0:
                    TextureManager::Draw(water, src, dest);
                    break;
                case 1:
                    TextureManager::Draw(dirt, src, dest);
                    break;
                case 2:
                    TextureManager::Draw(grass, src, dest);
                    break;
                default:
                    break;
            }
        }
    }
}