#include "minimap.h"

#include <SDL_image.h>
#include <iostream>

minimap::minimap(renderer* _renderer)
{
	m_p_renderer = _renderer->GetRenderer();

	m_enabled = true;
	m_rect.w = 50; m_rect.h = 50;
	m_rect.x = 0; m_rect.y = 0;
	m_rotation = 0;

	set_image("ui_assets/engine/HotbarBackground.png", "ui_assets/engine/DefaultImageNormal.png", "ui_assets/engine/ButtonNormal.png");
}
minimap::minimap(renderer* _renderer, std::string _minimapFrame_path, std::string _playerIcon_path, std::string _minimapImage_path,
	int _x, int _y, int _width, int _height, double _rotation)
{
	m_p_renderer = _renderer->GetRenderer();

	m_enabled = true;
	m_rect.w = _width; m_rect.h = _height;
	m_rect.x = _x; m_rect.y = _y;
	m_rotation = _rotation;

	set_image(_minimapFrame_path, _playerIcon_path, _minimapImage_path);
}
minimap::~minimap()
{
	SDL_DestroyTexture(m_p_minimapFrame);
	SDL_DestroyTexture(m_p_playerIcon);
	SDL_DestroyTexture(m_p_minimapImage);
}

void minimap::set_image(std::string _minimapFrame_path, std::string _playerIcon_path, std::string _minimapImage_path)
{
	SDL_Surface* frame_surface = IMG_Load(_minimapFrame_path.c_str());
	SDL_Surface* playerIcon_surface = IMG_Load(_playerIcon_path.c_str());
	SDL_Surface* minimapImage_surface = IMG_Load(_minimapImage_path.c_str());

	if (!frame_surface)
	{
		std::cerr << "Failed to create minimap frame surface.\n";
	}
	if (!playerIcon_surface)
	{
		std::cerr << "Failed to create player icon surface.\n";
	}
	if (!minimapImage_surface)
	{
		std::cerr << "Failed to create minimap image surface.\n";
	}

	//minimapImage_surface = crop_surface(minimapImage_surface, m_rect.x, m_rect.y, m_rect.w, m_rect.h);

	// Clear the previous image
	if (m_p_minimapFrame)
	{
		SDL_DestroyTexture(m_p_minimapFrame);
	}

	if (m_p_playerIcon)
	{
		SDL_DestroyTexture(m_p_playerIcon);
	}

	if (m_p_minimapImage)
	{
		SDL_DestroyTexture(m_p_minimapImage);
	}

	m_p_minimapFrame = SDL_CreateTextureFromSurface(m_p_renderer, frame_surface);
	m_p_playerIcon = SDL_CreateTextureFromSurface(m_p_renderer, playerIcon_surface);
	m_p_minimapImage = SDL_CreateTextureFromSurface(m_p_renderer, minimapImage_surface);

	//m_p_minimapImageCropped = getAreaTexture(m_rect, m_p_renderer, m_p_minimapImage);

	if (!m_p_minimapFrame)
	{
		std::cerr << "Failed to create minimap frame texture.\n";
	}
	if (!m_p_playerIcon)
	{
		std::cerr << "Failed to create player icon texture.\n";
	}
	if (!m_p_minimapImage)
	{
		std::cerr << "Failed to create minimap image texture.\n";
	}

	SDL_FreeSurface(frame_surface);
	SDL_FreeSurface(playerIcon_surface);
	SDL_FreeSurface(minimapImage_surface);
}

void minimap::draw()
{
	if (!m_p_minimapFrame)
	{
		std::cerr << "Minimap frame is null.\n";
	}
	if (!m_p_playerIcon)
	{
		std::cerr << "Player icon is null.\n";
	}
	if (!m_p_minimapImage)
	{
		std::cerr << "Minimap image is null.\n";
	}
	else if (m_enabled)
	{
		SDL_Rect minimapframe_rect = { m_rect.x, m_rect.y, m_rect.w, m_rect.h };

		//In order for the icon to be in the middle, we need to add half of the height and width to the position
		//and also substract half of the icon's size (because it's drawn from top right corner)
		//so the formula here is:
		//icon_position.x = (minimap_position + minimap_width / 2) - minimap_width / (icon_scale * 2)
		SDL_Rect playerIcon_rect = { (m_rect.x + m_rect.w / 2) - m_rect.w / 8,(m_rect.y + m_rect.h / 2) - m_rect.h / 8,
			m_rect.w / 4, m_rect.h / 4 };

		SDL_Rect minimapimage_rect = { 0, 0, m_rect.w, m_rect.h };

		SDL_RenderCopy(m_p_renderer, m_p_minimapImage, &minimapimage_rect, &minimapframe_rect);
		SDL_RenderCopy(m_p_renderer, m_p_playerIcon, nullptr, &playerIcon_rect);
		SDL_RenderCopy(m_p_renderer, m_p_minimapFrame, nullptr, &minimapframe_rect);
	}

}
