//
// Created by Asier Pereiro Castro on 31/8/23.
//

#include <memory>
#include <SDL2/SDL.h>
#include "RenderingEngine.h"


int main(){

    auto rendEngine {std::make_unique<RenderingEngine>()};

    SDL_Renderer*  renderer {rendEngine->getRenderer()};

    // Basic loop with black window
    while(true){
        SDL_Event e;
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT)
            break;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
    }

    return 0;
}