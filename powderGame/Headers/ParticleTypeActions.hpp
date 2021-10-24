//
//  ParticleTypeActions.hpp
//  powderGame
//
//  Created by Benjamin Lewis-Jones on 17/04/2021.
//

#ifndef ParticleTypeActions_hpp
#define ParticleTypeActions_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Particle.hpp"


// base class
class UniversalParticle
{
public:
    /// swaps a particle position relative to the current particles index
    void swap(int type, int change, int &index, vector<Particle> &points);
};


class Sand: public UniversalParticle
{
public:
    /// defines how sand will interact with the world
    void action(int &index, vector<Particle> &points, const int &numberOfPoints);
};


class Wall: public UniversalParticle
{
public:
    /// defines how sand will interact with the world
    void action(int &index, vector<Particle> &points);
};

#endif /* ParticleTypeActions_hpp */
