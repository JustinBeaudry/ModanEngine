#pragma once

#include "ECS.h"
#include "../Vector2D.h"

class Transform : public Component {
public:
    Vector2D position;
    Vector2D velocity;

    int height = 32;
    int width = 32;
    int scale = 1;

    int speed = 3;

    Transform() {
        position.Zero();
    }

    Transform(int s) {
        position.Zero();
        scale = s;
    }

    Transform(float x, float y) {
        position.x = x;
        position.y = y;
    }

    Transform(float x, float y, int w, int h, int s) {
        position.x = x;
        position.y = y;
        width = w;
        height = h;
        scale = s;
    }

    void init() override {
        velocity.Zero();
    }

    void update() override {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }
};