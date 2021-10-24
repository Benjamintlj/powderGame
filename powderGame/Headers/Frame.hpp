//
//  Frame.hpp
//  powderGame
//
//  Created by Benjamin Lewis-Jones on 14/04/2021.
//

#ifndef Frame_hpp
#define Frame_hpp

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>


class Window
{
    
private:
    // window dimentions
    int HEIGHT;
    int WIDTH;
        
    
public:
    // pointers
    SDL_Window *window;
    SDL_Texture *currentFrame;
    SDL_Renderer *renderTarget;
    
    
    /// constructor
    Window(int height, int width);
    
    /// destructor - is called at the end of program
    ~Window();
    
    /// creates the window
    void load();
    
    /// renders window
    void render();
    
    /// adds texture to be rendered
    void background(int R = 46, int G = 46, int B = 46, int A = 255);
};

#endif /* Frame_hpp */
