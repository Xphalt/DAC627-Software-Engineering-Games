#include "text.h"

text::text(SDL_Renderer* _renderer, std::string _font_texture_path, SDL_Color _color, int _font_size, float _x, float _y, float _width, float _height, double _rotation)
{
	m_p_renderer = _renderer;

	set_font(_font_texture_path);
	m_font_size = _font_size;
	m_color = _color;

	m_enabled = true;
	m_size.w = _width; m_size.h = _height;
	m_pos.x = _x; m_pos.y = _y;
	m_rotation = _rotation;
}
text::~text()
{
	// Clear the font texture
}

void text::set_font(std::string _font_texture_path)
{
	// Load the font texture
}

void text::draw()
{
	// Is the font null?
	// If not then render it if the UI component is enabled
	// Else print error
}