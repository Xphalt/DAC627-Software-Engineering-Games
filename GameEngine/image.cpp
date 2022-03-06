#include "image.h"

#include <SDL_image.h>
#include <iostream>

image::image(Renderer _renderer, std::string _image_path, int _x, int _y, int _width, int _height, double _rotation)
{
	m_p_renderer = _renderer.GetRenderer();

	set_image(_image_path);

	m_enabled = true;
	m_rect.w = _width; m_rect.h = _height;
	m_rect.x = _x; m_rect.y = _y;
	m_rotation = _rotation;
}
image::~image()
{
	SDL_DestroyTexture(m_p_image);
}

void image::set_image(std::string _image_path)
{
	SDL_Surface* surface = IMG_Load(_image_path.c_str());
	if (!surface)
	{
		std::cerr << "Failed to create surface.\n";
	}

	// Clear the previous image
	if (m_p_image)
	{
		SDL_DestroyTexture(m_p_image);
	}

	m_p_image = SDL_CreateTextureFromSurface(m_p_renderer, surface);
	if (!m_p_image)
	{
		std::cerr << "Failed to create texture.\n";
	}

	SDL_FreeSurface(surface);
}

void image::draw()
{
	if (!m_p_image)
	{
		std::cerr << "Image is null.\n";
	}
	else if (m_enabled)
	{
		SDL_Rect rect = { m_rect.x, m_rect.y, m_rect.w, m_rect.h };

		SDL_RenderCopy(m_p_renderer, m_p_image, nullptr, &rect);
	}
}