//
//  ParticleVector.hpp
//  powderGame
//
//  Created by Benjamin Lewis-Jones on 15/04/2021.
//

#ifndef ParticleVector_hpp
#define ParticleVector_hpp

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

#include "Frame.hpp"
#include "Particle.hpp"
#include "Event.hpp"
#include "ParticleTypeActions.hpp"


using namespace std;



class ParticleVector
{
private:
    // Attributes for particle grid, *note can be changed but if diffrence is too great, the program will act not as expected*
    const int rowWidth{75};
    const int particleSize{5};
    const int particleGap{1};
    const int spacing = particleGap + particleSize;
    
    /*
     void = -1 or 0 (type 0 into typeSelected if testing NOT -1)
     Sand = 1
     Wall = 2
     */
    
    Sand sandType;
    Wall wallType;
    
    
public:
    // attributes
    vector<Particle> points;
    int typeSelected{2};
    // defines the number of points in the particle grid
    const int numberOfPoints{5250};
    
    /// constructor
    ParticleVector(Window &screen);
    
    /// renders all the particles to the screen
    void renderParticles(Window &screen);
    
    /// selects a point based on mouse position
    void selectPoint(Event &event);
    
    /// sets the colour of a particle
    void setParticleColor(int index);    
};


#endif /* ParticleVector_hpp */
