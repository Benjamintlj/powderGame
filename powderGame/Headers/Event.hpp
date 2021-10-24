//
//  Event.hpp
//  powderGame
//
//  Created by Benjamin Lewis-Jones on 16/04/2021.
//

#ifndef Event_hpp
#define Event_hpp

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>

class Event
{
private:
    // program loop vars
    bool running = true;
    SDL_Event e;
    
    // relative mouse position vars
    int x{0}, y{0};
    
    /// if mouse is down, value is true
    bool mouseDown;
    
    /// sets x and y to the relative mouse position
    void getMousePosition();
    
public:
    
    /// checks all events
    void checkEvents();
    
    /// returns the var running
    bool getRunning();
    
    /// returns the mouse position
    int getMouseX();
    int getMouseY();
    
    /// returns the mouse button state down is true
    bool getMouseDownState();
    
};





#endif /* Event_hpp */
