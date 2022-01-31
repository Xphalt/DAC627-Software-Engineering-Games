#include "slider.h"

slider::slider(	SDL_Renderer* _renderer,
				const std::string &_background_image_path,
				const std::string &_fill_image_path,
				const std::string &_handle_image_path,
				float _min_value,
				float _max_value,
				float _x,
				float _y,
				float _width,
				float _height,
				double _rotation)
{
	m_p_renderer = _renderer;

	set_images(_background_image_path, _fill_image_path, _handle_image_path);
	m_min_value = _min_value;
	m_max_value = _max_value;
	m_value = _max_value;

	m_enabled = true;
	m_rect.w = _width; m_rect.h = _height;
	m_rect.x = _x; m_rect.y = _y;
	m_rotation = _rotation;
}
slider::~slider()
{
	// Clear the images
}

void slider::set_value(float _value)
{
	// Set m_value
	// Clamp m_value between m_min_value and m_max_value
	// Update fill size and handle position
}
void slider::set_images(std::string _background_image_path, std::string _fill_image_path, std::string _handle_image_path)
{
	// Create and store images
}

void slider::draw()
{
	// Are any of the images null?
	// If not then render if the UI component is enabled
	// Else print error
}