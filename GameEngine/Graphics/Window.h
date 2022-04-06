#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Window
{
public:
	Window();
	Window(const char* title, int x, int y, int width, int height, Uint32 flags, const char* iconPath = "");
	Window(const char* title, SDL_Point position, SDL_Point size, Uint32 flags, const char* iconPath = "");
	~Window();

	const SDL_Window* GetWindow() const;
	bool Resize(int width, int heigh);

	void SetIcon(const char* iconPath);
private:
	SDL_Window* m_window;

	const char* m_title;
	SDL_Point m_position;
	SDL_Point m_size;
	Uint32 m_flags;
};

