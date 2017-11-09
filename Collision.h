#pragma once

#include "SDL2/SDL.h"

class Collider;

// AABB - Axis Aligned Bounding Box
class Collision {
public:
	static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
	static bool AABB(const Collider& colA, const Collider& colB);
};