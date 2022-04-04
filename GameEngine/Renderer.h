#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <conio.h>

class Window;
class gameobject;

class renderer
{
public:
    renderer(Window* m_Window);
    ~renderer();

    void Draw(gameobject* _gameobject);
    void ClearRender();
    void PresentRender();
    void CreateTexture(std::string _filename);

    SDL_Renderer* GetRenderer() { return m_renderer; };
    SDL_Texture* GetTexture() { return m_texture; };

private:
    Window* m_Window;
    SDL_Renderer* m_renderer{ nullptr };
    SDL_Texture* m_texture{ nullptr };
    SDL_Rect m_rect{ NULL };
};