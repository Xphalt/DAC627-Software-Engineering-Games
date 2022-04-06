#include "renderer.h"
#include "Graphics\Window.h"
#include "gameobject.h"

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

	m_p_window = m_Window;
}

renderer::~renderer()
{
	if (nullptr != m_renderer)
	{
		SDL_DestroyRenderer(m_renderer);
		m_renderer = nullptr;
	}
}

void renderer::Draw(gameobject* _gameobject)
{
	SDL_Rect rect = { _gameobject->get_position().x , _gameobject->get_position().y, _gameobject->get_scale().x, _gameobject->get_scale().y };

	SDL_RenderCopy(GetRenderer(), GetTexture(), nullptr, &rect);
}

void renderer::ClearRender()
{
	SDL_RenderClear(m_renderer);
}

void renderer::PresentRender()
{
	SDL_RenderPresent(m_renderer);
}

void renderer::CreateTexture(std::string _filename)
{
	SDL_Surface* surface = IMG_Load(_filename.c_str());
	if (!surface)
	{
		std::cerr << "Failed to create surface.\n";
	}

	// Clear the previous image
	if (m_texture)
	{
		SDL_DestroyTexture(m_texture);
	}

	m_texture = SDL_CreateTextureFromSurface(m_renderer, surface);
	if (!m_texture)
	{
		std::cerr << "Failed to create texture.\n";
	}

	SDL_FreeSurface(surface);
}