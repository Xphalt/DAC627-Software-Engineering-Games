#pragma once
#include <SDL.h>
#include <iostream>
#include <conio.h>

class Window;

class renderer
{
private:
    SDL_Renderer* m_renderer{ nullptr };
    Window* m_Window;

public:
    renderer(Window* m_Window);
    ~renderer();
    void Update();

    SDL_Renderer* GetRenderer();
    SDL_Window* GetWindow();
};