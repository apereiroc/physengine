//
// Created by Asier Pereiro Castro on 31/8/23.
//

#pragma once

#include "PhysicsObject.h"
#include <vector>

class PhysicsEngine {
private:
    std::vector<PhysicsObject*> objects;

public:
    PhysicsEngine() {}

    void addObject(PhysicsObject *obj){
        objects.push_back(obj);
    }

    inline PhysicsObject *getObject(unsigned int index) const {
        return objects[index];
    }
    inline unsigned int getNumObjects() const {
        return static_cast<unsigned int>(objects.size());
    }

    void Simulate(const double& delta){
        for (auto obj : objects)
            obj->Integrate(delta);
    }

};
