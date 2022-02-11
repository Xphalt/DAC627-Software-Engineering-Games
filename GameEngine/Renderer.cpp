#include "Renderer.h"

Renderer::Renderer(SDL_Window* m_Window)
{
    m_Renderer = SDL_CreateRenderer(
		m_Window, -1, 0);

	if (nullptr == m_Renderer)
	{
		std::cout << "Window initialisation failed: " << SDL_GetError() << std::endl;
		std::cout << "Press a key to continue" << std::endl;
		_getch();
	}
}

Renderer::~Renderer()
{
    if (nullptr != m_Renderer)
	{
		SDL_DestroyRenderer(m_Renderer);
		m_Renderer = nullptr;
	}
}

void Renderer::Update()
{
    if (nullptr == m_Renderer) return;
	
	SDL_RenderClear(m_Renderer);
    SDL_RenderPresent(m_Renderer);

}