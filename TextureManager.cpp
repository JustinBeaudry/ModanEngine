#include "Game.h"
#include "TextureManager.h"

// @TODO:  update to use environment variables
const std::string BASE = "/Users/justinbeaudry/Projects/ModanEngine";
const std::string ASSETS = BASE + "/assets/";

SDL_Texture* TextureManager::LoadTexture(const char* fileName) {
    std::string texturePath = ASSETS + fileName;
    return IMG_LoadTexture(Game::renderer, texturePath.c_str());
};

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest) {
    SDL_RenderCopy(Game::renderer, texture, &src, &dest);
}