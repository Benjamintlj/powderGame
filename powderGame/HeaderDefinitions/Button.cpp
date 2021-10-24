//
//  Button.cpp
//  powderGame
//
//  Created by Benjamin Lewis-Jones on 17/04/2021.
//

#include "Button.hpp"

using namespace std;

Button::Button(int inputType, int x, int y, int w, int h, Uint32 red, Uint32 green, Uint32 blue)
{
    // setting rect struct attributes
    rectangle.h = h;
    rectangle.w = w;
    rectangle.x = x;
    rectangle.y = y;
    
    // setting colour struct attributes
    color.red = red;
    color.green = green;
    color.blue = blue;
    
    // type of particle the button possesses
    type = inputType;
}

void Button::render(Window &screen)
{
    // colour of the rect
    SDL_SetRenderDrawColor(screen.renderTarget, color.red, color.green, color.blue, color.alpha);
    // renders the rect
    SDL_RenderFillRect(screen.renderTarget, &rectangle);
}

void Button::Pressed(ParticleVector &particleObjects, Event &event)
{
    // gets the mouse coordinates
    int x = event.getMouseX();
    int y = event.getMouseY();
    
    // if mouse is within the Boundry
    if(x < rectangle.x || x > (rectangle.x + rectangle.w)) return;
    if(y < rectangle.y || y > (rectangle.y + rectangle.h)) return;
    // if the mouse button is pressed change the particles type
    if(event.getMouseDownState()) particleObjects.typeSelected = type;
}

void Button::saveFile(ParticleVector &particleObjects, Event &event)
{
    // gets the mouse coordinates
    int x = event.getMouseX();
    int y = event.getMouseY();
    
    // if mouse is within the Boundry
    if(x < rectangle.x || x > (rectangle.x + rectangle.w)) return;
    if(y < rectangle.y || y > (rectangle.y + rectangle.h)) return;
    // if the mouse button is pressed change save the particle vectors types
    if(event.getMouseDownState())
    {
        // open out file stream
        ofstream file("file.txt");

        // set all types on a new line
        for(int i{0}; i < particleObjects.numberOfPoints; i++)
        {
            // all -1 elements are stored as 0 since -1 cannot be read correctly
            particleObjects.points[i].status.type == -1 ? file << 0 << endl : file << particleObjects.points[i].status.type << endl;
        }
        
        // close file
        file.close();
    }
}


void Button::readFile(ParticleVector &particleObjects, Event &event)
{
    // gets the mouse coordinates
    int x = event.getMouseX();
    int y = event.getMouseY();
    
    // if mouse is within the Boundry
    if(x < rectangle.x || x > (rectangle.x + rectangle.w)) return;
    if(y < rectangle.y || y > (rectangle.y + rectangle.h)) return;
    // if the mouse button is pressed load all types to the particle vector
    if(event.getMouseDownState())
    {
        // open input file stream
        ifstream file("file.txt");
        
        // set all output to each particle vector type
        for(int i{0}; i < particleObjects.numberOfPoints; i++) file >> particleObjects.points[i].status.type;
        
        // close the file
        file.close();
    }
}
