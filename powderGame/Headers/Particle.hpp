//
//  Particle.hpp
//  powderGame
//
//  Created by Benjamin Lewis-Jones on 14/04/2021.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <iostream>

#include "Frame.hpp"

using namespace std;


class Particle
{
private:
    // attributes
    SDL_Rect rectangle;
    
    // stores colour of the particle
    struct particleColor
    {
        Uint32 red;
        Uint32 green;
        Uint32 blue;
        Uint32 alpha;
    } color;
    
    
public:
    struct objectStatus
    {
        /*
         struct was made incase of furture updates more vars may be included
         Examples:
            1. heat
            2. speed
            3. weight
         */
         
        int type{-1};
    } status;
    
    /// constructor
    Particle(int x, int y, int w, int h);
    
    /// renders the particle to the render target
    void render(Window &screen);
    
    /// changes the particle color
    void changeColor(Uint32 red, Uint32 green, Uint32 blue, Uint32 alpha);
    
};

#endif /* Particle_hpp */
