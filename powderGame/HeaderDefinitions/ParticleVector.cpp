//
//  ParticleVector.cpp
//  powderGame
//
//  Created by Benjamin Lewis-Jones on 15/04/2021.
//

#include "ParticleVector.hpp"
using namespace std;


ParticleVector::ParticleVector(Window &screen)
{
    // vars needed for loop
    int thisRow{0};
    int x, y;
    
    // loops for the amount of points specified
    for (int i{0}; i < numberOfPoints; i++)
    {
        // if i is longer then the row, increase this row
        if(i/rowWidth > thisRow) thisRow++;
        
        // x coordinate
        x = ((i % rowWidth) * spacing) + 10;
        // y coordinate
        y = (thisRow * spacing) + 25;
        
        // init particle
        points.push_back(Particle(x, y, particleSize, particleSize));
    }
};


void ParticleVector::renderParticles(Window &screen)
{
    // loops through all the points in the vector
    for (int i{0}; i < numberOfPoints; i++) /* render points top to bottom */
    
    // dont want to remove since may help in the future
    //for (int i = numberOfPoints; i >= 0; i--) /* render points bottom to top*/
    {
        // actions based on type
        switch (points[i].status.type) {
                
            case 1:
                //cout << "sand" << endl;
                sandType.action(i, points, numberOfPoints);
                break;
            
            case 2:
                //cout << "wall" << endl;
                wallType.action(i, points);
                break;
        }
        
        // render
        if(points[i].status.type != -1) setParticleColor(i);
        points[i].render(screen);
    }
}


void ParticleVector::selectPoint(Event &event)
{
    // getting external data
    int height = (numberOfPoints/rowWidth);
    int x = (event.getMouseX()/spacing);
    int y = (event.getMouseY()/spacing);
    
    // if mouse is out of the boundarys
    if(!(x > 1 && x <= rowWidth + 1)) return;
    if(!(y >= 0 && y <= height + 5)) return;
    if(!event.getMouseDownState()) return;
    
    // essentially putting top left point at (0,0), mathematically speaking
    height += 5;
    x -= 10;
    y -= 25;
    
    // x and y to respective index calculation
    int index = x + ((y % height) * height) + 1583;
    
    // if the points index is in bounds change type
    if(index <= numberOfPoints && index >= 0) points[index].status.type = typeSelected;
}

void ParticleVector::setParticleColor(int index)
{    
    // void
    if(points[index].status.type == 0) points[index].changeColor(0, 0, 0, 255);
    
    // sand
    else if(points[index].status.type == 1) points[index].changeColor(252, 240, 131, 255);
    
    // wall
    else if(points[index].status.type == 2) points[index].changeColor(128, 101, 56, 255);
}
