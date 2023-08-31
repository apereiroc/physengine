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
    auto r {std::make_unique<Rectangle>(0, 0, 50, 100)};
    p->addObject(r.get());

    // Define a time step
    const double dt = 0.3;

    // Position should be (0,0), since the velocity is 0
    p->Simulate(dt);
    const Vector& p0 = p->getObject(0)->getPosition();
    std::cout << "Position: " << p0.x() << ", " << p0.y() << std::endl;

    // Add movement. Position should change
    p->getObject(0)->setVelocity(3,-1);
    p->Simulate(dt);

    const Vector& p1 = p->getObject(0)->getPosition();
    std::cout << "Position: " << p1.x() << ", " << p1.y() << std::endl;


    return 0;
}