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
    Rectangle(const std::string& name, const Vector& position, const Vector& velocity, const double& width,
              const double& height)
    : PhysicsObject(name, position, velocity), width(width), height(height) {}

    Rectangle(const std::string& name, const double& x, const double& y, const double& w, const double& h)
    : PhysicsObject(name, Vector(x, y), Vector(0, 0)), width(w), height(h) {}

    ~Rectangle(){ std::cout << "Destroying Rectangle" << std::endl; }

    [[nodiscard]] inline double getWidth() const { return width; }
    [[nodiscard]] inline double getHeight() const { return height; }

    inline void setWidth(const double& w) { width = w; }
    inline void setHeight(const double& h) { height = h; }

    void Render(SDL_Renderer* render) const override {
        (void)render;
    }
};
