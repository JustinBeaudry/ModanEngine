#pragma once

#include "../TextureManager.h"
#include "Components.h"
#include "SDL2/SDL.h"

class Sprite : public Component {
private:

    Transform *transform;
    SDL_Texture *texture;
    SDL_Rect srcRect;
    SDL_Rect destRect;

public:

    Sprite() = default;
    Sprite(const char* path) {
        setTexture(path);
    }

    ~Sprite() {
        SDL_DestroyTexture(texture);
    }

    void setTexture(const char* path) {
        texture = TextureManager::LoadTexture(path);
    }

    void init() override {

        transform = &entity->getComponent<Transform>();

        srcRect.x = srcRect.y = 0;
        srcRect.w = transform->width;
        srcRect.h = transform->height;
    }

    void update() override {
        destRect.x = static_cast<int>(transform->position.x);
        destRect.y = static_cast<int>(transform->position.y);
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;
    }

    void draw() override {
        TextureManager::Draw(texture, srcRect, destRect);
    }
};