//
// Created by Asier Pereiro Castro on 31/8/23.
//

#pragma once

#include "PhysicsObject.h"
#include "Types.h"
#include <map>
#include <memory>
#include <functional>


class PhysicsEngine {
private:
    ObjMap objects;
    unsigned int nObjects = 0;

public:
    PhysicsEngine() = default;

    void addObject(PhysicsObject* obj){
        objects[obj->getName()] = std::unique_ptr<PhysicsObject>(obj);
        nObjects++;
    }

    [[nodiscard]] inline unsigned int getNumObjects() const { return nObjects; }

    [[nodiscard]] inline const Vector &getPosition(const std::string& name) { return objects[name]->getPosition(); }
    [[nodiscard]] inline const Vector &getVelocity(const std::string& name) { return objects[name]->getVelocity(); }
    [[nodiscard]] inline const Color &getColor(const std::string& name) { return objects[name]->getColor(); }

    inline void setPosition(const std::string& name, const Vector& v){ objects[name]->setPosition(v);}
    inline void setPosition(const std::string& name, const double& x, const double& y) { objects[name]->setPosition(x, y); }

    inline void setVelocity(const std::string& name, const Vector& v){ objects[name]->setVelocity(v);}
    inline void setVelocity(const std::string& name, const double& x, const double& y) { objects[name]->setVelocity(x, y); }

    inline void setColor(const std::string& name, const Color& c) { objects[name]->setColor(c); }
    inline void setColor(const std::string& name, const Colors& c) { objects[name]->setColor(c); }

    inline void Integrate(const double& delta){
        ObjMap::iterator it;
        for (it = objects.begin(); it != objects.end(); it++){
            it->second->Integrate(delta);
        }
    }

    // Pass a lambda function to apply to all objects in the engine
    inline void applyToObjects(const std::function<void(const std::unique_ptr<PhysicsObject>&)>& fun){
        ObjMap::iterator it;
        for (it = objects.begin(); it != objects.end(); it++){
            fun(it->second);
        }
    }
};
