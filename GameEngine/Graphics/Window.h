#pragma once

#include <SDL.h>
#include <string>

class Window
{
public:
	Window();
	Window(const char* title, int x, int y, int width, int height, Uint32 flags);
	Window(const char* title, SDL_Point position, SDL_Point size, Uint32 flags);
	~Window();

	const SDL_Window* GetWindow() const;
	bool Resize(int width, int heigh);
private:
	SDL_Window* m_window;

	const char* m_title;
	SDL_Point m_position;
	SDL_Point m_size;
	Uint32 m_flags;
};

