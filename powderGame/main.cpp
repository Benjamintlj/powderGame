//
//  main.cpp
//  powderGame
//
//  Created by Benjamin Lewis-Jones on 08/04/2021.
//

// Using SDL and Input Output Stream

// libs
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

// headers
#include "Frame.hpp"
#include "ParticleVector.hpp"
#include "Particle.hpp"
#include "Event.hpp"
#include "Button.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    // buttons
    Button voidType(0, 500, 200, 100, 50, 0, 0, 0);
    Button sand(1, 500, 50, 100, 50, 252, 240, 131);
    Button wall(2, 500, 125, 100, 50, 128, 101, 56);
    Button save(0, 500, 395, 40, 50, 235, 64, 52);
    Button load(0, 560, 395, 40, 50, 45, 99, 224);
    
    // init the events class
    Event event;
    
    // window creation
    Window screen(480, 640);
    screen.load();
    
    // init the paricle vector
    ParticleVector particleObjects(screen);
    
    
    // main program loop
    while (event.getRunning()) {
        
        // poll all events
        event.checkEvents();
        
        // renders all particles and processes next move
        particleObjects.renderParticles(screen);
        particleObjects.selectPoint(event);
        
        // All buttons
        // selects the sand particle type
        sand.render(screen);
        sand.Pressed(particleObjects, event);
        // selects the wall particle type
        wall.render(screen);
        wall.Pressed(particleObjects, event);
        // selects the void particle type
        voidType.render(screen);
        voidType.Pressed(particleObjects, event);
        
        // saves and loads the arangement of the particles
        save.render(screen);
        load.render(screen);
        save.saveFile(particleObjects, event);
        load.readFile(particleObjects, event);
        
        // renders the screen
        screen.render();
    }
    
    return 0;
}

