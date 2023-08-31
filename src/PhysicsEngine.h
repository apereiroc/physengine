//
// Created by Asier Pereiro Castro on 31/8/23.
//

#pragma once

#include "PhysicsObject.h"
#include <map>
#include <memory>

class PhysicsEngine {
private:
    std::map<std::string, std::unique_ptr<PhysicsObject>> objects;
    unsigned int nObjects = 0;

public:
    PhysicsEngine() = default;

    ~PhysicsEngine(){ std::cout << "Destroying physics engine" << std::endl;}

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

    void Simulate(const double& delta){
        std::map<std::string, std::unique_ptr<PhysicsObject>>::iterator it;
        for(it=objects.begin(); it!=objects.end(); ++it){
            it->second->Integrate(delta);
        }
    }

};
