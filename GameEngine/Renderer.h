#include <SDL.h>
#include <iostream>
#include <conio.h>
#include "text.h"
#include "slider.h"
#include "image.h"
#include "hotbar.h"
#include "button.h"
#include "animation.h"


struct SDL_Renderer;

class Renderer
{
    private:
    SDL_Renderer* m_Renderer{ nullptr };

    public:
    Renderer(SDL_Window* m_Window);
    ~Renderer();
    void Update();
    SDL_Renderer* GetRenderer();
    void Render(text _text);
    void Render(slider _slider);
    void Render(image _image);
    void Render(hotbar _hotbar);
    void Render(button _button);
};