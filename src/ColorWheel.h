//
// Created by Asier Pereiro Castro on 31/8/23.
//

#pragma once

#include "Types.h"
#include <iostream>


class ColorWheel {
public:
    static unsigned int idx;

    ColorWheel()
    {
        idx = static_cast<unsigned int>(Colors::Red);
    }

    static Color Get()
    {
        return MakeColor(static_cast<Colors>(idx++));
    }
    static Color MakeColor(const Colors &color)
    {
        switch (color)
        {
            case Colors::Red:
                return Color(255, 45, 85, 1);
            case Colors::Green:
                return Color(59, 239, 86, 1);
            case Colors::Blue:
                return Color(0, 142, 255, 1);
            case Colors::Violet:
                return Color(98, 108, 240, 1);
            case Colors::Orange:
                return Color(255, 149, 0, 1);
            case Colors::Cyan:
                return Color(90, 200, 250, 1);
            case Colors::Salmon:
                return Color(255, 99, 136, 1);
            case Colors::Purple:
                return Color(191, 133, 245, 1);
            case Colors::Yellow:
                return Color(255, 195, 77, 1);
            case Colors::White:
                return Color(255, 255, 255, 1);
            case Colors::Black:
                return Color(0, 0, 0, 0);
            default:
                std::cout << "ERROR: color not implemented" << std::endl;
                std::exit(1);
        }
    }
};

// Initialise first color
unsigned int ColorWheel::idx = static_cast<unsigned int>(Colors::Red);
