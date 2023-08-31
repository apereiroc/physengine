//
// Created by Asier Pereiro Castro on 31/8/23.
//

#pragma once

#include <Eigen/Dense>
#include <memory>
#include <map>
#include "PhysicsObject.h"

typedef Eigen::Vector2d Vector;

class PhysicsObject;
typedef std::map<std::string, std::unique_ptr<PhysicsObject>> ObjMap;

typedef struct Color
{
    unsigned char r, g, b, a;
    Color(): r(0), g(0), b(0), a(255) {};
    Color(unsigned char r, unsigned char g,
          unsigned char b, unsigned char a) :
          r(r), g(g), b(b), a(a) {}
} Color;

enum Colors
{
    Red,
    Green,
    Blue,
    Violet,
    Orange,
    Cyan,
    Salmon,
    Purple,
    Yellow,
    White,
    Black,

    NUMCOLORS,
};
