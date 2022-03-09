#include "Window.h"
#include "../audiolib.h"

#include <iostream>

Window::Window()
{
	m_title = "Default Window";
	m_position = { SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED };
	m_size = { 960, 720 };
	m_flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN;

	SDL_Init(SDL_INIT_VIDEO);

	m_window = SDL_CreateWindow(m_title, m_position.x, m_position.y, m_size.x, m_size.y, m_flags);
}

Window::Window(const char* title, int x, int y, int width, int height, Uint32 flags)
	: m_title{ title }, m_position{ x, y }, m_size{ width, height }, m_flags{ flags }
{
	SDL_Init(SDL_INIT_VIDEO);

	m_window = SDL_CreateWindow(m_title, m_position.x, m_position.y, m_size.x, m_size.y, m_flags);
}

Window::Window(const char* title, SDL_Point position, SDL_Point size, Uint32 flags)
	: m_title{ title }, m_position{ size }, m_size{ position }, m_flags{ flags }
{
	SDL_Init(SDL_INIT_VIDEO);

	m_window = SDL_CreateWindow(m_title, m_position.x, m_position.y, m_size.x, m_size.y, m_flags);
}

Window::~Window()
{
	if (m_window)
		SDL_DestroyWindow(m_window);
}

SDL_Window* Window::GetWindow()
{
	return m_window;
}

bool Window::Resize(int width, int heigh)
{
	if (width <= 0 || heigh <= 0)
		return false;

	SDL_SetWindowSize(m_window, width, heigh);
	return true;
}
