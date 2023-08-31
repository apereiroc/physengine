//
// Created by Asier Pereiro Castro on 31/8/23.
//

#pragma once

#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


class RenderingEngine {
private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
public:
    RenderingEngine() {
        // Initialize SDL
        if (SDL_Init(SDL_INIT_VIDEO) < 0){
            SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
            exit(1);
        }

        // Create a window
        window = SDL_CreateWindow("2D Rendering Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == nullptr){
            SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            exit(1);
        }

        // Create a renderer
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == nullptr){
            SDL_Log("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
            exit(1);
        }
    }

    ~RenderingEngine(){
        // Cleanup and quit
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    [[nodiscard]] inline SDL_Renderer * getRenderer() const { return renderer; }

};
