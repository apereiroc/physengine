//
// Created by Asier Pereiro Castro on 31/8/23.
//

#pragma once

#include <SDL2/SDL.h>
#include "Types.h"
#include "ColorWheel.h"


class PhysicsObject {
private:
    Vector position, velocity;
    Color color;
public:
    PhysicsObject(const Vector& position, const Vector& velocity,
                  const Color& color = ColorWheel::Get())
    : position(position), velocity(velocity), color(color){}

    PhysicsObject(const Vector& position, const Vector& velocity, const Colors& color)
    : position(position), velocity(velocity), color(ColorWheel::MakeColor(color)) {}

    virtual ~PhysicsObject() = default;

    [[nodiscard]] inline const Vector &getPosition() const { return position; }
    [[nodiscard]] inline const Vector &getVelocity() const { return velocity; }
    [[nodiscard]] inline const Color &getColor() const { return color; }

    virtual void Render(SDL_Renderer* render) const = 0;
};