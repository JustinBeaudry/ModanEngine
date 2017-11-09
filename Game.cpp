#include "Game.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Collision.h"

Map* map;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<Collider*> Game::colliders;

Manager manager;
auto& player(manager.addEntity());
auto& wall(manager.addEntity());

auto& tile0(manager.addEntity());
auto& tile1(manager.addEntity());
auto& tile2(manager.addEntity());

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

	map = new Map();

	tile0.addComponent<Tile>(200, 200, 32, 32, 0);
	tile1.addComponent<Tile>(250, 250, 32, 32, 1);
	tile1.addComponent<Collider>("dirt");
	tile2.addComponent<Tile>(150, 150, 32, 32, 2);
	tile2.addComponent<Collider>("grass");

	player.addComponent<Transform>(2);
	player.addComponent<Sprite>("player.png");
	player.addComponent<KeyboardController>();
	player.addComponent<Collider>("player");

	wall.addComponent<Transform>(300.0f, 300.0f, 20, 300, 1);
	wall.addComponent<Sprite>("dirt.png");
	wall.addComponent<Collider>("wall");
}

Game::~Game() {}

void Game::handleEvents() {

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
	manager.refresh();
	manager.update();

	if (Collision::AABB(player.getComponent<Collider>().collider, wall.getComponent<Collider>().collider)) {
		player.getComponent<Transform>().velocity * -1;
	}
}

void Game::render() {
	SDL_RenderClear(renderer);
	map->Draw();
	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}