#include "Game.h"
#include "GameObject.h"
#include "Map.h"

#include "ECS.h"
#include "Component.h"

GameObject* player;
GameObject* enemy;
Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& newPlayer(manager.addEntity());

Game::Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

    int flags = 0;

    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
        }
        isRunning = true;
    }

    player = new GameObject("player.png");
    enemy = new GameObject("enemy.png");
    map = new Map();

    newPlayer.addComponent<PositionComponent>();
}

Game::~Game() {}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;

        default:
            break;
    }
}

void Game::update() {
    player->Update();
    enemy->Update();
    manager.update();
    std::cout << newPlayer.getComponent<PositionComponent>().x() << "," <<
        newPlayer.getComponent<PositionComponent>().y() << std::endl;
}

void Game::render() {
    SDL_RenderClear(renderer);
    map->Draw();
    player->Render();
    enemy->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    player->Clean();
    enemy->Clean();
    SDL_Quit();
}