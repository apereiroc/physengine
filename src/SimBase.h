//
// Created by Asier Pereiro Castro on 31/8/23.
//

#pragma once

#include <memory>
#include "PhysicsEngine.h"
#include "RenderingEngine.h"
#include "Rectangle.h"

enum Shape {
    Rectangle,

    NUMSHAPES
};

class SimBase {
protected:
    std::unique_ptr<PhysicsEngine> phys;
    std::unique_ptr<RenderingEngine> rend;
public:
    SimBase()
    : phys(new PhysicsEngine()),
      rend(new RenderingEngine()) {}

    template<typename ...Args>
    inline void addShape(const Shape& s, const std::string& name, const Args&... args) {
        switch (s) {
            case Rectangle:
                phys->addObject(new class Rectangle(name, args...));
                break;
            default:
                exit(1);
        }
    }

    // Make class abstract. Each derivation should implement the game and end conditions
    virtual void Run() const = 0;
    [[nodiscard]] virtual bool endCondition() const = 0;
};
