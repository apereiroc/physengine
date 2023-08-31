//
// Created by Asier Pereiro Castro on 31/8/23.
//

#pragma once

#include <Eigen/Dense>

typedef Eigen::Vector2d Vector;

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
