#include "text.h"

#include <iostream>
#include <SDL_ttf.h>

text::text(renderer _renderer, std::string _font_path, SDL_Color _color, int _font_size, int _x, int _y, int _width, int _height, double _rotation)
{
	m_p_renderer = _renderer.GetRenderer();
	m_font_path = _font_path;
	set_font(_font_path);
	m_font_size = _font_size;
	m_color = _color;
	m_text = "";

	m_enabled = true;
	m_rect.w = _width; m_rect.h = _height;
	m_rect.x = _x; m_rect.y = _y;
	m_rotation = _rotation;
}
text::~text()
{
	SDL_DestroyTexture(m_p_font);
}

void text::set_text(std::string _text)
{
	m_text = _text;

	set_font(m_font_path);
}
void text::set_font(std::string _font_path)
{

	TTF_Font* font = TTF_OpenFont(_font_path.c_str(), m_font_size);
	if (!font)
	{
		std::cerr << "Failed to load font.\n";
	}

	SDL_Surface* surface = TTF_RenderText_Solid(font, m_text.c_str(), m_color);
	if (!surface)
	{
		std::cerr << "Failed to create text surface.\n";
	}

	// Clear the previous font
	if (m_p_font)
	{
		SDL_DestroyTexture(m_p_font);
	}

	m_p_font = SDL_CreateTextureFromSurface(m_p_renderer, surface);
	if (!m_p_font)
	{
		std::cerr << "Failed to create text texture.\n";
	}

	TTF_CloseFont(font);
	SDL_FreeSurface(surface);
}

void text::draw()
{
	if (!m_p_font)
	{
		std::cerr << "Font is null.\n";
	}
	else if (m_enabled)
	{
		SDL_Rect rect = { m_rect.x, m_rect.y, m_rect.w, m_rect.h };

		SDL_RenderCopy(m_p_renderer, m_p_font, nullptr, &rect);
	}
}