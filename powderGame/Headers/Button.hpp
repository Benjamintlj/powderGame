//
//  Button.hpp
//  powderGame
//
//  Created by Benjamin Lewis-Jones on 17/04/2021.
//

#ifndef button_hpp
#define button_hpp

#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <fstream>

#include "Frame.hpp"
#include "ParticleVector.hpp"
#include "Event.hpp"

// buttons that perform an action when called
class Button
{
private:
    // Attributes
    SDL_Rect rectangle;
    
    struct particleColor
    {
        Uint32 red {255};
        Uint32 green {255};
        Uint32 blue {255};
        Uint32 alpha {255};
    } color;
    
    int type;
    
public:
    /// constructor
    Button(int type, int x, int y, int w, int h, Uint32 red, Uint32 green, Uint32 blue);
    
    /// renders the button to the window
    void render(Window &screen);
    
    /// if pressed change particle selection type
    void Pressed(ParticleVector &particleObjects, Event &event);
    
    /// if pressed save the particle vector state to the file.txt
    void saveFile(ParticleVector &particleObjects, Event &event);
    
    /// if pressed load the file.txt to particle vector
    void readFile(ParticleVector &particleObjects, Event &event);
};

#endif /* button_hpp */
