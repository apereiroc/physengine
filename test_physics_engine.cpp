//
// Created by Asier Pereiro Castro on 31/8/23.
//

#include "PhysicsEngine.h"
#include "Rectangle.h"
#include <memory>

int main(){

    // Create engine
    auto p {std::make_unique<PhysicsEngine>()};

    // Create and add rectangle
    const std::string name = "Rectangle 1";
    p->addObject(new Rectangle(name, 0, 0, 50, 100));

    // Define a time step
    const double dt = 0.3;

    // Position should be (0,0), since the velocity is 0
    p->Simulate(dt);
    const Vector& p0 = p->getPosition(name);
    std::cout << "Position: " << p0.x() << ", " << p0.y() << std::endl;

    // Add movement. Position should change
    p->setVelocity(name, 3,-1);
    p->Simulate(dt);

    const Vector& p1 = p->getPosition(name);
    std::cout << "Position: " << p1.x() << ", " << p1.y() << std::endl;


    return 0;
}