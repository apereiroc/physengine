//
// Created by Asier Pereiro Castro on 31/8/23.
//

#include <iostream>
#include "Rectangle.h"
#include "Types.h"

void printRectangleInfo(Rectangle* r){
    const Vector& pos = r->getPosition();
    const Vector& vel = r->getVelocity();

    auto get_string = [](const Vector& v){
        const std::string s = "(" + std::to_string(v.x()) + ", " + std::to_string(v.y()) + ")";
        return s;
    };
    const std::string& pos_string = get_string(pos);
    const std::string& vel_string = get_string(vel);

    std::cout << "Allocated object of type Rectangle at position: " << pos_string
              << " with velocity: " << vel_string
              << " and having width: " << r->getWidth() << " and height: " << r->getHeight()
              << std::endl;
}

int main(){

    const Vector pos1(0, 0), vel1(0, 0);
    const double h1 = 1.0, w1 = 0.5;

    const Vector pos2(1, -2), vel2(1, 2);
    const double h2 = 1.5, w2 = 2.5;


    auto r1 = std::make_unique<Rectangle>("R1",pos1, vel1, w1, h1);
    auto r2 = std::make_unique<Rectangle>("R2", pos2, vel2, w2, h2);


    printRectangleInfo(r1.get());
    printRectangleInfo(r2.get());

    
    return 0;
}