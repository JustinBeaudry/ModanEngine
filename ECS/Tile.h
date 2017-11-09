#pragma once

#include "ECS.h"
#include "Transform.h"
#include "Sprite.h"
#include "SDL2/SDL.h"

class Tile : public Component {
public:
	Transform *transform;
	Sprite *sprite;

	SDL_Rect tile;
	int tileID;
	char* path;

	Tile() = default;
	Tile(int x, int y, int w, int h, int id) {
		tile.x = x;
		tile.y = y;
		tile.w = w;
		tile.h = h;
		tileID = id;

		switch(tileID) {
			case 0:
				path = "water.png";
				break;
			case 1:
				path = "dirt.png";
				break;
			case 2:
				path = "grass.png";
				break;
			default:
				break;
		}
	}

	void init() override {
		entity->addComponent<Transform>(tile.x, tile.y, tile.w, tile.h, 1);
		transform = &entity->getComponent<Transform>();

		entity->addComponent<Sprite>(path);
		sprite = &entity->getComponent<Sprite>();
	}
};