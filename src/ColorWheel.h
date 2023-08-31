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
        return MakeColor(static_cast<Colors>(idx++ % NUMCOLORS));
    }
    static Color MakeColor(const Colors &color)
    {
        switch (color)
        {
            case Colors::Red:
                return {255, 45, 85, 1};
            case Colors::Green:
                return {59, 239, 86, 1};
            case Colors::Blue:
                return {0, 142, 255, 1};
            case Colors::Violet:
                return {98, 108, 240, 1};
            case Colors::Orange:
                return {255, 149, 0, 1};
            case Colors::Cyan:
                return {90, 200, 250, 1};
            case Colors::Salmon:
                return {255, 99, 136, 1};
            case Colors::Purple:
                return {191, 133, 245, 1};
            case Colors::Yellow:
                return {255, 195, 77, 1};
            case Colors::White:
                return {255, 255, 255, 1};
            case Colors::Black:
                return {0, 0, 0, 0};
            default:
                std::cout << "ERROR: color not implemented" << std::endl;
                std::exit(1);
        }
    }
};

// Initialise first color
unsigned int ColorWheel::idx = static_cast<unsigned int>(Colors::Red);
