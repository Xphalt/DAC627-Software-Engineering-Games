#include "renderer.h"
#include "Graphics\Window.h"

renderer::renderer(Window* m_Window)
{
	m_renderer = SDL_CreateRenderer(
		m_Window->GetWindow(), -1, 0);

	if (nullptr == m_renderer)
	{
		std::cout << "Window initialisation failed: " << SDL_GetError() << std::endl;
		std::cout << "Press a key to continue" << std::endl;
		_getch();
	}
}

renderer::~renderer()
{
	if (nullptr != m_renderer)
	{
		SDL_DestroyRenderer(m_renderer);
		m_renderer = nullptr;
	}
}

void renderer::Update()
{
	if (nullptr == m_renderer) return;

	SDL_RenderPresent(m_renderer);
	SDL_RenderClear(m_renderer);

}

SDL_Renderer* renderer::GetRenderer()
{
	return m_renderer;
}
