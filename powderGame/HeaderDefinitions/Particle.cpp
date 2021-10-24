//
//  Particle.cpp
//  powderGame
//
//  Created by Benjamin Lewis-Jones on 14/04/2021.
//

#include "Particle.hpp"

//using namespace std;


/// constuctor
Particle::Particle(int x, int y, int w, int h)
{
    rectangle.x = x;
    rectangle.y = y;

    rectangle.w = w;
    rectangle.h = h;
    
    
    changeColor(0, 0, 0, 255);
}


/// render
void Particle::render(Window &screen)
{
    SDL_SetRenderDrawColor(screen.renderTarget, color.red, color.green, color.blue, color.alpha);
    SDL_RenderFillRect(screen.renderTarget, &rectangle);
}


void Particle::changeColor(Uint32 red, Uint32 green, Uint32 blue, Uint32 alpha)
{
    color = {red, green, blue, alpha};
}
