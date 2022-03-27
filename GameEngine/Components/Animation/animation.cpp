#include "animation.h"
#include "renderer.h"
#include <iostream>

std::map<FLIP, SDL_RendererFlip> FlipMap
{
	{FLIP::NONE, SDL_FLIP_NONE},
	{FLIP::HORIZONTAL, SDL_FLIP_HORIZONTAL},
	{FLIP::VERTICAL, SDL_FLIP_VERTICAL},
};

animation::animation()
{
}

animation::animation(renderer* _renderer, std::string _file_name, bool _use_transparency)
	: m_p_renderer{ _renderer->GetRenderer() }
{
	SDL_Surface* img_surface = IMG_Load((_file_name).c_str());

	if (!img_surface)
	{
		std::cerr << SDL_GetError();
		return;
	}

	m_src_width = img_surface->w;
	m_src_height = img_surface->h;

	if (_use_transparency && _file_name.find(".bmp") != std::string::npos)
	{	//Set Magenta as transparent colour for Animations
		Uint32 colour_key = SDL_MapRGB(img_surface->format, 255, 0, 255);
		SDL_SetColorKey(img_surface, SDL_TRUE, colour_key);
	}

	m_p_bmp_texture = SDL_CreateTextureFromSurface(_renderer->GetRenderer(), img_surface);

	SDL_FreeSurface(img_surface);
	img_surface = nullptr;
}

animation::~animation()
{
	if (nullptr != m_p_bmp_texture)
	{
		SDL_DestroyTexture(m_p_bmp_texture);
		m_p_bmp_texture = nullptr;
	}

	m_p_renderer = nullptr;
}

int animation::get_width() { return m_src_width; }

int animation::get_height() { return m_src_height; } //Change to frame dimensions

void animation::next_frame()
{
	if (SDL_GetTicks() - m_frame_start > m_frame_duration && m_animated)
	{
		if (m_loop) ++m_current_frame %= m_max_frames; //Run through spite frames and reset when at last
		else ++m_current_frame = std::min(m_current_frame, m_max_frames - 1);
		m_frame_start = SDL_GetTicks(); //Used when checking if it's time to move on
	}
}

void animation::set_frames(int _rows, int _columns, bool _loop) //Define a size to create a source rect from the spritesheet which is used in the draw function
{
	m_frame_rows = _rows;
	m_frame_columns = _columns;

	m_frame_width = m_src_width / _columns;
	m_FrameHeight = m_src_height / _rows;

	m_max_frames = m_frame_rows * m_frame_columns;
	m_frame_duration = 1000 / m_max_frames; //Default animation time to 1 second

	m_animated = true;
	m_loop = _loop;
}

void animation::set_frame_duration(int _ms) 
{ 
	m_frame_duration = _ms; 
}

void animation::draw(int _x, int _y, int _width, int _height, double _rotation, FLIP _flip)
{
	if (nullptr == m_p_bmp_texture) return;

	SDL_Rect dest_rect{ _x, _y, _width, _height };
	SDL_Rect src_rect{ 0, 0, m_src_width, m_src_height };

	if (m_animated)
	{
		next_frame();
		src_rect = { m_frame_width * (m_current_frame % m_frame_columns), m_FrameHeight * (m_current_frame / m_frame_columns), m_frame_width, m_FrameHeight };
		//Determine a frame from the spritesheet to use as the image to be drawn

	}
	SDL_RenderCopyEx(m_p_renderer, m_p_bmp_texture, &src_rect, &dest_rect, _rotation, NULL, FlipMap[_flip]);
}

