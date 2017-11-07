#include "Game.h"
#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y) {
    texture = TextureManager::LoadTexture(texturesheet);

    xpos = x;
    ypos = y;
}

GameObject::~GameObject() {}

void GameObject::Update() {

    xpos++;
    ypos++;

    // default resolution is that of the supplied texture
    int w, h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    srcRect.w = w;
    srcRect.h = h;

    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
}

void GameObject::Render() {
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);
}

void GameObject::Clean() {
    SDL_DestroyTexture(texture);
}