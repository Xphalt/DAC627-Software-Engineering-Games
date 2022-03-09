#pragma once
#include <SDL.h>
#include <iostream>
#include <conio.h>

class renderer
{
private:
    SDL_Renderer* m_renderer{ nullptr };

public:
    renderer(SDL_Window* m_Window);
    ~renderer();
    void Update();
    SDL_Renderer* GetRenderer();
};