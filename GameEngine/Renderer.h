#include <SDL.h>
#include <iostream>
#include <conio.h>

struct SDL_Renderer;

class Renderer
{
    private:
    SDL_Renderer* m_Renderer{ nullptr };

    public:
    Renderer(SDL_Window* m_Window);
    ~Renderer();
    void Update();
};