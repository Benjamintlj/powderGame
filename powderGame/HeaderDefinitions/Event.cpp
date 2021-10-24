//
//  Event.cpp
//  powderGame
//
//  Created by Benjamin Lewis-Jones on 16/04/2021.
//

#include "Event.hpp"

using namespace std;

void Event::getMousePosition()
{
    // gets mouse data
    x = e.motion.x;
    y = e.motion.y;
    mouseDown = false;
}



void Event::checkEvents()
{
    while (SDL_PollEvent(&e) != 0) {
        
        // if quit button is presses exit program loop
        switch (e.type) {
            // X is pressed
            case SDL_QUIT:
                running = false;
                break;
            // mouse moves
            case SDL_MOUSEMOTION:
                getMousePosition();
                break;
            // mouse button released
            case SDL_MOUSEBUTTONUP:
                mouseDown = false;
                break;
            // mouse button pressed
            case SDL_MOUSEBUTTONDOWN:
                mouseDown = true;
                break;
        }
    }
}


bool Event::getRunning() {return running;}

int Event::getMouseX() {return x;}

int Event::getMouseY() {return y;}

bool Event::getMouseDownState() {return mouseDown;}
