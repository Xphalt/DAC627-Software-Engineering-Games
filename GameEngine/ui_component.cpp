#include "ui_component.h"

ui_component::ui_component(SDL_Renderer* _renderer, float _x, float _y, float _width, float _height, double _rotation)
{
	m_p_renderer = _renderer;

	m_enabled = true;
	m_rect.w = _width; m_rect.h = _height;
	m_rect.x = _x; m_rect.y = _y;
	m_rotation = _rotation;
}
ui_component::~ui_component()
{
	// Ensure stored data is released/destroyed
}

void ui_component::draw()
{
	// Should usually follow the following format:
	//		Is relevant data null?
	//		If not then render if the UI component is enabled
	//		Else print error
}