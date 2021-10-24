//
//  ParticleTypeActions.cpp
//  powderGame
//
//  Created by Benjamin Lewis-Jones on 17/04/2021.
//

#include "ParticleTypeActions.hpp"

using namespace std;

void UniversalParticle::swap(int type, int change, int &index, vector<Particle> &points)
{
    // swaps the types between two points
    points[index + change].status.type = type;
    points[index].status.type = 0;
}


void Sand::action(int &index, vector<Particle> &points, const int &numberOfPoints)
{
    // what to do in certain situations
    if(points[index + 75].status.type == -1 || (points[index + 75].status.type == 0 && (index + 75) < numberOfPoints))
    {
        swap(1, 75, index, points);
        
    }
    else if(points[index + 74].status.type == -1 || (points[index + 74].status.type == 0 && (index + 74) < numberOfPoints))
    {
        swap(1, 74, index, points);
    }
    else if(points[index + 76].status.type == -1 || (points[index + 76].status.type == 0 && (index + 76) < numberOfPoints))
    {
        swap(1, 76, index, points);
    }
}


void Wall::action(int &index, vector<Particle> &points)
{
    // any actions can be added here in the future
}
