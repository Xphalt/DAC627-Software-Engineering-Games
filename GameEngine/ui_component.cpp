#include "ui_component.h"

ui_component::ui_component(SDL_Renderer* _renderer, float _x, float _y, float _width, float _height, double _rotation)
{
	m_p_renderer = _renderer;

	m_enabled = true;
	m_size.w = _width; m_size.h = _height;
	m_pos.x = _x; m_pos.y = _y;
	m_rotation = _rotation;
}
ui_component::~ui_component()
{
}

void ui_component::draw()
{
}