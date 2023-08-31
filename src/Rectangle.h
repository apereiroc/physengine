//
// Created by Asier Pereiro Castro on 31/8/23.
//

#pragma once

#include "PhysicsObject.h"
#include "Types.h"
#include <SDL2/SDL.h>

#include <utility>


class Rectangle: public PhysicsObject {
private:
    double width, height;

public:
    Rectangle(std::string name, const Vector& position, const Vector& velocity, const double& width,
              const double& height)
    : PhysicsObject(std::move(name), position, velocity), width(width), height(height) {}

    Rectangle(std::string name, const double& x, const double& y, const double& w, const double& h)
    : PhysicsObject(std::move(name), Vector(x, y), Vector(0, 0)), width(w), height(h) {}

    Rectangle(std::string name, const double& x, const double& y, const double& w, const double& h,
              const Colors& c)
            : PhysicsObject(std::move(name), Vector(x, y), Vector(0, 0), c), width(w), height(h) {}

    [[nodiscard]] inline double getWidth() const { return width; }
    [[nodiscard]] inline double getHeight() const { return height; }

    inline void setWidth(const double& w) { width = w; }
    inline void setHeight(const double& h) { height = h; }

    void Render(SDL_Renderer* renderer) const override {
        const Vector &pos = getPosition();
        SDL_Rect rect = {(int)pos.x(), (int)pos.y() - (int)height, (int)width, (int)height};
        const Color &c = getColor();

        SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
        SDL_RenderFillRect(renderer, &rect);
    }
};
