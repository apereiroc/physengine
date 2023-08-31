//
// Created by Asier Pereiro Castro on 31/8/23.
//

#pragma once

#include "Types.h"
#include "ColorWheel.h"

class PhysicsObject {
private:
    Vector position, velocity;
    Color color;
public:
    PhysicsObject(const Vector& position, const Vector& velocity)
    : position(position), velocity(velocity), color(ColorWheel::Get()){}

    PhysicsObject(const Vector& position, const Vector& velocity, const Colors& color)
    : position(position), velocity(velocity), color(ColorWheel::MakeColor(color)) {}

    virtual ~PhysicsObject() {}

    inline const Vector &GetPosition() const { return position; }
    inline const Vector &GetVelocity() const { return velocity; }
    inline const Color &GetColor() const { return color; }
};
