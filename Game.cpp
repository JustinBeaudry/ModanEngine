#include "Game.h"
#include "ECS/Components.h"
#include "Collision.h"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<Collider*> Game::colliders;

Manager manager;
auto& player(manager.addEntity());
auto& wall(manager.addEntity());

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

	for (auto cc : colliders) {
		Collision::AABB(player.getComponent<Collider>(), *cc);
	}
}

void Game::render() {
	SDL_RenderClear(renderer);
	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::AddTile(int id, int x, int y) {
	auto& tile(manager.addEntity());
	tile.addComponent<Tile>(x, y, 32, 32, id);
}