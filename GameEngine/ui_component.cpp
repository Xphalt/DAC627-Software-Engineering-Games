#include "ui_component.h"

ui_component::ui_component(int _x, int _y, int _width, int _height, double _rotation)
{
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