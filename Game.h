#pragma once

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>

class Game {
public:
    Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    ~Game();

    void handleEvents();
    void update();
    void render();
    void clean();

    static SDL_Renderer *renderer;

    bool running() {
        return isRunning;
    }

private:
    bool isRunning;
    SDL_Window *window;
};
