//
// Created by Asier Pereiro Castro on 31/8/23.
//

#pragma once

#include "PhysicsObject.h"
#include "Types.h"
#include <SDL2/SDL.h>


class Rectangle: public PhysicsObject {
private:
    double width, height;
public:
    Rectangle(const Vector& position, const Vector& velocity, const double& width,
              const double& height)
    : PhysicsObject(position, velocity), width(width), height(height) {}


    [[nodiscard]] inline double getWidth() const { return width; }

    [[nodiscard]] inline double getHeight() const { return height; }

    void Render(SDL_Renderer* render) const override {
        (void)render;
    }
};
