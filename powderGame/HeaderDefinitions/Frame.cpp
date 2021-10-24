//
//  Frame.cpp
//  powderGame
//
//  Created by Benjamin Lewis-Jones on 14/04/2021.
//

#include "Frame.hpp"
#include <iostream>
#include <SDL2/SDL.h>

using namespace std;


/// constuctor
Window::Window(int height, int width)
{
    // diamentions
    HEIGHT = height;
    WIDTH = width;
    
    // pointers
    window = nullptr;
    currentFrame = nullptr;
    renderTarget = nullptr;
}


/// destructor
Window::~Window()
{
    // destroys the window Texture and Renderer
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(currentFrame);
    SDL_DestroyRenderer(renderTarget);
    window = nullptr;
    currentFrame = nullptr;
    renderTarget = nullptr;
    
    
    SDL_Quit();
}


/// loads the window
void Window::load()
{
    // only initializes sdl video
    SDL_Init(SDL_INIT_VIDEO);
    
    // creates the window
    window = SDL_CreateWindow("powderGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    // checks to see it has loaded, so program doesn't crash
    if (window == NULL) {
        cout << "SDL ERROR: window failed to be created" << endl;
        return;
    }
    
    // setting renderTarget
    renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Init(SDL_INIT_VIDEO);
    // checks to see if renderTarget was created so program doesn't crash
    if (renderTarget == NULL) {
        cout << "SDL ERROR: render target failed to be created" << endl;
        return;
    }
}


// renders a BMP file to the frame as a texture ready for the next frame - Default is set to GRAY
void Window::background(int R, int G, int B, int A)
{
    SDL_SetRenderDrawColor(renderTarget, R, G, B, A);
}


// renders the next frame
void Window::render()
{
    background();
    SDL_RenderCopy(renderTarget, currentFrame, NULL, NULL);
    SDL_RenderPresent(renderTarget);
    SDL_RenderClear(renderTarget);
}


